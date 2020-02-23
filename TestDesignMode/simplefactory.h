#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <iostream>
using namespace std;

#include <string>

namespace simplefactory {



class AbFruit
{
public:
    virtual void fruitName() = 0;
};

class Banana : public AbFruit
{
public:
    Banana(){}
    void fruitName();
};

class Apple : public AbFruit
{
public:
    Apple(){}
    void fruitName();
};


class SimpleFactory
{
public:
    SimpleFactory();

    AbFruit* getFruit(string);
};

}

#endif // SIMPLEFACTORY_H
