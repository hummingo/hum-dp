#ifndef _PREPROCESS_FACTORY_H_
#define _PREPROCESS_FACTORY_H_

#include "pipeline_data.h"
#include "default_factory.h"

#include <thread>
#include <chrono>
#include <iostream>

namespace hum {

class PreProcessFactory
    :public DefaultFactory {
public:
    PreProcessFactory():DefaultFactory() {};

    PreProcessFactory(std::string name):DefaultFactory(name) {};

    ~PreProcessFactory() {};

    bool implProcess() override {
        std::cout << "preprocess factory: processing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return true;
    };
};

};

#endif // _PREPROCESS_FACTORY_H_