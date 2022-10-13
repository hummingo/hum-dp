#ifndef _SIMPLE_FACTORY_PROCESSOR_
#define _SIMPLE_FACTORY_PROCESSOR_

#include <string>

namespace hum {
class IProcessor {
public:
    IProcessor() = default;
    virtual ~IProcessor() = default;

    virtual bool process() = 0;
};

class DefaultProcessor: public IProcessor {
public:
    DefaultProcessor(const std::string name);
    virtual ~DefaultProcessor();

    bool process() override;
    virtual bool implProcess();

protected:
    std::string name_;
};

class AProcessor: public DefaultProcessor {
public:
    AProcessor(const std::string name);
    ~AProcessor();

    bool implProcess() override;
};

class BProcessor: public DefaultProcessor {
public:
    BProcessor(const std::string name);
    ~BProcessor();

    bool implProcess() override;
};
};

#endif // _SIMPLE_FACTORY_PROCESSOR_