#pragma once
#include "NotificationStrategy.h"

class SMSNotification:public NotificationStrategy
{
    public:
    virtual void Notify() override
    {
        std::cout << "\n Sending SMS \n";
    }
};
