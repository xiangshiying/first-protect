#ifndef MUTLISTATE_HPP
#define MUTLISTATE_HPP


#include <iostream>
using namespace std;

namespace mutlispace {

class A
{
public:
    virtual void printT()
    {
        cout << "A:printT" << endl;
    }

    void printT2()
    {
        cout << "A::printT2" << endl;
    }
};

class B : public A
{
public:
    void printT()
    {
        cout << "B:printT" << endl;
    }

    void printT3()
    {
        cout << "B:printT3" << endl;
    }

};


void testValue(A a)
{
    a.printT();
    a.printT2();
}

void testQuote(A &a)
{
    a.printT();
    a.printT2();
}

void testPointer(A *a)
{
    a->printT();
    a->printT2();
}

void testMain()
{
    B b;
    testValue(b);
    testQuote(b);
    testPointer(&b);
}

}

#endif // MUTLISTATE_HPP

