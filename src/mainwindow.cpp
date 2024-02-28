#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      Plot(new Plot_window(nullptr))
{
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_Br_open, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_Br_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(this, &MainWindow::Window_Closed_signal, &Plot, &::Plot_window::MainWindow_closed);
  connect(&Plot, &::Plot_window::expression_text, this, &MainWindow::expression_send);
}

MainWindow::~MainWindow() { delete ui; }

in_string str_res;

void MainWindow::digits_numbers() {
  QPushButton *digit_button = (QPushButton *)sender();
  QString line_digit = digit_button->text();
  QByteArray button_digit = line_digit.toLocal8Bit();
  char *str_digit = button_digit.data();
  int error = 0;
  if (!strcmp(str_digit, "sin")) {
    error = input_translator('s', &str_res);
  } else if (!strcmp(str_digit, "cos")) {
    error = input_translator('c', &str_res);
  } else if (!strcmp(str_digit, "tan")) {
    error = input_translator('t', &str_res);
  } else if (!strcmp(str_digit, "mod")) {
    error = input_translator('m', &str_res);
  } else if (!strcmp(str_digit, "log")) {
    error = input_translator('g', &str_res);
  } else if (!strcmp(str_digit, "asin")) {
    error = input_translator('a', &str_res);
  } else if (!strcmp(str_digit, "acos")) {
    error = input_translator('o', &str_res);
  } else if (!strcmp(str_digit, "atan")) {
    error = input_translator('n', &str_res);
  } else if (!strcmp(str_digit, "v")) {  //  вмсесто знака корня печатается "v"
    error = input_translator('q', &str_res);
  } else if (!strcmp(str_digit, "ln")) {
    error = input_translator('l', &str_res);
  } else {
    error = input_translator(*str_digit, &str_res);
  }
  if (!error) {
    ui->lineInput->setText(str_res.res_str);
  } else {
    ui->lineOutput->setText("Error: Input string is too large");
  }
}

int MainWindow::calculate_mainwindow(char *str_bit, double *result) {
  char polish[MAX_INPUT_SYM];
  int error = 0;
  QString line_in = ui->lineInput->text();
  QByteArray button_in = line_in.toLocal8Bit();
  char *input_copy = button_in.data();
  error = brackets_check(input_copy);
  if (!error) error = insert_x(str_bit, input_copy);
  if (error == 3) {
    ui->lineOutput->setText("Error: Incorrect \"x\" - must be a number");
  } else if (error == 4) {
    ui->lineOutput->setText("Please, set \"x\"");
  } else if (error == 5) {
    ui->lineOutput->setText("Error: Incorrect brackets number");
  }
  if (!error) error = polish_translator(input_copy, polish);
  if (error == 1) {
    ui->lineOutput->setText("Error: Input string is too large");
  } else if (error == 6) {
    ui->lineOutput->setText("Error: Incorrect expression");
  } else if (!error) {
    error = calculate(polish, result, Grad);
    if (error == 2) {
      ui->lineOutput->setText("Error: Division by zero");
    } else if (error == 1) {
      ui->lineOutput->setText("Error: Input string is too large");
    }
  }
  return error;
}

void MainWindow::on_pushButton_eq_clicked() {
  int error = 0;
  QString line_ok = ui->lineEdit_X->text();
  QByteArray button_ok = line_ok.toLocal8Bit();
  char *str_bit = button_ok.data();
  double result;
  error = calculate_mainwindow(str_bit, &result);
  if (!error) {
    char res_str[MAX_INPUT_SYM];
    double temp = (int)result - result;
    sprintf(res_str, "%lf", fabs(temp));
    if (strlen(res_str) > 8) {
      snprintf(res_str, MAX_INPUT_SYM, "%.9e", result);
    } else {
      sprintf(res_str, "%.8lf", result);
      unsigned i = strlen(res_str) - 1;
      while ((res_str[i] == '0' ||
            res_str[i] == ',') && i > 0) {
        res_str[i] = '\0';
        i--;
      }
    }
    ui->lineOutput->setText(res_str);
  }
}

void MainWindow::on_pushButton_Clear_clicked() {
  input_string_init(&str_res);
  ui->lineInput->setText(str_res.res_str);
}

void MainWindow::on_pushButton_Del_clicked() {
  if (str_res.char_counter > 0) {
    delete_button(&str_res);
    ui->lineInput->setText(str_res.res_str);
  }
}

void MainWindow::on_pushButton_All_Clear_clicked() {
  on_pushButton_Clear_clicked();
  ui->lineOutput->setText(str_res.res_str);
  ui->lineEdit_X->setText(str_res.res_str);
}

void MainWindow::on_pushButton_open_plot_clicked() {
  Plot.show();
}

void MainWindow::expression_send() {
  QString expression = ui->lineInput->text();
  Plot.expression_reciever(expression);
}

void MainWindow::on_radioButton_Rad_clicked()
{
    ui->radioButton_Rad->setChecked(1);
    ui->radioButton_Grad->setChecked(0);
    Grad = 0;
    Plot.Grad_Setter(Grad);
}


void MainWindow::on_radioButton_Grad_clicked()
{
    ui->radioButton_Rad->setChecked(0);
    ui->radioButton_Grad->setChecked(1);
    Grad = 1;
    Plot.Grad_Setter(Grad);
}

