#ifndef OBSERVERMODE_HPP
#define OBSERVERMODE_HPP
#include <iostream>
using namespace std;

#include <string>
#include <list>

#include <algorithm>

namespace observermode {

class Employee;
class Observer
{
public:
    virtual void setEmployee(Employee *employee) = 0;
    virtual void sendNotify() = 0;
};

class Employee
{
public:
    Employee(Observer *observer)
    {
        m_observer = observer;
        observer->setEmployee(this);
    }

    virtual void doThing() = 0;


private:
    Observer *m_observer;
};

class HR : public Observer
{
public:
    void setEmployee(Employee *employee)
    {
        m_list.push_back(employee);
    }

    void sendNotify()
    {
        for(list<Employee*>::iterator it = m_list.begin(); it != m_list.end(); it++)
            (*it)->doThing();
    }
private:
    list<Employee*> m_list;
};

class Coder : public Employee
{
public:
    Coder(Observer *observer): Employee(observer)
    {

    }

    virtual void doThing()
    {
        cout << "Pretend to work hard." << endl;
    }

};


}

#endif // OBSERVERMODE_HPP

