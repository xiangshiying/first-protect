#-------------------------------------------------
#
# Project created by QtCreator 2020-01-25T18:05:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestSort
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    commonsort.cpp

HEADERS  += mainwindow.h \
    commonsort.h
