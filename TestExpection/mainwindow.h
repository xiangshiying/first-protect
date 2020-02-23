#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "typetransfer.h"
#include "exceptionhandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startWork();

    void startTestException();

private:
    TypeTransfer typeTrans;
    ExceptionHandler exceptionHandler;
};

#endif // MAINWINDOW_H
