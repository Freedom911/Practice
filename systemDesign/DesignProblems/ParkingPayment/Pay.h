#pragma once
#include "PaymentDecorator.h"
#include "PaymentStrategy.h"
#include "FlatPayment.h"
#include "VariablePayment.h"
#include "WeekendPaymentDecorator.h"
#include "FinePaymentDecorator.h"

class Pay
{
    public:
    Pay(double duration)
    {
        m_duration = duration;

    }

    double GetCost()
    {
        VariablePayment paymentStrategy;

        // Add weekend fee (if applicable)
        WeekendPaymentDecorator weekend (&paymentStrategy);
        

         // Add fine (if applicable)
        FinePaymentDecorator fine(&weekend); // Add $50 fine

        return fine.GetCost(m_duration);
    }



    private:
    double m_duration;
};