#ifndef MEDIATORMODE_HPP
#define MEDIATORMODE_HPP

#include <iostream>
using namespace std;
#include <string>

namespace mediatormode {



class Person;
class AbMediator
{
public:
    void setMan(Person *man)
    {
        m_man = man;
    }

    void setWoman(Person *woman)
    {
        m_woman = woman;
    }

    virtual void makeCompare() = 0;

protected:
    Person *m_man;
    Person *m_woman;

};


class Person
{
public:
    Person(string name, int sex, int condi, AbMediator *mediator):m_name(name), m_sex(sex), m_condi(condi), m_mediator(mediator) {}

    string getName()
    {
        return m_name;
    }

    int getSex()
    {
        return m_sex;
    }

    int getCondition()
    {
        return m_condi;
    }

    virtual void setMarry(Person *person) = 0;

protected:
    string m_name;
    int m_sex;
    int m_condi;
    AbMediator* m_mediator;
};

class Mediator : public AbMediator
{
public:
    void makeCompare()
    {
        if(m_man->getSex() == m_woman->getSex()){
            cout << "Wrong sex" << endl;
        } else if(m_man->getCondition() != m_woman->getCondition()){
            cout << "Condition not match" << endl;
        } else {
            cout << "You meet the suitable one.\tthe name is :" << m_man->getName() << " and " << m_woman->getName() << endl;
        }
    }
};

class Man: public Person
{
public:
    Man(string name, int sex, int condi, AbMediator *mediator):Person(name, sex, condi, mediator) {}

    void setMarry(Person *person)
    {
        m_mediator->setMan(this);
        m_mediator->setWoman(person);
        m_mediator->makeCompare();
    }

};

class Woman: public Person
{
public:
    Woman(string name, int sex, int condi, AbMediator *mediator):Person(name, sex, condi, mediator) {}

    void setMarry(Person *person)
    {
        m_mediator->setWoman(this);
        m_mediator->setMan(person);
        m_mediator->makeCompare();
    }

};



}

#endif // MEDIATORMODE_HPP

