#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include <string>

class StdHash: public HashStrategy
{
   public:
    size_t CalculateHash(const std::string &str) override
    {
        std::hash<std::string> hashFun;
        return hashFun(str);
    }

};
