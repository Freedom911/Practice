#pragma once
#include "HashTypeEnum.h"
#include "HashStrategy.h"
#include "HashFactory.h"
#include <string>
#include <vector>
#include <memory>
/**
 * Class Manages Hash Strategy.
 * Although Conceptually we need multiple hash functions. but here we use only 2 hash functions
 * Bloom Filter doesnt need k filters rather we need to generate k position and we do that by
 * using 2 hash functinos
 * h1(x) + index*h2(x)
 * So for each index of string we generate hash value
 */

class HashManager
{
    public:

    HashManager()
    {
       m_hash1 = std::move(m_factory.CreateHashFunction(HashTypeEnum::DJB2));
       m_hash2 = std::move(m_factory.CreateHashFunction(HashTypeEnum::STDHASH));
    }

     std::pair<size_t,size_t>  GetHashedValues(const std::string &str)
    {
        size_t hash1 =  m_hash1->CalculateHash(str);
        //if hash2 == 0 then it will make all varibale to be same as it will depend on hash1 only
        // index = hash1 + index * hash2
        size_t hash2 =  m_hash2->CalculateHash(str);

        if (hash2 == 0)
        {
            hash2 = 1;
        }
        return {hash1,hash2};
    }


    private:
    std::unique_ptr<HashStrategy> m_hash1;
    std::unique_ptr<HashStrategy> m_hash2;
    HashFactory m_factory;
};
