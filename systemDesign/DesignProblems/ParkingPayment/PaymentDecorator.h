#pragma once
#include "PaymentStrategy.h"

class PaymentDecorator : public PaymentStrategy
{
    public:
    PaymentDecorator(PaymentStrategy *str)
    {
        m_str = str;
    }

    virtual double GetCost(double duration) = 0;

    protected:
    PaymentStrategy *m_str;
};