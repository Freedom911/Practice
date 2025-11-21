#pragma once
#include "PaymentStrategy.h"
#include "PaymentDecorator.h"

class FinePaymentDecorator : public PaymentDecorator
{
    public:
    FinePaymentDecorator(PaymentStrategy*str):PaymentDecorator(str){}

    double GetCost(double duration)
    {
        return m_str->GetCost(duration) + 1000.0;
    }

};