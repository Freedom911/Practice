#pragma once

#include "PaymentStrategy.h"

class FlatPayment: public PaymentStrategy
{
    public:
    
    FlatPayment()
    {
        m_baseFees = 50;
    }
    void CalculateCost(TokenDetails &details) 
    {
        details.TotalPayment = 50;
    }

    private:
    
    int m_baseFees;
};
