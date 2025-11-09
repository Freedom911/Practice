#pragma once

#include "OrderFactory.h"
#include "PickupOrder.h"
#include "DeliveryOrder.h"

class ScheduleOrderFactory:public OrderFactory
{
    public:
    
     Order* CreateOrder(const std::string &Type,User *user,PaymentStrategy *payment,NotificationStrategy *strategy, int
     orderID,std::string time)
     {
         std::cout << "\n Order will be placed at = " << time << "\n";
         if(Type == "Delivery")
         {
            return new DeliveryOrder(user,payment,strategy, orderID)
         }
         else
         {
             return new PickupOrder(user,payment,strategy,orderID);
         }

     }
};
