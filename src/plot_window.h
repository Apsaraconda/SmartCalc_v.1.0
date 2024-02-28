#ifndef PLOT_WINDOW_H
#define PLOT_WINDOW_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <iostream>

extern "C" {
#include "calculator.h"
}

namespace Ui {
class Plot_window;
}

class Plot_window : public QDialog {
  Q_OBJECT

public:
  Ui::Plot_window *ui;
  explicit Plot_window(QWidget *parent = nullptr);
  void Function_to_draw(QString text);
  void expression_reciever(QString expr);
  ~Plot_window();
  void Grad_Setter(unsigned Value);

signals:
  void expression_text();

private slots:
  void on_pushButton_Draw_clicked();
  int calculate_plot_window(double X, char *input_copy, double *result);
  int plot_setup(char *input_copy, double x_Begin, double x_End, double y_min,
                 double y_max, double h);
  void on_radioButton_Adaptive_clicked();
  void on_radioButton_Fixed_clicked();
public slots:
  void MainWindow_closed();


private:
//  Ui::Plot_window *ui;
  double xBegin, xEnd, y_min, y_max, h, X;
  QVector<double> x, y;
  unsigned Grad;
};

#endif  // PLOT_WINDOW_H
