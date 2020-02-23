#include <QCoreApplication>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainWindow mainWindow;

    //test singleton
    //mainWindow.testSingleTon();

    //test simplefactory
    //mainWindow.testSimpleFactory();

    //test abstractfactory
    //mainWindow.testAbstractFactory();

    //test factorymode
    //mainWindow.testFactoryMode();

    //test prototypemode
    //mainWindow.testPrototypeMode();

    //test builermode
    //mainWindow.testBuilderMode();

    //test proxymode
    //mainWindow.testProxyMode();

    //test bridgemode
    //mainWindow.testBrigeMode();

    //test composemode
    //mainWindow.testComposeMode();

    //test templatemode
    //mainWindow.testTemplateMode();

    //test commandermode
    //mainWindow.testCommanderMode();

    //test responsemode
    //mainWindow.testResponseMose();

    //test mediatormode
    //mainWindow.testMediatorMode();

    //test obersermode
    //mainWindow.testObserverMode();

    //test memorymode
    //mainWindow.testMemoryMode();

    //test visitormode
    mainWindow.testVisitorMode();

    return a.exec();
}

