#ifndef PROTOTYPEMODE_H
#define PROTOTYPEMODE_H

#include <iostream>
using namespace std;
#include <string>

namespace prototypemode {

class Teacher
{
public:
    Teacher(int age, string name):m_age(age), m_name(name){}

    Teacher* getPrototype()
    {
        return this;
    }

    void printT()
    {
        cout << "age: " << m_age << "\tname: " << m_name << endl;
    }

private:
    int m_age;
    string m_name;

};

}

#endif // PROTOTYPEMODE_H

