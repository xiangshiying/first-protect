#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

void MainWindow::startWork()
{

    //test static_cast
    typeTrans.transStatic();

    //test reinterpreter_cast
    typeTrans.transReinterpreter();

    //test dynamic
    typeTrans.transDynamic();

    //test const
    typeTrans.transConst();

}

void MainWindow::startTestException()
{
    //test int
    exceptionHandler.testIntExceptional();

    //test char*
    exceptionHandler.testCharExceptional();

    //test class
    exceptionHandler.testClassExceptional();

    //test inherent-class
    exceptionHandler.testInherentClassExceptional();


}
