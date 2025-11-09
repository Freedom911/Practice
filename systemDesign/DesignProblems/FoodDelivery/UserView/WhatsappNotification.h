#pragma once
#include "NotificationStrategy.h"

class WhatsappNotification:public NotificationStrategy
{
    public:
    virtual void Notify() override
    {
        std::cout << "\n Sending Whatsapp SMS \n";
    }
};
