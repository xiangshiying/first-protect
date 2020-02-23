#include "commonsort.h"
#include <iostream>
#include <stdlib.h>

#define SWAP_ELEMENT(a,b) ({a = a^b; b = a^b; a = a^b;})

using namespace std;

CommonSort::CommonSort()
{

}

//choose
void CommonSort::selectSort(int a[], int n)
{
    int b[10] = {1,2,5,4,3,4,6,7,9,10};
    cout << "Before select Sort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    int i,j;

    for ( i = 0; i < n; i++) {
       for(j = i+1; j < n; j++)
       {
          if(a[i] > a[j])
            SWAP_ELEMENT(a[i], a[j]);
       }

    }



    cout << "after select Sort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

}


//insert
void CommonSort::insertSort(int *a, int n)
{
    int b[10] = {1,2,5,4,3,4,6,7,9,10};
    cout << "Before insertSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    int i,j,k;
    int temp;
    for ( i = 1; i < n; i++) {
       temp = a[i];
       k = i;
       for(j = i-1; j > 0 && a[j] > temp; j--)
       {
           a[j+1] = a[j];
           k = j;
       }

       a[k] = temp;
    }



    cout << "after insertSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

}


//bubble
void CommonSort::bubbleSort(int *a, int n)
{
//    cout << "Before bubbleSort." << endl;
//    for (auto i : a) {
//        cout << i ;
//    }



//    cout << "after bubbleSort." << endl;
//    for (auto i : a) {
//        cout << i ;
//    }
}


void CommonSort::shellSort(int *a, int n)
{
    int b[10] = {1,2,5,4,3,4,6,7,9,10};
    cout << "Before shellSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    int i, j, k, gap = n, temp;
    do {
        gap = gap/3+1;

        for(i = gap; i < n; i += gap){
            k = i;
            temp = a[i];

            for(j = i - gap; j > 0 && a[j] > temp; j -= gap ){
                a[j+gap] = a[j];
                k = j;
            }

            a[k] = temp;

        }

    }while(gap > 1);


    cout << "after shellSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
}

static int quickAlgorithm(int *a, int low, int high)
{
    int temp = a[low];
    while(low < high){
        while(low < high && a[high] >= temp)
            high--;
        if(a[high] < temp)
        SWAP_ELEMENT(a[high], a[low]);
        while(low < high && a[low] <= temp)
            low++;
        if(a[low] > temp)
        SWAP_ELEMENT(a[low], temp);
    }
    //a[low] = temp;

    return low;
}

void CommonSort::quickSort(int *a, int low, int high)
{
   if(low < high){
       int mid = quickAlgorithm(a, low, high);
       quickSort(a, low, mid-1);
       quickSort(a, mid+1, high);
   }
}

static void mergeArray(int *src, int *des, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){

        if(src[i] < src[j])
            des[k++] = src[i++];
        else
            des[k++] = src[j++];

    }

    while(i <= mid)
        des[k++] = src[i++];

    while(j <= high)
        des[k++] = src[j++];
}

static void mergeAlgorithm(int *src, int *des, int low, int high, int max)
{
    if(low == high) {
        des[low] = src[low];
    } else {

    int mid = (low + high)/2;
    int *space = (int *)malloc(sizeof(int)*max);
    if(space != NULL){
        mergeAlgorithm(src, space, low, mid, max);
        mergeAlgorithm(src, space, mid+1, high, max);
        mergeArray(space, des, low, mid, high);
    }

    free(space);
    }
}

void CommonSort::mergeSort(int *a, int n)
{
    cout << "Before mergeSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    mergeAlgorithm(a, a, 0, n-1, n);

    cout << "after mergeSort." << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
}

