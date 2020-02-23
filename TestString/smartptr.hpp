#ifndef SMARTPTR_HPP
#define SMARTPTR_HPP


//top network c++ interview question

#include <iostream>
#include <memory>
#include <string>

using namespace std;


namespace smartptr
{

//Base Test Class
class MyTest
{
public:
    MyTest()
    {
        cout << "MyTest()" << endl;
        m_age = 26;
        m_name = "xixi";
    }

    MyTest(int age, string name)
    {
        cout << "MyTest(age, name)" << endl;
        m_age = age;
        m_name = name;
    }

    ~MyTest()
    {
        cout << "~MyTest()" << endl;
    }

    void printM()
    {
        cout << "name:" << m_name << "\tage:" << m_age << endl;
    }

public:
    int m_age;
    string m_name;

};


//test shared_ptr
void testSharedPtr(shared_ptr<MyTest>& test)
{
    test->printM();
    cout << "shared_count:" << test.use_count() << endl;
}

//test lambda
void testLambda(shared_ptr<MyTest>& test)
{
    int b = 3;
    cout << "lambda test.use_count:" << test.use_count() << endl;
    int a = [&](int c)mutable
    {
        test->printM();
        cout << "lambda test.use_count:" << test.use_count() << endl;
        b = 10;
        cout << "c:" << c << endl;
        return 0;
    }(55);
    cout << "lambda test.use_count:" << test.use_count() << endl;
}

void testMain()
{

    //test shared_ptr
    shared_ptr<MyTest> shareMytest  = make_shared<MyTest>();
    cout << "shared_count:" << shareMytest.use_count() << endl;
    testSharedPtr(shareMytest);
    cout << "shared_count:" << shareMytest.use_count() << endl;


    testLambda(shareMytest);

}

}

#endif // SMARTPTR_HPP

