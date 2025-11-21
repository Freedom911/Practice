#pragma once

class PaymentStrategy
{
    public:
    virtual double GetCost(double duration) = 0;
    
};