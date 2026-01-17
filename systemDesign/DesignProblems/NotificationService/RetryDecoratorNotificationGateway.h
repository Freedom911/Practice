#pragma once

/**
 * Decorator Class REsponible for retrying messages
 */
#include "NotificationGateway.h"
#include "Notification.h"
#include "Recipient.h"
#include <thread>
#include <iostream>
#include <chrono>

class RetryDecoratorNotificationGateway : public NotificationGateway
{
    public:
        RetryDecoratorNotificationGateway(NotificationGateway * gateway)
        {
            m_gateway = gateway;
        }
        void send(Notification &notification) override
        {
            int attempt = 0;
            while (attempt < 10) 
            {
                try 
                {
                    m_gateway->send(notification);
                    return; // Success
                }
                catch (const std::exception& e) 
                {
                    attempt++;
                    std::cout << "Error: Attempt " << attempt << " failed for notification " << notification.Getid() <<
                    ". Retrying..." << std::endl;
                    if (attempt >= 10) 
                    {
                        std::cout << e.what() << std::endl;
                        throw std::runtime_error("Failed to send notification after " + std::to_string(10) + " attempts.");
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }
            }
        }

    private:
        NotificationGateway *m_gateway;
};
