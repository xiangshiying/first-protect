#include "tempfunc.h"

#include <iostream>
using namespace std;

template <typename T1, typename T2>
void MySwap(T1 a, T2 b)
{
    cout << "a " << a << "b " << b << endl;
    cout << "template func" << endl;
}

//void MySwap(int a, char b)
//{
//    cout << "a " << a << "b " << b << endl;
//    cout << "normal func" << endl;
//}

template <typename T>
TempFunc<T>::TempFunc(T a )
{
    this->a = a;
}


template <typename T>
void TempFunc<T>::testTempFunc()
{
        int a = 10;
        char c = 'a';

        MySwap(a, c);

        MySwap<>(a, c);

}

template <typename T>
void TempFunc<T>::printValue()
{
    cout << "Value " << a << endl;
}

template <typename T>
void TempFunc<T>::myAdd(const TempFunc<T> &obj)
{
 cout << "myAdd" << a+obj.a << endl;
}
