#pragma once
#include <iostream>
#include "HashManager.h"
#include <vector>
#include "HashTypeEnum.h"

class BloomFilter
{
    public:

    static BloomFilter &GetInstance()
    {
        static BloomFilter m_bloomFilter;
        return m_bloomFilter;
    }

    void Initialize()
    {
      size_t bloomArraySize = 100000;
      std::vector<HashTypeEnum> bloomFunctions {HashTypeEnum::STDHASH,HashTypeEnum::DJB2,HashTypeEnum::STDHASH,
      HashTypeEnum::DJB2};

      for(HashTypeEnum type : bloomFunctions)
      {
          m_mgr.AddHash(type);
      }
      m_bloomArray.resize(bloomArraySize);
      for(size_t i = 0; i < bloomArraySize; i++)
      {
          m_bloomArray[i] = 0;
      }

    }

    void Add(std::string str)
    {
        size_t totalHashFunc = m_mgr.GetTotalHashFunctions();
        size_t bloomArraySize = m_bloomArray.size();

        for(size_t i = 0; i < totalHashFunc; i++)
        {
            size_t hash = 0;
            if(m_mgr.GetHashedValue(str,i,hash))
            {
                m_bloomArray[hash % bloomArraySize] = 1;
            }
        }
    }

    bool Check(std::string str)
    {
        size_t totalHashFunc = m_mgr.GetTotalHashFunctions();
        size_t bloomArraySize = m_bloomArray.size();

        for(size_t i = 0; i < totalHashFunc; i++)
        {
            size_t hash = 0;
            if(m_mgr.GetHashedValue(str,i,hash))
            {
                //if anyone is off then we can positively say it is not there
                if(m_bloomArray[hash % bloomArraySize] == 0)
                {
                    return false;
                }
            }
        }
        
        //element is there but there can be false positive
        //Like we say element is there but it is not
        return true;

    }

    BloomFilter(const BloomFilter &obj) = delete;
    BloomFilter &operator = (const BloomFilter &obj) = delete;

    private:
    BloomFilter() = default;

    std::vector<bool> m_bloomArray;
    HashManager m_mgr;
};
