#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include <string>

class Djb2Hash: public HashStrategy
{
   public:
    size_t CalculateHash(const std::string &str)
    {
        size_t hash = 5381;

        for(const char ch : str)
        {
            hash = ((hash << 5) + hash) + ch;
        }

        return hash;
    }

};
