#pragma once

#include "PickupOrder.h"
#include "DeliveryOrder.h"
#include <string>
class OrderFactory
{
    public:
    
     virtual Order* CreateOrder(const std::string &Type,User *user,PaymentStrategy *payment,NotificationStrategy
     *strategy, int orderID,std::string time) = 0;
};
