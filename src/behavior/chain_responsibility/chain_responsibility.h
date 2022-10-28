#include "pipeline_data.h"
#include "default_factory.h"
#include "preprocess_factory.h"
#include "process_factory.h"
#include "checkprocess_factory.h"

namespace hum {

class FactoryChain {
public:
    FactoryChain();

    ~FactoryChain();

    static DefaultFactory* GetFactoryChain();

public:
    static DefaultFactory* preprocess_factory;
    static DefaultFactory* process_factory;
    static DefaultFactory* checkprocess_factory;
};

};