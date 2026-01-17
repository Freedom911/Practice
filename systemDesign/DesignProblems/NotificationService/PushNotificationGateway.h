#pragma once

/**
 * Class REsponible for sending Push Messages
 */
#include "NotificationGateway.h"
#include "Notification.h"
#include "Recipient.h"
#include <iostream>
class PushNotificationGateway : public NotificationGateway
{
    public:
        void send( Notification &notification) override
        {
            if (notification.GetRecipient().getToken().empty()) 
            {
                throw std::runtime_error("Token  is required for Token notification.");
            }

            std::cout << "--- Sending Push ---\n";
            std::cout << "To: " << notification.GetRecipient().getToken() << "\n";
            std::cout << "Subject: " << notification.GetSubject() << "\n";
            std::cout << "Body: " << notification.GetMessage() << "\n";
            std::cout << "---------------------\n\n";
        }
};
