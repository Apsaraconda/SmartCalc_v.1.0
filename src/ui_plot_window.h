/********************************************************************************
** Form generated from reading UI file 'plot_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_WINDOW_H
#define UI_PLOT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Plot_window
{
public:
    QCustomPlot *widget_plot;
    QLineEdit *lineEdit_xMin;
    QLineEdit *lineEdit_yMin;
    QLineEdit *lineEdit_xMax;
    QLineEdit *lineEdit_yMax;
    QPushButton *pushButton_Draw;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_errors;
    QLabel *label_func;
    QLineEdit *lineEdit_step;
    QLabel *label_5;
    QRadioButton *radioButton_Adaptive;
    QRadioButton *radioButton_Fixed;

    void setupUi(QDialog *Plot_window)
    {
        if (Plot_window->objectName().isEmpty())
            Plot_window->setObjectName("Plot_window");
        Plot_window->resize(567, 623);
        widget_plot = new QCustomPlot(Plot_window);
        widget_plot->setObjectName("widget_plot");
        widget_plot->setGeometry(QRect(9, 29, 518, 461));
        lineEdit_xMin = new QLineEdit(Plot_window);
        lineEdit_xMin->setObjectName("lineEdit_xMin");
        lineEdit_xMin->setGeometry(QRect(55, 510, 81, 28));
        QFont font;
        font.setPointSize(12);
        lineEdit_xMin->setFont(font);
        lineEdit_xMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_yMin = new QLineEdit(Plot_window);
        lineEdit_yMin->setObjectName("lineEdit_yMin");
        lineEdit_yMin->setGeometry(QRect(55, 550, 81, 28));
        lineEdit_yMin->setFont(font);
        lineEdit_yMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_xMax = new QLineEdit(Plot_window);
        lineEdit_xMax->setObjectName("lineEdit_xMax");
        lineEdit_xMax->setEnabled(true);
        lineEdit_xMax->setGeometry(QRect(213, 510, 81, 28));
        lineEdit_xMax->setFont(font);
        lineEdit_xMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_yMax = new QLineEdit(Plot_window);
        lineEdit_yMax->setObjectName("lineEdit_yMax");
        lineEdit_yMax->setGeometry(QRect(213, 550, 81, 28));
        lineEdit_yMax->setFont(font);
        lineEdit_yMax->setLayoutDirection(Qt::LeftToRight);
        lineEdit_yMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_Draw = new QPushButton(Plot_window);
        pushButton_Draw->setObjectName("pushButton_Draw");
        pushButton_Draw->setGeometry(QRect(450, 510, 100, 68));
        QFont font1;
        font1.setPointSize(14);
        pushButton_Draw->setFont(font1);
        label = new QLabel(Plot_window);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 515, 47, 16));
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);
        label_2 = new QLabel(Plot_window);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 515, 47, 16));
        label_2->setFont(font2);
        label_3 = new QLabel(Plot_window);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 555, 47, 16));
        label_3->setFont(font2);
        label_4 = new QLabel(Plot_window);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 555, 49, 16));
        label_4->setFont(font2);
        label_errors = new QLabel(Plot_window);
        label_errors->setObjectName("label_errors");
        label_errors->setGeometry(QRect(10, 590, 371, 16));
        label_func = new QLabel(Plot_window);
        label_func->setObjectName("label_func");
        label_func->setGeometry(QRect(30, 10, 481, 20));
        label_func->setAlignment(Qt::AlignCenter);
        lineEdit_step = new QLineEdit(Plot_window);
        lineEdit_step->setObjectName("lineEdit_step");
        lineEdit_step->setEnabled(false);
        lineEdit_step->setGeometry(QRect(370, 575, 61, 28));
        lineEdit_step->setFont(font);
        lineEdit_step->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(Plot_window);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 580, 41, 20));
        label_5->setFont(font2);
        radioButton_Adaptive = new QRadioButton(Plot_window);
        radioButton_Adaptive->setObjectName("radioButton_Adaptive");
        radioButton_Adaptive->setGeometry(QRect(330, 510, 111, 21));
        radioButton_Adaptive->setFont(font2);
        radioButton_Adaptive->setChecked(true);
        radioButton_Adaptive->setAutoRepeat(false);
        radioButton_Fixed = new QRadioButton(Plot_window);
        radioButton_Fixed->setObjectName("radioButton_Fixed");
        radioButton_Fixed->setGeometry(QRect(330, 540, 111, 21));
        radioButton_Fixed->setFont(font2);
        radioButton_Fixed->setChecked(false);
        radioButton_Fixed->setAutoRepeat(true);

        retranslateUi(Plot_window);

        QMetaObject::connectSlotsByName(Plot_window);
    } // setupUi

    void retranslateUi(QDialog *Plot_window)
    {
        Plot_window->setWindowTitle(QCoreApplication::translate("Plot_window", "Plot", nullptr));
        lineEdit_xMin->setText(QCoreApplication::translate("Plot_window", "-1000", nullptr));
        lineEdit_yMin->setText(QCoreApplication::translate("Plot_window", "-10", nullptr));
        lineEdit_xMax->setText(QCoreApplication::translate("Plot_window", "1000", nullptr));
        lineEdit_yMax->setText(QCoreApplication::translate("Plot_window", "10", nullptr));
        pushButton_Draw->setText(QCoreApplication::translate("Plot_window", "Draw", nullptr));
        label->setText(QCoreApplication::translate("Plot_window", "X min = ", nullptr));
        label_2->setText(QCoreApplication::translate("Plot_window", "X max =", nullptr));
        label_3->setText(QCoreApplication::translate("Plot_window", "Y min = ", nullptr));
        label_4->setText(QCoreApplication::translate("Plot_window", "Y max = ", nullptr));
        label_errors->setText(QString());
        label_func->setText(QString());
        lineEdit_step->setText(QCoreApplication::translate("Plot_window", "1", nullptr));
        label_5->setText(QCoreApplication::translate("Plot_window", "step =", nullptr));
        radioButton_Adaptive->setText(QCoreApplication::translate("Plot_window", "Adaptive step", nullptr));
        radioButton_Fixed->setText(QCoreApplication::translate("Plot_window", "Fixed step", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plot_window: public Ui_Plot_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_WINDOW_H
