#ifndef TEMPLATEMODE_HPP
#define TEMPLATEMODE_HPP

#include <iostream>
using namespace std;

namespace templatemode {

class Car
{

public:
    virtual void makeDoor() = 0;
    virtual void makeWindow() = 0;
    virtual void makeTyer() = 0;

    void makeCar()
    {
        makeDoor();
        makeWindow();
        makeTyer();
    }

};

class BMCar : public Car
{
public:
    void makeDoor()
    {
        cout << "this is BMCar" << endl;
    }

    void makeWindow()
    {
        cout << "this is BMwindows" << endl;
    }

    void makeTyer()
    {
        cout << "this is BMTyer" << endl;
    }

};

}

#endif // TEMPLATEMODE_HPP

