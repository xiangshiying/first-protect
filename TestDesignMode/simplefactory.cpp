#include "simplefactory.h"

simplefactory::SimpleFactory::SimpleFactory()
{

}

void simplefactory::Banana::fruitName()
{
    cout << "this is Banana." << endl;
}

void simplefactory::Apple::fruitName()
{
    cout << "this is Apple." << endl;
}

simplefactory::AbFruit* simplefactory::SimpleFactory::getFruit(string name)
{
    if(name.compare("Apple") == 0)
        return new Apple;
    else if(name.compare("Banana") == 0)
        return new Banana;
    else
        return NULL;
}
