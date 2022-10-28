#include "chain_responsibility.h"
#include "checkprocess_factory.h"
#include "default_factory.h"
#include "preprocess_factory.h"
#include "process_factory.h"

#include <cstddef>
#include <iostream>

using namespace hum;

DefaultFactory* FactoryChain::preprocess_factory = nullptr;
DefaultFactory* FactoryChain::process_factory = nullptr;
DefaultFactory* FactoryChain::checkprocess_factory = nullptr;

FactoryChain::FactoryChain() {}

FactoryChain::~FactoryChain() {
    if (preprocess_factory) {
        delete preprocess_factory;
    }
    if (process_factory) {
        delete process_factory;
    }
    if (checkprocess_factory) {
        delete checkprocess_factory;
    }
}

DefaultFactory* FactoryChain::GetFactoryChain() {
    if (preprocess_factory == nullptr && process_factory == nullptr &&
        checkprocess_factory == nullptr) {
        preprocess_factory = new PreProcessFactory("preprocess");
        process_factory = new ProcessFactory("process");
        checkprocess_factory = new CheckProcessFactory("checkprocess");

        preprocess_factory->setNextFactory(process_factory);
        process_factory->setNextFactory(checkprocess_factory);
        checkprocess_factory->setNextFactory(nullptr);

        return preprocess_factory;
    } else {
        return preprocess_factory;
    }
}