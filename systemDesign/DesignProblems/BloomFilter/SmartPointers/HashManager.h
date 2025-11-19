#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include "HashFactory.h"
#include <string>
#include <vector>
#include <memory>


class HashManager
{
    public:

    ~HashManager()
    {
        ClearHashFunctions();
    }

    void AddHash(const HashTypeEnum &type)
    {
        m_hashFunctions.push_back((m_factory.CreateHashFunction(type)));
    }

    size_t GetTotalHashFunctions()
    {
        return m_hashFunctions.size();
    }

    void ClearHashFunctions()
    {
        m_hashFunctions.clear();
    }

    bool GetHashedValue(const std::string &str,const size_t &index,size_t &hashedValue)
    {
        if(index < m_hashFunctions.size())
        {
            hashedValue = (m_hashFunctions[index]->CalculateHash(str) + index);
            return true;
        }

        return false;
    }

    

    private:
    std::vector<std::unique_ptr<HashStrategy>> m_hashFunctions;
    HashFactory m_factory;
};
