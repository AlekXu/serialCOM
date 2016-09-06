#-------------------------------------------------
#
# Project created by QtCreator 2016-08-06T15:19:00
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

CONFIG       += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialCOM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RC_FILE += serial.rc

RESOURCES += \
    serialcom.qrc
