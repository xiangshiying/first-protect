#-------------------------------------------------
#
# Project created by QtCreator 2020-01-28T15:59:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestIo
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -std=c++11




SOURCES += main.cpp\
        mainwindow.cpp \
    iotester.cpp

HEADERS  += mainwindow.h \
    iotester.h
