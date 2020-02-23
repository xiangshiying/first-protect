#ifndef FACTORYMODE_H
#define FACTORYMODE_H

#include <iostream>
using namespace std;

namespace factorymode {


class FMfruit
{
public:
    virtual void sayName() = 0;
};

class Banana : public FMfruit
{
public:
    void sayName()
    {
        cout << "this is banana" << endl;
    }
};

class FMvegetables
{
public:
    virtual void sayVegetableName() = 0;
};

class Potato : public FMvegetables
{
public:
    void sayVegetableName()
    {
        cout << "this is potato." << endl;
    }
};

class FactoryMode
{
public:
    FactoryMode(){}

    FMfruit* getFruit()
    {
        return new Banana;
    }

    FMvegetables* getVegetables()
    {
        return new Potato;
    }
};


}

#endif // FACTORYMODE_H
