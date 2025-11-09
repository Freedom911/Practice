#pragma once
#include "../UserView/User.h"
#include "../UserView/NotificationStrategy.h"
#include "PaymentStrategy.h"

class Order
{
    public:

    Order(User *user,PaymentStrategy *payment,NotificationStrategy *strategy, int orderID)
    {
        m_user = user;
        m_payment = payment;
        m_notification = notification;
        m_orderID = orderID;
    }

    virtual void OrderType() = 0;

    protected:

    User *m_user;
    PaymentStrategy *m_payment;
    NotificationStrategy *m_notification;
    int m_orderID;

};
