#ifndef MEMORYMODE_HPP
#define MEMORYMODE_HPP

#include <iostream>
using namespace std;
#include <string>

namespace memorymode {

class Memory
{
public:
    Memory(string name, int age)
    {
       m_name = name;
       m_age = age;
    }
public:
    string m_name;
    int m_age;
};

class People
{
public:
    People(string name, int age):m_name(name), m_age(age) {}

    Memory* createMemory()
    {
        return new Memory(m_name, m_age);
    }

    void setMemory(Memory *memory)
    {
        m_name = memory->m_name;
        m_age = memory->m_age;
    }

    void setAge(int age)
    {
        m_age = age;
    }

    void printP()
    {
        cout << "name: " << m_name << "\t age: " << m_age << endl;
    }

private:
    string m_name;
    int m_age;
};

class ManagerM
{
public:
    ManagerM(Memory *memory)
    {
     m_memory = memory;
    }

    Memory* getMemory()
    {
        return m_memory;
    }

private:
    Memory *m_memory;
};

}

#endif // MEMORYMODE_HPP

