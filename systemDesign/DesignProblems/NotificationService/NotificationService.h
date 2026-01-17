#pragma once
#include "Notification.h"
#include "RetryDecoratorNotificationGateway.h"
#include "NotificationGateway.h"
#include "NotificationGatewayCreator.h"
#include <iostream>
class NotificationService
{
    public:
        void sendNotification(Notification &notification)
        {
            NotificationGatewayCreator creator;
            NotificationGateway *gateway = creator.CreateGateway(notification.GetType());

            RetryDecoratorNotificationGateway gatewayWrapped(gateway);
            try
            {
                gatewayWrapped.send(notification);
            }catch(std::exception &e)
            {
                std::cout << e.what() << "\n";
            }

        }
};
