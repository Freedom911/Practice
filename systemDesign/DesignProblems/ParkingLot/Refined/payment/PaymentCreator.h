#pragma once
#include "PaymentStrategy.h"
#include "VariablePayment.h"
#include "FlatPayment.h"
#include "PaymentTypeEnum.h"

class PaymentCreator
{
    public:
    PaymentStrategy *CreatePaymentMethod(const PaymentType &type)
    {
        if(type == PaymentType::FLAT)
        {
            return new FlatPayment();
        }
        else
        {
            return new VariablePayment();
        }
    }
};