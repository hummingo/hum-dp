#ifndef _PROCESS_FACTORY_H_
#define _PROCESS_FACTORY_H_

#include "pipeline_data.h"
#include "default_factory.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace hum {

class ProcessFactory
    :public DefaultFactory {
public:
    ProcessFactory():DefaultFactory() {};

    ProcessFactory(const std::string name):DefaultFactory(name) {};

    ~ProcessFactory() {};

    bool implProcess() override {
        std::cout << "process factory: processing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return true;
    };
};

};


#endif //  _PROCESS_FACTORY_H_