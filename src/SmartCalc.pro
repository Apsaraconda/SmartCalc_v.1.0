QT       += core gui
QT    += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brackets_check.c \
    calculate.c \
    delete_button.c \
    input_translator.c \
    insert_x.c \
    main.cpp \
    mainwindow.cpp \
    plot_window.cpp \
    polish_translator.c \
    qcustomplot.cpp

HEADERS += \
    calculator.h \
    mainwindow.h \
    plot_window.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui \
    plot_window.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
