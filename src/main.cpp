#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  setlocale(LC_NUMERIC, "Russian");
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
