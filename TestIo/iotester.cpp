#include "iotester.h"

#include <string.h>

IoTester::IoTester()
{

}


//cin test
void IoTester::testCin()
{
    char a;
    char b;
    char buf[256];

   // istream cinTest;

    cout << "please input 2 data:" << endl;

    cin >> a;
    cin >> b;

    cout << "a" << a << "b" << b << endl;

    cin.get(a);
    cin.get(b);
    cin.getline(buf, sizeof(buf));

    cout << "a" << a << "b" << b << "buf" << buf << endl;


}


//cout test
void IoTester::testCout()
{
    cout << hex << 22 << endl;
}


class Teacher
{
public:
    Teacher()
    {
        age = 0;
        name = new char(1);
        strcpy(name, "");
    }

    Teacher (int _age, char *_name):age(_age)
    {
        name = new char(strlen(_name)+1);
        strcpy(name, _name);
    }

    Teacher (const Teacher &obj)
    {
        if(name != nullptr)
        {
            delete []name;
            name = NULL;
            age = 0;
        }

        name = new char(strlen(obj.name)+1);
        strcpy(name, obj.name);

        age = obj.age;
    }

    ~Teacher()
    {
        if(name != nullptr)
        {
            delete []name;
            name = NULL;
            age = 0;
        }
    }

    void printT()
    {
        cout << "age:" << age << "name" << name << endl;
    }

private:
    int age;
    char *name;
};

//fio test
void IoTester::testFileIo()
{

    char *fName = "file.txt";

    Teacher t1(22,"zhangsan");
    Teacher t2(25,"Lisi");

    ofstream fout(fName, ios_base::binary);

    if (fout){
        fout.write((char *)&t1, sizeof(Teacher));
        fout.write((char *)&t2, sizeof(Teacher));
    }
    fout.close();


    ifstream fin(fName);
    Teacher tmp;

    fin.read((char *)&tmp, sizeof(Teacher));
    tmp.printT();

    fin.read((char *)&tmp, sizeof(Teacher));
    tmp.printT();

    fin.close();





}

