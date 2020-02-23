#ifndef BRIDGEMODE_HPP
#define BRIDGEMODE_HPP

#include <iostream>
using namespace std;

namespace bridgemode {

class Engine
{
public:
  virtual void printVersion() = 0;
};

class Engine4430 : public Engine
{
public:
    void printVersion()
    {
        cout << "this is Engin4430." << endl;
    }
};

class Car
{
public:
    Car(Engine *engine)
    {
        m_engine = engine;
    }

  virtual void showName() = 0;
protected:
    Engine *m_engine;
};

class BM7 : public Car
{
public:
    BM7(Engine* engine):Car(engine){}
    void showName()
    {
        cout << "this is BM7" << endl;
        m_engine->printVersion();
    }

};

}




#endif // BRIDGEMODE_HPP

