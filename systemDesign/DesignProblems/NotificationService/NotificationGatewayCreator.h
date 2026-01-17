#pragma once
#include "NotificationGateway.h"
#include "PushNotificationGateway.h"
#include "SMSNotificationGateway.h"
#include "EmailNotificationGateway.h"
#include "NotificationEnum.h"

class NotificationGatewayCreator
{
    public:
    NotificationGateway *CreateGateway(NotificationEnum type)
    {
        if(type == NotificationEnum::SMS)
        {
            return new SMSNotificationGateway();
        }
        else if(type == NotificationEnum::EMAIL)
        {
            return new EmailNotificationGateway();
        }
        else
        {
            return new PushNotificationGateway();
        }
    }
};


