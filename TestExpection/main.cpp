#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.startWork();
    w.startTestException();
//    w.show();

    return a.exec();
}
