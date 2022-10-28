#ifndef _DEFAULT_FACTORY_H_
#define _DEFAULT_FACTORY_H_

#include "pipeline_data.h"
#include "processor.h"

#include <iostream>
#include <chrono>
#include <cstddef>
#include <cwchar>

namespace hum {

using std::chrono::system_clock;

class DefaultFactory {
public:
    DefaultFactory() {};

    DefaultFactory(const std::string name)
        :factory_name_(name), pdata_(nullptr) {};

    virtual ~DefaultFactory() {};

    bool process(PipelineData* data) {
        this->pdata_ = data;
        this->pdata_->flows.push_back(factory_name_);
        system_clock::time_point start = system_clock::now();
        bool res = implProcess();
        system_clock::time_point end = system_clock::now();
        std::chrono::milliseconds spend_time =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
#ifdef DEBUG
        std::cout << factory_name_ << " spend time: " 
                  << spend_time.count() << " milliseconds" << std::endl;
#endif
        if (res == true && next_factroy != nullptr) {
            res = next_factroy->process(data);
            return res;
        } else {
            return false;
        }
        return res;
    }

    const DefaultFactory* getNextFactory() const {
        return next_factroy;
    }

    void setNextFactory(DefaultFactory* next) {
        next_factroy = next;
    }

protected:
    virtual bool implProcess() { return false; };

protected:
    PipelineData* pdata_;
    std::string factory_name_;
    DefaultFactory* next_factroy;
};

};

#endif // _DEFAULT_FACTORY_H_