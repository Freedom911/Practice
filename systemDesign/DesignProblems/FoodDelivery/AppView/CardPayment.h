#pragma once
#include "PaymentStrategy.h"
class CardPayment
{
    public:
    virtual void Pay() override
    {
        std::cout << "\n Paying Through Card";
    }
};
