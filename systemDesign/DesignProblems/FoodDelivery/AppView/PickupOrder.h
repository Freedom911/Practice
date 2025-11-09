#pragma once
#include "../UserView/User.h"
#include "../UserView/NotificationStrategy.h"
#include "PaymentStrategy.h"
#include "Order.h"

class PickupOrder:public Order
{
    public:

    Order(User *user,PaymentStrategy *payment,NotificationStrategy *strategy, int orderID)
    {
        m_user = user;
        m_payment = payment;
        m_notification = notification;
        m_orderID = orderID;
    }

    virtual void OrderType() override
    {
        std::cout << "\n Creating order Type = " << " Pickup Order  for User = " << m_user->GetName << " ";
        std::cout << "\n Payment " ;
        m_payment->Pay();
        std::cout << " Notifying User ";
        m_notification->Notify();
        std::cout << " Order ID = " << m_orderID << "\n";
    }

};
