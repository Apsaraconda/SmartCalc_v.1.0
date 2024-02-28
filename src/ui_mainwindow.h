/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QLineEdit *lineInput;
    QLineEdit *lineOutput;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Del;
    QPushButton *pushButton_div;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_Br_open;
    QPushButton *pushButton_Br_close;
    QPushButton *pushButton_x;
    QPushButton *pushButton_All_Clear;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_log;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_acos;
    QLineEdit *lineEdit_X;
    QLabel *label_x;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_open_plot;
    QRadioButton *radioButton_Rad;
    QRadioButton *radioButton_Grad;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(380, 500);
        MainWindow->setMinimumSize(QSize(380, 500));
        MainWindow->setMaximumSize(QSize(380, 540));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(170, 390, 41, 41));
        QFont font;
        font.setPointSize(12);
        pushButton_1->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 390, 41, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 390, 41, 41));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(170, 340, 41, 41));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(220, 340, 41, 41));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(270, 340, 41, 41));
        pushButton_6->setFont(font);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(170, 290, 41, 41));
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(220, 290, 41, 41));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(270, 290, 41, 41));
        pushButton_9->setFont(font);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(170, 440, 91, 41));
        pushButton_0->setFont(font);
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(270, 440, 41, 41));
        pushButton_dot->setFont(font);
        pushButton_eq = new QPushButton(centralwidget);
        pushButton_eq->setObjectName("pushButton_eq");
        pushButton_eq->setGeometry(QRect(320, 390, 41, 91));
        pushButton_eq->setFont(font);
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(320, 340, 41, 41));
        pushButton_plus->setFont(font);
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(320, 290, 41, 41));
        pushButton_minus->setFont(font);
        lineInput = new QLineEdit(centralwidget);
        lineInput->setObjectName("lineInput");
        lineInput->setGeometry(QRect(20, 17, 341, 41));
        QFont font1;
        font1.setPointSize(16);
        lineInput->setFont(font1);
        lineInput->setLayoutDirection(Qt::LeftToRight);
        lineInput->setMaxLength(1000);
        lineInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineInput->setReadOnly(true);
        lineInput->setClearButtonEnabled(false);
        lineOutput = new QLineEdit(centralwidget);
        lineOutput->setObjectName("lineOutput");
        lineOutput->setGeometry(QRect(20, 77, 341, 41));
        lineOutput->setFont(font1);
        lineOutput->setMaxLength(1000);
        lineOutput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineOutput->setReadOnly(true);
        pushButton_Clear = new QPushButton(centralwidget);
        pushButton_Clear->setObjectName("pushButton_Clear");
        pushButton_Clear->setGeometry(QRect(220, 240, 41, 41));
        pushButton_Clear->setFont(font);
        pushButton_Del = new QPushButton(centralwidget);
        pushButton_Del->setObjectName("pushButton_Del");
        pushButton_Del->setGeometry(QRect(270, 240, 41, 41));
        pushButton_Del->setFont(font);
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(120, 340, 41, 41));
        pushButton_div->setFont(font);
        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName("pushButton_mul");
        pushButton_mul->setGeometry(QRect(120, 290, 41, 41));
        pushButton_mul->setFont(font);
        pushButton_Br_open = new QPushButton(centralwidget);
        pushButton_Br_open->setObjectName("pushButton_Br_open");
        pushButton_Br_open->setGeometry(QRect(70, 240, 41, 41));
        pushButton_Br_open->setFont(font);
        pushButton_Br_close = new QPushButton(centralwidget);
        pushButton_Br_close->setObjectName("pushButton_Br_close");
        pushButton_Br_close->setGeometry(QRect(120, 240, 41, 41));
        pushButton_Br_close->setFont(font);
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(320, 240, 41, 41));
        pushButton_x->setFont(font);
        pushButton_All_Clear = new QPushButton(centralwidget);
        pushButton_All_Clear->setObjectName("pushButton_All_Clear");
        pushButton_All_Clear->setGeometry(QRect(170, 240, 41, 41));
        pushButton_All_Clear->setFont(font);
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(70, 340, 41, 41));
        pushButton_sin->setFont(font);
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(120, 390, 41, 41));
        pushButton_ln->setFont(font);
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(20, 340, 41, 41));
        pushButton_cos->setFont(font);
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(20, 240, 41, 41));
        pushButton_sqrt->setFont(font);
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(20, 390, 41, 41));
        pushButton_tan->setFont(font);
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(120, 440, 41, 41));
        pushButton_log->setFont(font);
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(70, 390, 41, 41));
        pushButton_asin->setFont(font);
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(70, 440, 41, 41));
        pushButton_atan->setFont(font);
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(20, 440, 41, 41));
        pushButton_acos->setFont(font);
        lineEdit_X = new QLineEdit(centralwidget);
        lineEdit_X->setObjectName("lineEdit_X");
        lineEdit_X->setGeometry(QRect(48, 137, 311, 41));
        lineEdit_X->setFont(font1);
        lineEdit_X->setMaxLength(1000);
        lineEdit_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_x = new QLabel(centralwidget);
        label_x->setObjectName("label_x");
        label_x->setGeometry(QRect(20, 150, 22, 16));
        label_x->setFont(font);
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(20, 290, 41, 41));
        pushButton_mod->setFont(font);
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName("pushButton_pow");
        pushButton_pow->setGeometry(QRect(70, 290, 41, 41));
        pushButton_pow->setFont(font);
        pushButton_open_plot = new QPushButton(centralwidget);
        pushButton_open_plot->setObjectName("pushButton_open_plot");
        pushButton_open_plot->setGeometry(QRect(270, 190, 91, 41));
        pushButton_open_plot->setFont(font);
        radioButton_Rad = new QRadioButton(centralwidget);
        radioButton_Rad->setObjectName("radioButton_Rad");
        radioButton_Rad->setGeometry(QRect(20, 200, 91, 22));
        QFont font2;
        font2.setPointSize(10);
        radioButton_Rad->setFont(font2);
        radioButton_Rad->setChecked(false);
        radioButton_Grad = new QRadioButton(centralwidget);
        radioButton_Grad->setObjectName("radioButton_Grad");
        radioButton_Grad->setGeometry(QRect(80, 200, 61, 22));
        radioButton_Grad->setFont(font2);
        radioButton_Grad->setChecked(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_Del->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_Br_open->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_Br_close->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_All_Clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        label_x->setText(QCoreApplication::translate("MainWindow", "X = ", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_open_plot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        radioButton_Rad->setText(QCoreApplication::translate("MainWindow", "Rad", nullptr));
        radioButton_Grad->setText(QCoreApplication::translate("MainWindow", "Grad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
