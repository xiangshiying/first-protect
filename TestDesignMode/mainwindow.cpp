#include "mainwindow.h"

MainWindow::MainWindow()
{

}

//test singleton
void MainWindow::testSingleTon()
{
    SingleTon *singleTon1 = SingleTon::getInstance();
    singleTon1->printT();

    SingleTon *singleTon2 = SingleTon::getInstance();
    singleTon2->printT();

    if(singleTon1 == singleTon2)
        cout << "SingleTon1 == SingleTon2" << endl;
    else
        cout << "SingleTon1 != SingleTon2" << endl;

    SingleTon::deleteSingleTon();
}

//test simple factory
void MainWindow::testSimpleFactory()
{
    simplefactory::AbFruit *fruit;
    simplefactory::SimpleFactory *factory = new simplefactory::SimpleFactory;

    fruit = factory->getFruit("Apple");
    if(fruit)
        fruit->fruitName();
    delete fruit;

    fruit = factory->getFruit("Banana");
    if(fruit)
        fruit->fruitName();
    delete fruit;

}

//test abstractFactory
void MainWindow::testAbstractFactory()
{
    AbFruit *fruit;
    AbstractFactory *abstractFactory;

    abstractFactory = new BananaFactory;
    fruit = abstractFactory->getFruit();
    if(fruit)
        fruit->fruitName();
    delete fruit;
    delete abstractFactory;

    abstractFactory = new AppleFactory;
    fruit = abstractFactory->getFruit();
    if(fruit)
        fruit->fruitName();
    delete fruit;
    delete abstractFactory;

}

//test factory mode
void MainWindow::testFactoryMode()
{
    factorymode::FMfruit* fruit = NULL;
    factorymode::FMvegetables* vegetables = NULL;

    factorymode::FactoryMode* factory = new factorymode::FactoryMode;

    fruit = factory->getFruit();
    vegetables = factory->getVegetables();

    fruit->sayName();
    vegetables->sayVegetableName();

    delete vegetables;
    delete fruit;
    delete factory;

}

//test prototype mode
void MainWindow::testPrototypeMode()
{
    prototypemode::Teacher *teacher1 = new prototypemode::Teacher(33, string("zhangsan"));
    teacher1->printT();

    prototypemode::Teacher *teacher2 = teacher1->getPrototype();
    teacher2->printT();

}

//test builder mode
void MainWindow::testBuilderMode()
{
    buildermode::House *house = NULL;
    buildermode::HouseMaker *houseMaker = NULL;
    buildermode::Structer* structer = NULL;

    houseMaker = new buildermode::FlatHouse;
    structer = new buildermode::Structer(houseMaker);
    structer->buildHouse();
    house = houseMaker->getHouse();
    house->printHouse();

    delete house;
    delete structer;
    delete houseMaker;

}

//test proxy mode
void MainWindow::testProxyMode()
{
    proxymode::DangDang *dangdang = new proxymode::DangDang;
    dangdang->sellBooks();
}

//test brige mode
void MainWindow::testBrigeMode()
{
    bridgemode::Engine *engine = new bridgemode::Engine4430;
    bridgemode::Car *car = new bridgemode::BM7(engine);
    car->showName();

    delete car;
    delete engine;
}

//test compose mode
void MainWindow::testComposeMode()
{
    composemode::IFiles *dirc = new composemode::CDir("C:/");

    composemode::IFiles *file1 = new composemode::CFile("111.txt");
    composemode::IFiles *dir1 = new composemode::CDir("dir1");

    composemode::IFiles *file2 = new composemode::CFile("222.txt");
    composemode::IFiles *dir2 = new composemode::CDir("dir2");

    dirc->addFile(dir1);
    dirc->addFile(file1);

    dir1->addFile(file2);
    dir1->addFile(dir2);


    composemode::showIFiles(dirc);

    delete dir2;
    delete file2;
    delete dir1;
    delete file1;
    delete dirc;

}

//test template mode
void MainWindow::testTemplateMode()
{
    templatemode::Car *car = new templatemode::BMCar;
    car->makeCar();
}

//test commander mode
void MainWindow::testCommanderMode()
{
    commandmode::Doctor *doctor = new commandmode::Doctor;

    commandmode::Commander *commander1 = new commandmode::EyesCommander(doctor);
    commandmode::Commander *commander2 = new commandmode::NoseCommander(doctor);

    commandmode::Nurse *nurse = new commandmode::Nurse;
    nurse->setCommander(commander1);
    nurse->setCommander(commander2);

    nurse->submit();

}

//test response mode
void MainWindow::testResponseMose()
{
    responsemode::Car *headcar = new responsemode::HeadCar;
    responsemode::Car *bodycar = new responsemode::BodyCar;
    responsemode::Car *tailcar = new responsemode::TailCar;

    headcar->setNextStep(bodycar);
    bodycar->setNextStep(tailcar);
    tailcar->setNextStep(NULL);

    headcar->makeCar();

}

//test mediator mode
void MainWindow::testMediatorMode()
{
    mediatormode::Mediator *mediator = new mediatormode::Mediator;

    mediatormode::Person *woman1 = new mediatormode::Woman("Russian", 2, 5, mediator);
    mediatormode::Person *woman2 = new mediatormode::Woman("Lisamer", 2, 4, mediator);
    mediatormode::Person *man1 = new mediatormode::Man("Frand", 1, 5, mediator);

    man1->setMarry(woman1);

    woman1->setMarry(man1);
    woman2->setMarry(man1);

    delete man1;
    delete woman2;
    delete woman1;
    delete mediator;

}

//test observer mode
void MainWindow::testObserverMode()
{

     observermode::Observer *observer = new observermode::HR;

     observermode::Employee *coder1 = new observermode::Coder(observer);
     observermode::Employee *programmer1 = new observermode::Coder(observer);
     observermode::Employee *tester1 = new observermode::Coder(observer);
     observermode::Employee *manager1 = new observermode::Coder(observer);

     observer->sendNotify();

     delete manager1;
     delete tester1;
     delete programmer1;
     delete coder1;
     delete observer;

}

//test memory mode
void MainWindow::testMemoryMode()
{
    memorymode::People *people = new memorymode::People("zhangsan", 33);
    memorymode::ManagerM *manager = new memorymode::ManagerM(people->createMemory());

    people->printP();
    people->setAge(40);
    people->printP();

    people->setMemory(manager->getMemory());

    people->printP();

    delete manager;
    delete people;
}


//test visitor mode
void MainWindow::testVisitorMode()
{
    visitormode::Visitor *visitorA = new visitormode::VisitorA;
    visitormode::Visitor *visitorB = new visitormode::VisitorB;

    visitormode::Element *elementA = new visitormode::ElementA;
    visitormode::Element *elementB = new visitormode::ElementB;

    elementA->accept(visitorA);
    elementB->accept(visitorB);

    delete elementB;
    delete elementA;
    delete visitorB;
    delete visitorA;


}
