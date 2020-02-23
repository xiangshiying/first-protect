#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tempfunc.cpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startWork();

private:
    TempFunc<int> *tempFunc;
};

#endif // MAINWINDOW_H
