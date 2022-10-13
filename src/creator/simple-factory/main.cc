#include <iostream>
#include <memory>

#include "factory.h"

using namespace hum;

int main(int argc, char **argv) {
    std::shared_ptr<ProcessorFactory> p_factory = std::make_shared<ProcessorFactory>();

    std::shared_ptr<IProcessor> a_processor = p_factory->createAProcessor();
    std::shared_ptr<IProcessor> b_processor = p_factory->createBProcessor();

    a_processor->process();
    b_processor->process();

    return 0;
}