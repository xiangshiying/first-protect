#ifndef VISITORMODE_HPP
#define VISITORMODE_HPP

#include <iostream>
using namespace std;

namespace visitormode {

class Element;
class Visitor
{
public:
    virtual void visit(Element* element) = 0;
};

class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
};

class ElementA : public Element
{
public:
    void accept(Visitor* visitor)
    {
        visitor->visit(this);
    }
};

class ElementB: public Element
{
public:
    void accept(Visitor* visitor)
    {
        visitor->visit(this);
    }
};

class VisitorA : public Visitor
{
public:
    void visit(Element *element)
    {
        cout << "Im visiting The Part A" << endl;
    }

};

class VisitorB : public Visitor
{
public:
    void visit(Element *element)
    {
        cout << "Im visiting The Part B" << endl;
    }

};

}

#endif // VISITORMODE_HPP

