#pragma once

/**
 * Class REsponible for sending Email Messages
 */
#include "NotificationGateway.h"
#include "Notification.h"
#include "Recipient.h"
#include <iostream>
class EmailNotificationGateway : public NotificationGateway
{
    public:
        void send(Notification &notification) override
        {
            if (notification.GetRecipient().getEmail().empty()) 
            {
                throw std::runtime_error("Email address is required for EMAIL notification.");
            }

            std::cout << "--- Sending EMAIL ---\n";
            std::cout << "To: " << notification.GetRecipient().getEmail() << "\n";
            std::cout << "Subject: " << notification.GetSubject() << "\n";
            std::cout << "Body: " << notification.GetMessage() << "\n";
            std::cout << "---------------------\n\n";
        }
};
