#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

namespace hum {

class IProduct {
public:
    IProduct() {};

    virtual ~IProduct() {};

    virtual std::string getName() const = 0;
};

class ProductBase
    :public IProduct {
public:
    ProductBase():name_("null") {};

    ProductBase(const std::string name):name_(name) {};

    ~ProductBase() {};

    std::string getName() const override { return name_; };

protected:
    std::string name_;
};

class FooProduct
    :public ProductBase {
public:
    FooProduct():ProductBase() {};

    FooProduct(const std::string name):ProductBase(name) {
        name_ = "Foo: " + name;
    };

    ~FooProduct() {};
};

class BarProduct
    :public ProductBase {
public:
    BarProduct():ProductBase() {};

    BarProduct(const std::string name):ProductBase(name) {
        name_ = "Bar: " + name;
    };

    ~BarProduct() {};
};

};

#endif // _PRODUCT_H_