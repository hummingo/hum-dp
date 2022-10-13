#include <iostream>
#include <string>

#include "factory.h"
#include "processor.h"

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

int main(int argc, char **argv) {
    std::cout << "hello world!" << std::endl;

    std::shared_ptr<ProcessorFactory> p_factory = std::make_shared<ProcessorFactory>();
    std::shared_ptr<IProcessor> a_processor = p_factory->createAProcessor();
    std::shared_ptr<IProcessor> b_processor = p_factory->createBProcessor();
    a_processor->process();
    b_processor->process();

    return 0;
}