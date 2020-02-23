#ifndef PROXYMODE
#define PROXYMODE

#include <iostream>
using namespace std;

namespace proxymode {

class Book
{
public:
    virtual void sellBooks() = 0;
};

class BookStore : public Book
{
public:
    BookStore() {}
    void sellBooks()
    {
        cout << "bookstore sell books" << endl;
    }
};

class DangDang : public Book
{
  public:
    DangDang()
    {
        m_bookSaler = new BookStore;
    }
    void sellBooks()
    {
        cout << "Dang Dang  sell books for bookStore" << endl;
        m_bookSaler->sellBooks();
    }

private:
    Book* m_bookSaler;
};


}

#endif // PROXYMODE

