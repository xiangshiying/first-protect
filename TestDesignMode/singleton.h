#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
using namespace std;

class SingleTon
{
private:
    SingleTon();

public:
   static SingleTon *getInstance();
   static void deleteSingleTon();
   void printT();

private:
    static SingleTon *m_singleTon;
    static int m_count;
};

#endif // SINGLETON_H
