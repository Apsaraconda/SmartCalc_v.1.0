#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdio>
#include <math.h>
#include <QMainWindow>
#include <QString>
#include <QMouseEvent>

#include "plot_window.h"

extern "C" {
#include "calculator.h"
}



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  int Qstring_to_double(QString text, double *result);
  ~MainWindow();

private slots:
  void digits_numbers();
  void on_pushButton_eq_clicked();
  void on_pushButton_Clear_clicked();
  void on_pushButton_Del_clicked();
  void on_pushButton_All_Clear_clicked();
  void on_pushButton_open_plot_clicked();
  int calculate_mainwindow(char *str_bit, double *result);
  void expression_send();

  void on_radioButton_Rad_clicked();

  void on_radioButton_Grad_clicked();

private:
  Ui::MainWindow *ui;
  Plot_window Plot;
  unsigned Grad = 1;

signals:
  void Window_Closed_signal(QCloseEvent *event);
    unsigned Grad_Set_signal(unsigned Value);
};
#endif  // MAINWINDOW_H
