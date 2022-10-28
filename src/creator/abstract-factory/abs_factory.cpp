#include "abs_factory.h"
#include "product.h"

using namespace hum;

FooFactory::FooFactory() {}

FooFactory::~FooFactory() {}

IProduct* FooFactory::CreateProductA() {
    return new FooProduct("A");
}

IProduct* FooFactory::CreateProductB() {
    return new FooProduct("B");
}

BarFactory::BarFactory() {}

BarFactory::~BarFactory() {}

IProduct* BarFactory::CreateProductA() {
    return new BarProduct("A");
}

IProduct* BarFactory::CreateProductB() {
    return new BarProduct("B");
}