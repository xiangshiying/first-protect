#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "singleton.h"
#include "simplefactory.h"
#include "abstractfactory.h"
#include "factorymode.h"
#include "prototypemode.hpp"
#include "buildermode.hpp"
#include "proxymode.hpp"
#include "bridgemode.hpp"
#include "composemode.hpp"
#include "templatemode.hpp"
#include "commandmode.hpp"
#include "responsemode.hpp"
#include "mediatormode.hpp"
#include "observermode.hpp"
#include "memorymode.hpp"
#include "visitormode.hpp"

class MainWindow
{
public:
    MainWindow();

    //test lazy/starving singleton
    void testSingleTon();

    //test simple factory
    void testSimpleFactory();

    //test abstractFactory
    void testAbstractFactory();

    //test factory mode
    void testFactoryMode();

    //test prototype mode
    void testPrototypeMode();

    //test builder mode
    void testBuilderMode();

    //test proxy mode
    void testProxyMode();

    //test brige mode
    void testBrigeMode();

    //test compose mode
    void testComposeMode();

    //test template mode
    void testTemplateMode();

    //test commander mode
    void testCommanderMode();

    //test response mode
    void testResponseMose();

    //test mediator mode
    void testMediatorMode();

    //test observer mode
    void testObserverMode();

    //test memory mode
    void testMemoryMode();

    //test visitor mode
    void testVisitorMode();


};

#endif // MAINWINDOW_H
