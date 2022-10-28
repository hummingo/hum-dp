#include <iostream>

#include "product.h"
#include "abs_factory.h"

using namespace hum;

int main(int argc, char** argv) {
    AbsFactory* foo_factory = new FooFactory();
    AbsFactory* bar_factory = new BarFactory();
    IProduct* foo_A = foo_factory->CreateProductA();
    IProduct* foo_B = foo_factory->CreateProductB();
    IProduct* bar_A = bar_factory->CreateProductA();
    IProduct* bar_B = bar_factory->CreateProductB();

    std::cout << foo_A->getName() << std::endl;
    std::cout << foo_B->getName() << std::endl;
    std::cout << bar_A->getName() << std::endl;
    std::cout << bar_B->getName() << std::endl;

    delete foo_A;
    delete foo_B;
    delete bar_A;
    delete bar_B;
    delete foo_factory;
    delete bar_factory;
    return 0;
}