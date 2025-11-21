#pragma once
#include "PaymentStrategy.h"
class VariablePayment: public PaymentStrategy
{
    public:
    double GetCost(double duration) override
    {
        return 30.0 * duration;
    }
};