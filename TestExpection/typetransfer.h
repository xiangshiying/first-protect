#ifndef TYPETRANSFER_H
#define TYPETRANSFER_H

#include <iostream>
using namespace std;


class TypeTransfer
{
public:
    TypeTransfer();


    // static cast
    void transStatic();

    // reinterpreter cast
    void transReinterpreter();

    // dynamic cast
    void transDynamic();

    // const cast
    void transConst();

};

#endif // TYPETRANSFER_H
