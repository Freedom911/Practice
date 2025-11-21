#pragma once
#include "PaymentStrategy.h"
class FlatPayment : public PaymentStrategy
{
    public:
    double GetCost(double duration) override
    {
        return 30.0;
    }
};