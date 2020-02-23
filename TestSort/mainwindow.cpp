#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    commSort = new CommonSort();
}

MainWindow::~MainWindow()
{
    delete commSort;
}

void MainWindow::startWork()
{

    int a[10] = {1,87,55,3,7,6,10,9,10,11};

    //test select
//    commSort->selectSort(a, 10);

    //test insert
//    commSort->insertSort(a, 10);

    //test bubble
//    commSort->bubbleSort(a, 10);

    //test shell
   // commSort->shellSort(a, 10);

    //test quick
//    commSort->quickSort(a, 0, 9);
//    for(auto i: a){
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;

    //test merge
    commSort->mergeSort(a,10);

}
