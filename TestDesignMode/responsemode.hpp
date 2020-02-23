#ifndef RESPONSEMODE_HPP
#define RESPONSEMODE_HPP

#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <algorithm>

namespace responsemode {

class Car
{
public:
    virtual void makeCar() = 0;

    void setNextStep(Car *car)
    {
        m_car = car;
    }

    Car* getNextStep()
    {
        return m_car;
    }

protected:
    Car *m_car;
};

class HeadCar : public Car
{
public:
    void makeCar()
    {
        makeHead();

        Car* car = getNextStep();
        if(car != NULL)
            car->makeCar();
    }

    void makeHead()
    {
        cout << "make car head" << endl;
    }

};

class BodyCar : public Car
{
public:
    void makeCar()
    {
        makeBody();

        Car* car = getNextStep();
        if(car != NULL)
            car->makeCar();
    }

    void makeBody()
    {
        cout << "make car body" << endl;
    }

};

class TailCar : public Car
{
public:
    void makeCar()
    {
        makeTail();

        Car* car = getNextStep();
        if(car != NULL)
            car->makeCar();
    }

    void makeTail()
    {
        cout << "make car tail" << endl;
    }

};


}

#endif // RESPONSEMODE_HPP

