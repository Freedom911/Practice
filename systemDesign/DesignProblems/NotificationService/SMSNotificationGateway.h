#pragma once

/**
 * Class REsponible for sending Text Messages
 */
#include "NotificationGateway.h"
#include "Notification.h"
#include "Recipient.h"
#include <iostream>
class SMSNotificationGateway : public NotificationGateway
{
    public:
        void send(Notification &notification) override
        {
            if (notification.GetRecipient().getPhone().empty()) 
            {
                throw std::runtime_error("Phone is required for Phone notification.");
            }

            std::cout << "--- Sending Text Messages ---\n";
            std::cout << "To: " << notification.GetRecipient().getPhone() << "\n";
            std::cout << "Subject: " << notification.GetSubject() << "\n";
            std::cout << "Body: " << notification.GetMessage() << "\n";
            std::cout << "---------------------\n\n";
        }
};
