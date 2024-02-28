#include "plot_window.h"
#include "ui_plot_window.h"

Plot_window::Plot_window(QWidget *parent)
    : QDialog(parent), ui(new Ui::Plot_window) {
  ui->setupUi(this);
  if (ui->radioButton_Fixed->isChecked()) {
    ui->lineEdit_step->setEnabled(1);
  } else if (ui->radioButton_Adaptive->isChecked()) {
    ui->lineEdit_step->setDisabled(1);
  }
}

int Plot_window::plot_setup(char *input_copy, double x_Begin, double x_End,
                            double y_min, double y_max, double h) {
  int error = 0;
  double result = 0;
  char buffer[MAX_INPUT_SYM];
  int i = 0;
  ui->widget_plot->clearGraphs();
  ui->widget_plot->xAxis->setLabel("x");
  ui->widget_plot->yAxis->setLabel("f(x)");
  while (input_copy[i] != '\0') {  //  Копируем input_copy в buffer
    buffer[i] = input_copy[i];
    i++;
  }
  buffer[i] = '\0';
  ui->widget_plot->xAxis->setRange(x_Begin, x_End);
  ui->widget_plot->yAxis->setRange(y_min, y_max);
  for (X = xBegin; X <= xEnd; X += h) {
    error = calculate_plot_window(X, buffer, &result);
    int i = 0;
    while (input_copy[i] != '\0') {  //  Копируем input_copy в buffer
      buffer[i] = input_copy[i];
      i++;
    }
    buffer[i] = '\0';
    x.push_back(X);
    y.push_back(result);
  }
  ui->widget_plot->addGraph();
  ui->widget_plot->graph(0)->addData(x, y);
  ui->widget_plot->replot();

  ui->widget_plot->setInteraction(QCP::iRangeZoom, true);
  ui->widget_plot->setInteraction(QCP::iRangeDrag, true);
  x.clear();
  y.clear();
  return error;
}

int Plot_window::calculate_plot_window(double X, char *input_copy,
                                       double *result) {
  char polish[MAX_INPUT_SYM];
  int error = 0;
  char str_bit[MAX_INPUT_SYM];
  sprintf(str_bit, "%lf", X);
  error = brackets_check(input_copy);
  if (!error) error = insert_x(str_bit, input_copy);
  if (error == 3) {
    ui->label_errors->setText("Error: Incorrect \"x\" - must be a number");
  } else if (error == 4) {
    ui->label_errors->setText("Please, set \"x\"");
  } else if (error == 5) {
    ui->label_errors->setText("Error: Incorrect brackets number");
  }
  if (!error) error = polish_translator(input_copy, polish);
  if (error == 1) {
    ui->label_errors->setText("Error: Input string is too large");
  } else if (error == 6) {
    ui->label_errors->setText("Error: Incorrect expression");
  } else if (!error) {
      error = calculate(polish, result, Grad);
    if (error == 2) {
      ui->label_errors->setText("Error: Division by zero");
    } else if (error == 1) {
      ui->label_errors->setText("Error: Input string is too large");
    }
  }
  return error;
}

void Plot_window::Function_to_draw(QString text) {
  ui->label_func->setText(text);
  QByteArray text_in = text.toLocal8Bit();
  char *input_copy = text_in.data();
  xBegin = -1000;
  xEnd = 1000;
  y_min = -10;
  y_max = 10;
  h = 1;
  plot_setup(input_copy, xBegin, xEnd, y_min, y_max, h);
}

Plot_window::~Plot_window() { delete ui; }

int Qstring_to_double(QString text, double *result) {
  int error = 0;
  QByteArray text_Arr = text.toLocal8Bit();
  char *text_res = text_Arr.data();
  for (int i = 0; text_res[i] != '\0'; i++) {
    if (text_res[i] == '.') {
      text_res[i] = ',';
    }
    if (is_number(text_res[i]) != 1 && text_res[i] != '+' &&
        text_res[i] != '-') {
      error = 7;
    }
  }
  *result = atof(text_res);
  return error;
}

void Plot_window::on_pushButton_Draw_clicked() {
  int error = 0;
  emit expression_text();
  QString text = ui->label_func->text();
  QByteArray text_in = text.toLocal8Bit();
  char *input_copy = text_in.data();
  error = Qstring_to_double(ui->lineEdit_xMin->text(), &xBegin);
  if (!error) error = Qstring_to_double(ui->lineEdit_xMax->text(), &xEnd);
  if (!error) error = Qstring_to_double(ui->lineEdit_yMin->text(), &y_min);
  if (!error) error = Qstring_to_double(ui->lineEdit_yMax->text(), &y_max);
  if (ui->radioButton_Fixed->isChecked()) {
    ui->lineEdit_step->setEnabled(1);
    if (!error) error = Qstring_to_double(ui->lineEdit_step->text(), &h);
  } else if (ui->radioButton_Adaptive->isChecked()) {
    ui->lineEdit_step->setEnabled(0);
    h = (abs(xBegin) + abs(xEnd)) / 1000;
  }
  if (error) ui->label_errors->setText("Error: Incorrect number format");
  if (!error) plot_setup(input_copy, xBegin, xEnd, y_min, y_max, h);
}

void Plot_window::on_radioButton_Adaptive_clicked() { ui->lineEdit_step->setEnabled(0); }

void Plot_window::on_radioButton_Fixed_clicked() { ui->lineEdit_step->setEnabled(1); }

//  Закрывает окно, если поступает сигнал о том, что закрывается главное окно
void Plot_window::MainWindow_closed() { close(); }

void Plot_window::expression_reciever(QString expr) { ui->label_func->setText(expr); }

void Plot_window::Grad_Setter(unsigned Value) { Grad = Value; }
