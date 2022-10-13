#include "processor.h"

#include <iostream>
#include <string>

using namespace hum;

DefaultProcessor::DefaultProcessor(std::string name)
    :name_(name) {};

DefaultProcessor::~DefaultProcessor() {};

bool DefaultProcessor::process() {
    std::cout << name_ << ": begin process" << std::endl;
    bool res = this->implProcess();
    if (res == true) {
        std::cout << name_ << ": successful" << std::endl;
    } else {
        std::cout << name_ << ": failture" << std::endl;
    }
    std::cout << name_ << ": end process" << std::endl;
    return res;
}

bool DefaultProcessor::implProcess() {
    std::cout << "default process" << std::endl;
    return false;
}

AProcessor::AProcessor(std::string name)
    :DefaultProcessor(name) {};

AProcessor::~AProcessor() {};

bool AProcessor::implProcess() {
    std::cout << name_ << ": process" << std::endl;
    return true;
}

BProcessor::BProcessor(std::string name)
    :DefaultProcessor(name) {};

BProcessor::~BProcessor() {};

bool BProcessor::implProcess() {
    std::cout << name_ << ": process" << std::endl;
    return true;
}