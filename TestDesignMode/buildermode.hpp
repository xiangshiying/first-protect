#ifndef BUILDERMODE
#define BUILDERMODE

#include <iostream>
using namespace std;
#include <string>

namespace buildermode {

class House
{
public:
    void setDoor(string door)
    {
        m_door = door;
    }
    void setWindow(string window)
    {
        m_window = window;
    }
    void setWall(string wall)
    {
        m_wall = wall;
    }

    void printHouse()
    {
        cout << "door:" << m_door << "\t window:" << m_window << "\t wall" << m_wall << endl;
    }

private:
    string m_door;
    string m_window;
    string m_wall;

};

class HouseMaker
{
public:
    HouseMaker() {}
    virtual void makeDoor() = 0;
    virtual void makeWall() = 0;
    virtual void makeWindow() = 0;
    virtual House* getHouse() = 0;
};


class FlatHouse : public HouseMaker
{
public:
    FlatHouse()
    {
       m_house = new House;
    }
    void makeDoor()
    {
        m_house->setDoor("faltDoor");
    }
    void makeWindow()
    {
        m_house->setWindow("faltWindow");
    }
    void makeWall()
    {
        m_house->setWall("flatWall");
    }

    House* getHouse()
    {
        return m_house;
    }

private:
    House* m_house;
};

class Structer
{
public:
    Structer(HouseMaker * houseMaker):m_houseMaker(houseMaker) {}

    void buildHouse()
    {
        m_houseMaker->makeDoor();
        m_houseMaker->makeWall();
        m_houseMaker->makeWindow();
    }

private:
    HouseMaker *m_houseMaker;
};


}

#endif // BUILDERMODE

