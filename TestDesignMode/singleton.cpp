#include "singleton.h"


SingleTon *SingleTon::m_singleTon = NULL;
int SingleTon::m_count = 0;

SingleTon::SingleTon()
{
    cout << "SingleTon Struct Function" << endl;
}

SingleTon* SingleTon::getInstance()
{
    if(m_singleTon == NULL)
    {
        m_singleTon = new SingleTon;
    }

    ++m_count;
    return m_singleTon;
}

void SingleTon::printT()
{
    cout << "SingleTon::m_count = " << SingleTon::m_count << endl;
}

void SingleTon::deleteSingleTon()
{
    if(m_singleTon != NULL)
    {
        delete m_singleTon;
        m_singleTon = NULL;
        m_count = 0;
    }

    cout << "delete the SingleTon Memory" << endl;
}
