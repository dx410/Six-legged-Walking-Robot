QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DTH11
TEMPLATE = app


SOURCES += main.cpp\
        dth11.cpp

HEADERS  += dth11.h

FORMS    += dth11.ui

LIBS     += -lwiringPi
