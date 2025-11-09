#pragma once
#include "PaymentStrategy.h"
class UPIPayment
{
    public:
    virtual void Pay() override
    {
        std::cout << "\n Paying Through UPI";
    }
};
