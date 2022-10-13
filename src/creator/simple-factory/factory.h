#ifndef _SIMPLE_FACTORY_FACTORY_
#define _SIMPLE_FACTORY_FACTORY_

#include "processor.h"
#include <memory>

namespace hum {
class ProcessorFactory {
public:
    ProcessorFactory();
    ~ProcessorFactory();

    static std::shared_ptr<IProcessor> createAProcessor();
    static std::shared_ptr<IProcessor> createBProcessor();
};
};

#endif // _SIMPLE_FACTORY_FACTORY_