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
    //cin
//    iotester.testCin();

    //cout
    iotester.testCout();

    //file
    iotester.testFileIo();

}
