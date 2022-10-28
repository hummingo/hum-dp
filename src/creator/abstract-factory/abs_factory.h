#ifndef _ABS_FACTORY_H_
#define _ABS_FACTORY_H_

#include "product.h"

namespace hum {

class AbsFactory {
public:
    AbsFactory() {};

    virtual ~AbsFactory() {};

    virtual IProduct* CreateProductA() = 0;

    virtual IProduct* CreateProductB() = 0;
};

class FooFactory
    :public AbsFactory {
public:
    FooFactory();

    ~FooFactory();

    IProduct* CreateProductA() override;

    IProduct* CreateProductB() override;
};

class BarFactory
    :public AbsFactory {
public:
    BarFactory();

    ~BarFactory();

    IProduct* CreateProductA() override;

    IProduct* CreateProductB() override;
};

};

#endif // _ABS_FACTORY_H_