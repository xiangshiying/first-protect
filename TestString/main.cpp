#include <iostream>
#include <string.h>
using namespace std;


#include <vector>
#include "smartptr.hpp"

class MyString
{
public:
    MyString(char* str = NULL)
    {

        if(str != NULL){
            m_p = (char*)malloc(sizeof(str) + 1);

            strcpy(m_p, str);
        } else {
            m_p = NULL;
        }

    }

    ~MyString()
    {
        if(m_p != NULL)
        {
            free(m_p);
            m_p = NULL;
        }
    }

    MyString(const MyString &str)
    {

        m_p = (char*)malloc(sizeof(str.m_p) + 1);

        strcpy(m_p, str.m_p);


    }

    MyString& operator =(const MyString &str)
    {

        if(m_p != NULL)
        {
            free(m_p);
            m_p = NULL;
        }

        m_p = (char*)malloc(sizeof(str.m_p) + 1);

        strcpy(m_p, str.m_p);

        return *this;
    }

    void printMS()
    {
        if(m_p != NULL)
            cout << "m_p: " << m_p << endl;
    }

private:
    char *m_p;

};

class A
{
public:

    virtual void getNumber(int a)
    {
        cout << "A" << endl;
    }

    void getNumber2(int)
    {
        cout << "A2" << endl;
    }

    void getNumber3(int c, int d)
    {
        cout << "A3" << endl;
    }

};

class B: public A
{
public:

    void getNumber(int a)
    {
        cout << "B" << endl;
    }

    void getNumber2(float)
    {
        cout << "B2" << endl;
    }

    void getNumber3(int c, int d)
    {
        cout << "B3" << endl;
    }

};

class C
{
public:

    int getC1()
    {
        cout << "C1" << endl;
    }

    int getC2() const
    {
     //   ++m_c;
     //   getC1();
        return m_c;
    }

private:
    int m_c;


};


int main1()
{
    cout << "Hello World!" << endl;

    MyString str("MyString");
    str.printMS();

    MyString str2 = str;
    str2.printMS();

    MyString str3;
    str3 = str2;
    str3.printMS();


    return 0;
}

int main2()
{
    cout << "Hello World!" << endl;



    A a;
    B b;
    a.getNumber(1);
    a.getNumber(2);


    b.getNumber2(4);
    b.getNumber2(1);

    a.getNumber3(2,2);
    b.getNumber3(2,2);

    A *pA = &b;
    B *pB = &b;


    pA->getNumber(1);
    pB->getNumber(2);


    pA->getNumber2(4);
    pB->getNumber2(1);

    pA->getNumber3(2,2);
    pB->getNumber3(2,2);



    return 0;
}

int main3()
{
    char p[] = " Cisco system";
    char *p2 = p;

    int a = 0xff;
    int *p3 = &a;
    int b = *p3;
    //b = *p3++;
    p3++;
    cout << "b:" << b << "\ta:" << a << "\tp3:" << *p3 << endl;
    p3++;
    cout << "b:" << b << "\ta:" << a << "\tp3:" << *p3 << endl;


    char c = *p2++;
    cout << "p2:" << p2 << "\tP2:" << p2 << "\tc:" << c << endl;

    p2++;
    cout << "p2:" << p2 << endl;

    return 0;
}

struct Test
{ Test( int ) {}
Test() {}
void fun() {}
};
int main5( void )
{


    vector<int> array;
    array.push_back( 1 );
    array.push_back( 2 );
    array.push_back( 3 );

    for( vector<int>::size_type i=array.size()-1; i>=0; --i ) // 反向遍历array数组
    { cout << array[i] << endl;
    }


return 0;
}

int main4()
{

    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char* str5 = "abc";
    const char* str6 = "abc";
    cout << boolalpha << ( str1==str2 ) << endl; // 输出什么？
    cout << boolalpha << ( str3==str4 ) << endl; // 输出什么？
    cout << boolalpha << ( str5==str6 ) << endl; // 输出什么？


    return 0;
}


int main()
{

    smartptr::testMain();

    return 0;
}











