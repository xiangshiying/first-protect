#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tempFunc = new TempFunc<int>(20);
    tempFunc->printValue();

    TempFunc<int> b(30);
    tempFunc->myAdd(b);

//    TempFunc<int> b(10);
//    b.printValue();
}

MainWindow::~MainWindow()
{
    delete tempFunc;
}

void MainWindow::startWork()
{
    tempFunc->testTempFunc();
}
