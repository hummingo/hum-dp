#ifndef _CHECKPROCESS_FACTORY_H_
#define _CHECKPROCESS_FACTORY_H_

#include "pipeline_data.h"
#include "default_factory.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace hum {

class CheckProcessFactory
    :public DefaultFactory {
public:
    CheckProcessFactory():DefaultFactory() {};

    CheckProcessFactory(const std::string name):DefaultFactory(name) {};

    ~CheckProcessFactory() {};

    bool implProcess() {
        std::cout << "checkprocess factory: processing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return true;
    }
};

};

#endif // _CHECKPROCESS_FACTORY_H_