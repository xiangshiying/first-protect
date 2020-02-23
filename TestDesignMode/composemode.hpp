#ifndef COMPOSEMODE_HPP
#define COMPOSEMODE_HPP

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <list>

#include <algorithm>

namespace composemode {

class IFiles
{
  public:
    virtual void showName() = 0;
    virtual int addFile(IFiles *name) = 0;
    virtual int removeFile(IFiles *name) = 0;
    virtual list<IFiles*>* getFileList() = 0;

protected:
    string m_name;
};

class CFile : public IFiles
{
public:
    CFile(string name)
    {
        m_name = name;
    }
    void showName()
    {
        cout << "file name is: " << m_name << endl;
    }

    int addFile(IFiles *name)
    {
        return 0;
    }

    int removeFile(IFiles *name)
    {
        return 0;
    }

    list<IFiles*>* getFileList()
    {
        return NULL;
    }
};

class CDir : public IFiles
{
public:
    CDir(string name)
    {
        m_name = name;
        m_list = new list<IFiles*>;
        m_list->clear();
    }
    void showName()
    {
        cout << "file name is: " << m_name << endl;
    }

    int addFile(IFiles *name)
    {
        m_list->push_back(name);
        return 0;
    }

    int removeFile(IFiles *name)
    {
        list<IFiles*>::iterator it = find(m_list->begin(),m_list->end(),name);

        if(it != m_list->end())
            m_list->erase(it);

        //m_list->remove(name);

        return 0;
    }

    list<IFiles*>* getFileList()
    {
        return m_list;
    }

private:
    list<IFiles*> *m_list;
};

static void showIFiles(IFiles* files)
{
    if(files == NULL)
        return;

    files->showName();

    list<IFiles*> *flist = files->getFileList();

    if(flist != NULL)
    {
        for (list<IFiles*>::iterator it = flist->begin(); it != flist->end(); ++it)
            showIFiles(*it);
    }

}

}

#endif // COMPOSEMODE_HPP

