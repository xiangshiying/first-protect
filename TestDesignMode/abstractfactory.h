#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>
using namespace std;

#include <string>


class AbFruit
{
public:
    virtual void fruitName() = 0;
};

class Banana : public AbFruit
{
public:
    void fruitName()
    {
        cout << "this is Banana." << endl;
    }
};

class Apple : public AbFruit
{
public:
    Apple(){}
    void fruitName()
    {
        cout << "this is Apple." << endl;
    }
};



class AbstractFactory
{
public:
    virtual AbFruit* getFruit() = 0;
};

class BananaFactory : public AbstractFactory
{
public:
    AbFruit* getFruit()
    {
        return new Banana;
    }
};

class AppleFactory : public AbstractFactory
{
public:
    AbFruit* getFruit()
    {
        return new Apple;
    }
};


#endif // ABSTRACTFACTORY_H
