#pragma once

/**
 * Base Class For Gateway for sending notification
 */
#include "Notification.h"

class NotificationGateway
{
    public:
    virtual ~NotificationGateway() = default;
    virtual void send(Notification &notification) = 0;
};
