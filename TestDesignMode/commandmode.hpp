#ifndef COMMANDMODE_HPP
#define COMMANDMODE_HPP

#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <algorithm>

namespace commandmode {

class Doctor
{
public:
    void treatEyes()
    {
        cout << "doctor treat the eyes" << endl;
    }

    void treatNose()
    {
        cout << "doctor treat the nose" << endl;
    }

};

class Commander
{
public:
    Commander(Doctor *doctor)
    {
        m_doctor = doctor;
    }

    virtual void treat() = 0;

protected:
    Doctor *m_doctor;
};

class NoseCommander : public Commander
{
public:
    NoseCommander(Doctor* doctor): Commander(doctor)
    {

    }

    void treat()
    {
        m_doctor->treatNose();
    }
};

class EyesCommander : public Commander
{
public:
    EyesCommander(Doctor* doctor): Commander(doctor)
    {

    }

    void treat()
    {
        m_doctor->treatEyes();
    }
};

class Nurse
{
public:
    Nurse()
    {
        m_vec = new vector<Commander*>;
        m_list = new list<Commander*>;
    }

    ~Nurse()
    {
       m_vec->clear();
       m_list->clear();

       delete m_vec;
       delete m_list;
    }

    void setCommander(Commander* commander)
    {
        m_list->push_back(commander);
        m_vec->push_back(commander);
    }

    void submit()
    {
//        for(vector<Commander*>::iterator it = m_vec->begin(); it != m_vec->end();)
//        {
//            (*it)->treat();
//            m_vec->erase(it);
//        }

        list<Commander*>::iterator tmp = m_list->begin();
        for(list<Commander*>::iterator it = m_list->begin(); it != m_list->end();  )
        {
            (*it)->treat();

            tmp = ++it;
            m_list->erase(it);
            it = tmp;
        }
    }

private:
    vector<Commander*> *m_vec;

    list<Commander*> *m_list;
};

}

#endif // COMMANDMODE_HPP

