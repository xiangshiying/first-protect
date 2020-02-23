#ifndef COMMONSORT_H
#define COMMONSORT_H


class CommonSort
{
public:
    CommonSort();

    //choose
    void selectSort(int *a, int n);

    //insert
    void insertSort(int *a, int n);

    //bubble
    void bubbleSort(int *a, int n);

    //shell
    void shellSort(int *a, int n);

    //quick
    void quickSort(int *a, int low, int high);

    //shell
    void mergeSort(int *a, int n);

};

#endif // COMMONSORT_H
