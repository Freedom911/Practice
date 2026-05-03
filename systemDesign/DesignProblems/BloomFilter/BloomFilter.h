#pragma once
#include <iostream>
#include <vector>
#include <shared_mutex>
#include <mutex>
#include "HashManager.h"
#include "HashTypeEnum.h"

/**
 * Ok So How Does bloom Filter works. It Takes a string
 * and calculate the hash of the string.
 *
 * Now It has a bloom array and it marks the position of the elements
 * How many to Mark. K positions to Mark
 *
 * WE mark all them 1. for checking we again clculate hash and check if all 1
 * if anyone 0 we say element not there
 *
 * So we need M = Size of Bit Array, K position to Mark
 * 
 * P = acceptable False positive Rate
 * N = No of elements we expect
 * 
 * ONe More thing
 * We have fixed two algos for hashing
 * So Having HashManager,Hash Straregy and Hash Factory is overeneinger
 * We can keep one HashManager only
 */

class BloomFilter
{
public:
    BloomFilter(const size_t &totalExpectedElements, const double &errorRate)
    {
        //Take Probablity also into account
        size_t bloomArraySize = 1000;
        m_k = 7;
        m_bloomArray.resize(bloomArraySize);
        for (size_t i = 0; i < bloomArraySize; i++)
        {
            m_bloomArray[i] = 0;
        }
    }

    void Add(const std::string &str)
    {
        std::unique_lock<std::shared_mutex> ul(m_mux);
        auto hashes = m_mgr.GetHashedValues(str);

        size_t M = m_bloomArray.size();
        for (size_t i = 0; i < m_k; i++)
        {
            size_t index = (hashes.first + i * hashes.second) % M;
            m_bloomArray[index] = 1;
        }
    }

    bool Check(const std::string &str)
    {
        std::shared_lock<std::shared_mutex> shared(m_mux);

        auto hashes = m_mgr.GetHashedValues(str);

        size_t M = m_bloomArray.size();
        for (size_t i = 0; i < m_k; i++)
        {
            size_t index = (hashes.first + i * hashes.second) % M;
            if (m_bloomArray[index] == 0)
            {
                return false;
            }
        }

        // element is there but there can be false positive
        // Like we say element is there but it is not
        return true;
    }

private:
    vector<bool> m_bloomArray;
    HashManager m_mgr;
    std::shared_mutex m_mux;
    size_t m_k{};
};
