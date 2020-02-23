#ifndef IOTESTER_H
#define IOTESTER_H

#include <iostream>
using namespace std;

#include <fstream>
#include <istream>
#include <ostream>

class IoTester
{
public:
    IoTester();

    //cin test
    void testCin();

    //cout test
    void testCout();

    //fio test
    void testFileIo();
};

#endif // IOTESTER_H
