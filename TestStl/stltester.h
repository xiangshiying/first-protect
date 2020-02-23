#ifndef STLTESTER_H
#define STLTESTER_H


#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <map>

#include <algorithm>
#include <functional>

class StlTester
{
public:
    StlTester();

    //test string
    void testString();

    //test vector
    void testVector();

    //test set
    void testSet();

    //test list
    void testList();

    //test deque
    void testDeque();

    //test queue
    void testQueue();

    //test map
    void testMap();

    //test sample
    void testSpeakerCompetition();

};

#endif // STLTESTER_H
