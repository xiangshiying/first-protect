#include "typetransfer.h"

class Animal;

TypeTransfer::TypeTransfer()
{

}

class Animal
{
public:
    Animal() {}

protected:
    virtual void doThing() = 0;

};

class Dog : public Animal
{
public:
    Dog() {}

    void doThing()
    {
        cout << "watch home ..." << endl;
    }

    void cry()
    {
        cout << "wang wang ..." << endl;
    }

};

class Cat :public Animal
{
public:
    Cat() {}

    void doThing()
    {
        cout << "grab mouse ..." << endl;
    }

    void sleep()
    {
        cout << "miao maio ..." << endl;
    }
};

// static cast
void TypeTransfer::transStatic()
{
    cout << "static_cast test." << endl;
    int a = 10;
    double b = static_cast<double>(a);

    cout << "(int) a:" << a << " (double) b:" << b << endl;
}

// reinterpreter cast
void TypeTransfer::transReinterpreter()
{
    cout<< "reinterpreter_cast test." << endl;
    char *p = "xixi";
    int *q = reinterpret_cast<int*>(p);

    cout << "(char*) p:" << p << " (int*) q:" << q << endl;
}

static void testDynamicCast(Animal *animal)
{
    Cat *cat = dynamic_cast<Cat*>(animal);
    if(cat != nullptr){
     cat->doThing();
     cat->sleep();
    }

    Dog *dog = dynamic_cast<Dog*>(animal);
    if(dog != nullptr){
     dog->doThing();
     dog->cry();
    }

}

// dynamic cast
void TypeTransfer::transDynamic()
{
    cout << "dynamic_cast test." << endl;

    Dog *dog = new Dog();
    Cat *cat = new Cat();

    testDynamicCast(dog);
    testDynamicCast(cat);

}

// const cast
void TypeTransfer::transConst()
{
    cout << "const_cast test." << endl;

    const char p[] = "hello world!";
    char *q = const_cast<char*>(p);
    q[0] = 'z';

    cout << "(const char*) p:" << p << " (char*)q:" << q << endl;
}
