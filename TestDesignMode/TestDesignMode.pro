QT += core
QT -= gui

TARGET = TestDesignMode
CONFIG += console
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = app

SOURCES += main.cpp \
    singleton.cpp \
    mainwindow.cpp \
    simplefactory.cpp \
    abstractfactory.cpp

HEADERS += \
    singleton.h \
    mainwindow.h \
    simplefactory.h \
    abstractfactory.h \
    factorymode.h \
    prototypemode.hpp \
    buildermode.hpp \
    proxymode.hpp \
    bridgemode.hpp \
    composemode.hpp \
    templatemode.hpp \
    commandmode.hpp \
    responsemode.hpp \
    mediatormode.hpp \
    observermode.hpp \
    memorymode.hpp \
    visitormode.hpp

