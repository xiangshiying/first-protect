#include "stltester.h"
#include <string.h>

StlTester::StlTester()
{

}

class Teacher
{
public:
    Teacher(int _age, char *_name):age(_age)
    {
        strcpy(name, _name);
    }

public:
    int age;
    char name[64];
};


struct TeacherFunc
{
  bool operator ()(const Teacher &a, const Teacher &b)
  {
      if(a.age < b.age)
          return true;
      else
          return false;
  }
};

template <typename T>
struct ShowElement
{
    bool operator()(T &n)
    {
        cout << n << " " << endl;
    }

};

//test string
void StlTester::testString()
{
    //initial for 4
    string str = "xixi test";

    //insert
    str.append(" hello world!");

    //get
    cout << str[0] << endl;

    //delete
    str.erase(0,1);

    //change
    str.at(0) = 'k';

    //organize
   // transform(str.begin(),str.end(),str.begin(),toupper(str));

    cout << "upper" << str << endl;
}

struct IsGreater
{
    IsGreater(int num):m_num(num){}

    bool operator ()(int num)
    {
        return num > m_num;

    }

private:
    int m_num;
};

struct MyAdd
{
    int operator ()(int num1, int num2)
    {
        return num1 + num2;
    }

};

int mysum(int &num1, int &num2)
{
    return num1 + num2;
}

//test vector
void StlTester::testVector()
{
    //initial
    vector<int> vec;
    //insert
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }

    //get
    for(int i = 0; i < vec.size(); i++)
    {
        cout << " " << vec.at(i);
    }
    cout << endl;

    //delete
    vec.erase(vec.begin(),vec.begin()+3);

    //change
    vec.back() = 100;

    //organize
    for(int i = 0; i < vec.size(); i++)
    {
        cout << " " << vec.at(i);
    }
    cout << endl;

    int num = count(vec.begin(), vec.end(), 3);
    cout << "the value 3 number is : " << num << endl;

    num = count_if(vec.begin(), vec.end(), IsGreater(4));
    cout << "the greater 3 number is : " << num << endl;

    num = count_if(vec.begin(), vec.end(), bind2nd(modulus<int>(), 2));
    cout << "the moudules 2 == 0 number is : " << num << endl;

    num = count_if(vec.begin(), vec.end(), not1(bind2nd(modulus<int>(), 2)));
    cout << "the moudules 2 == 1 number is : " << num << endl;


    vector<int> v2, v3;
    v2.push_back(200);
    v2.push_back(200);
    v2.push_back(200);
    v2.push_back(200);

    v3.resize(10);

    transform(vec.begin(), vec.end(), v2.begin(), v3.begin(), MyAdd());
    for(int i = 0; i < v3.size(); i++)
    {
        cout << " " << v3.at(i);
    }
    cout << endl;



}

//test set
void StlTester::testSet()
{
    //initial
    set<Teacher, TeacherFunc> setTester;
    //insert
    Teacher t1(36, "zhangsan");
    Teacher t2(34, "lisi");
    Teacher t3(35, "wangwu");
    Teacher t4(36, "liuliu");

    pair<set<Teacher>::iterator, bool> pair1 = setTester.insert(t1);
    cout << "pair1->second:" << pair1.second << endl;
    setTester.insert(t2);
    setTester.insert(t3);

    pair<set<Teacher>::iterator, bool> pair2 = setTester.insert(t4);
    cout << "pair2->second:" << pair2.second << endl;
    //get

    for(set<Teacher>::iterator it = setTester.begin(); it != setTester.end(); it++)
    {
        cout << "age:" << it->age << " name:" << it->name << endl;
    }

    //delete
    //setTester.erase(setTester.end());

    //change

    //organize
}

//test list
void StlTester::testList()
{
    //initial
    list<int> listTest;

    //insert
    for (int i = 0; i < 10; ++i){
        listTest.push_front(i+1);
    }

    //get
    for(list<int>::iterator it = listTest.begin(); it != listTest.end(); it++)
    {
        cout << *it << " " << endl;
    }

    //delete
    listTest.erase(++listTest.begin(), ++(listTest.begin()));
    listTest.remove(5);

    //change
    listTest.insert(listTest.begin(), 100);

    //organize
    listTest.sort();

    for(list<int>::iterator it = listTest.begin(); it != listTest.end(); ++it)
    {
        cout << *it << " " << endl;
    }

}

//test deque
void StlTester::testDeque()
{
    //initial
    deque<int> dequeTester;

    //insert
    for(int i = 0; i < 10; i++)
    dequeTester.insert(dequeTester.begin(), i+1);

    //get
    for_each(dequeTester.begin(), dequeTester.end(), ShowElement<int>());

    //delete
    dequeTester.pop_front();
    dequeTester.pop_back();

    //change
    random_shuffle(dequeTester.begin(), dequeTester.end());
    for_each(dequeTester.begin(), dequeTester.end(), ShowElement<int>());

    //organize
    sort(dequeTester.begin(), dequeTester.end());
    for_each(dequeTester.begin(), dequeTester.end(), ShowElement<int>());
}

//priority queue

static void testQueuePriority()
{
    priority_queue<int, vector<int>, greater<int>> priQueueTester;

    priQueueTester.push(3);
    priQueueTester.push(13);
    priQueueTester.push(5);
    priQueueTester.push(23);
    priQueueTester.push(8);
    priQueueTester.push(7);

    while( !priQueueTester.empty() )
    {
        cout << " " << priQueueTester.top();
        priQueueTester.pop();
    }
    cout << endl;
}

//test queue
void StlTester::testQueue()
{
    //initial
    queue<int> queueTester;

    //insert
    int a = 10;
    queueTester.push(a);

    for(int i = 10; i > 0; i--)
    {
        queueTester.push(i+1);
    }

    //get
    while( !queueTester.empty() )
    {
        cout << " " << queueTester.front();
        queueTester.pop();
    }
    cout << endl;
    //delete

    //change

    //organize

    //other
    testQueuePriority();
}

//test map
void StlTester::testMap()
{
    //initial
    map<int,string> mapTester;

    //insert
    mapTester.insert(make_pair(1, "zhangsan"));
    mapTester.insert(pair<int,string>(2, "lisi"));
    mapTester.insert(map<int, string>::value_type(3, "wangwu"));
    mapTester[4] = "liuniu";

    //get
   for(map<int,string>::iterator it = mapTester.begin(); it != mapTester.end(); ++it)
   {
        cout << "first" << it->first << "second" << it->second << endl;
   }

    //delete
    mapTester.erase(mapTester.begin());

    //change
    mapTester[4] = "Xixi";
    //organize

    map<int,string>::iterator it2 =  mapTester.find(3);
    if(it2 != mapTester.end())
    {
        cout << "find the data" << " first: " << it2->first << " second: " << it2->second << endl;
    }

    while(!mapTester.empty())
    {
        map<int,string>::iterator it3 = mapTester.begin();
        cout << "first: " << it3->first << "\tsecond: " << it3->second << endl;
        mapTester.erase(it3);
    }

    if(mapTester.empty()){
        cout << "maptTester is empty!" << endl;
    }

}

struct Speaker
{
  string m_name;
  int m_score[3];
};


static void startCompetetion(int number, vector<int> &vin, map<int, Speaker> &mapSpeaker, vector<int> &vout)
{

    //random_shuffle
    random_shuffle(vin.begin(), vin.end());

    int temp = 0, score, average;
    deque<int> dequeScore;
    multimap<int, int, greater<int>> mapGroupScore;
    //make group
    for(vector<int>::iterator it = vin.begin(); it != vin.end(); ++it)
    {
        ++temp;
        for(int i = 0; i < 10; i++)
        {
            score = rand()%50+50;
            dequeScore.push_back(score);
        }

        sort(dequeScore.begin(), dequeScore.end());
        dequeScore.pop_back();
        dequeScore.pop_front();

        average = accumulate(dequeScore.begin(), dequeScore.end(), 0)/8;
        mapGroupScore.insert(make_pair(average, *it));

        mapSpeaker[*it].m_score[number] = average;

        if((temp % 6) == 0)
        {
            cout << "group score:" << endl;

           for(multimap<int, int, greater<int>>::iterator it2 = mapGroupScore.begin(); it2 != mapGroupScore.end(); ++it2)
           {
               cout << "speaker number:" << it2->second << "\tspeaker score:" << it2->first << endl;
           }

           while(mapGroupScore.size() > 3)
           {
                multimap<int, int, greater<int>>::iterator it3 = mapGroupScore.begin();
                vout.push_back(it3->second);
                cout << "win speaker number is :" << it3->second << "\twin score is :" << it3->first << endl;
                mapGroupScore.erase(it3);
           }

           mapGroupScore.clear();
        }
       dequeScore.clear();
    }

}

static void generateSpeaker(vector<int> &vec, map<int, Speaker> &mapSpeaker)
{
    Speaker tmp;
    string speaker = "speaker";
    for(int i = 100; i < 124; i++ )
    {
        char x = (char)(i-35);
        speaker = "speaker";
        tmp.m_name = speaker.append(1, x);

        memset(tmp.m_score, 0, sizeof(tmp.m_score));
        vec.push_back(i);
        mapSpeaker.insert(make_pair(i, tmp));
    }
}

static void printVec(int number, vector<int> vec,  map<int, Speaker> &mapSpeaker)
{
        cout << "The result of "<< number << "competetion" << endl;
        for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            cout << "The speaker number is:" << *it << "\tname:" << mapSpeaker[*it].m_name << "\tscore"
                 << mapSpeaker[*it].m_score[number-1] << endl;
        }
}

//test sample
void StlTester::testSpeakerCompetition()
{
    vector<int> v1,v2,v3,v4;
    map<int, Speaker> mapSpeaker;

    //generate speaker
    generateSpeaker(v1, mapSpeaker);

    cout << "start first competetion, press any key continue..." << endl;
    cin.get();
    //first competetion
    //make group
    //competetion
    startCompetetion(0, v1, mapSpeaker, v2);

    //printLefe
    printVec(1, v2, mapSpeaker);

    cout << "start second competetion, press any key continue..." << endl;
    cin.get();
    //second competetion
    //make group
    //competetion
    startCompetetion(1, v2, mapSpeaker, v3);
    //printLefe
    printVec(2, v3, mapSpeaker);

    cout << "start third competetion, press any key continue..." << endl;
    cin.get();
    //third competetion
    //make group
    //competetion
    startCompetetion(2, v3, mapSpeaker, v4);
    //printLefe
    printVec(3, v4, mapSpeaker);



}
