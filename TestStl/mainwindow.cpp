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

    //test string
//    stlTester.testString();

    //test vec
    //stlTester.testVector();

    //test list
//    stlTester.testList();

    //test deque
//    stlTester.testDeque();

    //test set
   // stlTester.testSet();

    //test queue
//    stlTester.testQueue();

    //test map
//    stlTester.testMap();

    //test speakerCompetetion
    stlTester.testSpeakerCompetition();

}
