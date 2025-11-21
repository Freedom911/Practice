#pragma once
#include "TokenDetails.h"
//class Base Class for Payemnt related functionalities

class PaymentStrategy
{
    public:
    virtual void CalculateCost(TokenDetails &details) = 0;
};