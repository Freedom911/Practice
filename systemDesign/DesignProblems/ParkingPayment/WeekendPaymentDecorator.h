#pragma once
#include "PaymentStrategy.h"
#include "PaymentDecorator.h"

class WeekendPaymentDecorator : public PaymentDecorator
{
    public:
    WeekendPaymentDecorator(PaymentStrategy*str):PaymentDecorator(str){}

    double GetCost(double duration)
    {
        return m_str->GetCost(duration) + 30.0;
    }

};