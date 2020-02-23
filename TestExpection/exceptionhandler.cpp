#include "exceptionhandler.h"

#include <iostream>
using namespace std;

ExceptionHandler::ExceptionHandler()
{

}

static void testIntNum(int num)
{
    if(num < 1 || num > 100)
        throw -1;
}

//exception int
void ExceptionHandler::testIntExceptional()
{
    try {
        testIntNum(100);
        testIntNum(1000);
    } catch(int num) {
        cout << "int exception, num = " << num << endl;
    } catch(...) {
        cout << "unknow exception" << endl;
    }

}


static void testCharStr(char *str)
{
    if(str == NULL || str[0] == 's')
        throw string("str is null");
}
//exception char*
void ExceptionHandler::testCharExceptional()
{
    try {
       // testCharStr("");
        throw "aaa";
    } catch (char *str){
        cout << "char exception, str = " << str << endl;
    } catch (string *str) {
        cout << "string exception, str = " << str << endl;
    } catch (...){
        cout << "unknow exception" << endl;
    }
}


class MyExpection :public exception
{
public:
    MyExpection() {}

    const char* what(){
        cout << "this is class exception" << endl;
    }

};

//exception class
void ExceptionHandler::testClassExceptional()
{
    try {
        throw MyExpection();
    } catch (MyExpection &e){
        e.what();
    } catch (...) {
        cout << "unknown exception";
    }
}


//exception inherent-class
void ExceptionHandler::testInherentClassExceptional()
{

}
