#pragma once 
#include "HashTypeEnum.h"
#include <string>

class HashStrategy
{
    public:
    virtual size_t CalculateHash(const std::string &str) = 0;
};
