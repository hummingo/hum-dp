#include "factory.h"
#include "processor.h"


using namespace hum;

ProcessorFactory::ProcessorFactory() {};

ProcessorFactory::~ProcessorFactory() {};

std::shared_ptr<IProcessor> ProcessorFactory::createAProcessor() {
    return std::make_shared<AProcessor>("A");
}

std::shared_ptr<IProcessor> ProcessorFactory::createBProcessor() {
    return std::make_shared<BProcessor>("B");
}