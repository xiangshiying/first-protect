#-------------------------------------------------
#
# Project created by QtCreator 2020-01-28T00:41:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestExpection
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11



SOURCES += main.cpp\
        mainwindow.cpp \
    typetransfer.cpp \
    exceptionhandler.cpp

HEADERS  += mainwindow.h \
    typetransfer.h \
    exceptionhandler.h
