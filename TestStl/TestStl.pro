#-------------------------------------------------
#
# Project created by QtCreator 2020-01-29T05:19:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestStl
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

CONFIG += consele
CONFIG -= app_bundle


SOURCES += main.cpp\
        mainwindow.cpp \
    stltester.cpp

HEADERS  += mainwindow.h \
    stltester.h
