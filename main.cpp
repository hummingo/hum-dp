#include <chrono>
#include <iostream>
#include <string>

#include "factory.h"
#include "pipeline_data.h"
#include "processor.h"

#include "abs_factory.h"

#include "chain_responsibility.h"

using namespace hum;

class GClass {
public:
    GClass() {
        std::cout << "g_class ctor" << std::endl;
    }
    ~GClass() {}
private:
    int val_;
};

static GClass g_class;

void TestSimpleFactory() {
    std::shared_ptr<ProcessorFactory> p_factory = std::make_shared<ProcessorFactory>();
    std::shared_ptr<IProcessor> a_processor = p_factory->createAProcessor();
    std::shared_ptr<IProcessor> b_processor = p_factory->createBProcessor();
    a_processor->process();
    b_processor->process();
}

void TestAbstractFactory() {
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
}

void TestChainResonsibility() {
    FactoryChain factory = FactoryChain();
    DefaultFactory* factory_chain = factory.GetFactoryChain();

    PipelineData* data = new PipelineData();
    factory_chain->process(data);

    for (const auto& flow:data->flows) {
        std::cout << "flow: " << flow << std::endl;
    }

    delete data;
}


int main(int argc, char **argv) {
    std::cout << "hello world!" << std::endl;

    TestChainResonsibility();
    return 0;
}