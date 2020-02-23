#ifndef TEMPFUNC_H
#define TEMPFUNC_H


template <typename T>
class TempFunc
{
public:
    TempFunc(T a = 0);

    void printValue();

    void myAdd(const TempFunc<T> &obj);

    void testTempFunc();

private:
    T a;
};

#endif // TEMPFUNC_H
