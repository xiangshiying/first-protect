#include <iostream>

#include "mutlistate.hpp"

using namespace std;

static void testMutliState()
{
    mutlispace::testMain();
}

static void test1()
{
    int a[] = {1,2};
    for(auto i: a)
        cout << i << a;
}

int main()
{
    testMutliState();
    cout << "Hello World!" << endl;
    return 0;
}

