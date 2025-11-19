#pragma once
#include <random>

class Die
{
    public:
    Die()
    {
        std::random_device rd;
        
        
        m_mt.seed(rd());
    }

    int RollDie()
    {
        std::uniform_int_distribution<> ud(1,6);

        return ud(m_mt);
    }

    private:
    std::mt19937 m_mt;
};