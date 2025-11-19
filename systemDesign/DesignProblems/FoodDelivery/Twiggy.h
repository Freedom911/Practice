#pragma once
#include <iostream>
#include "RestaurantView/Restaurant.h"
#include "RestaurantView/Menu.h"
#include "RestaurantView/MenuItem.h"
#include "RestaurantView/RestaurantManager.h"
#include "AppView/DeliveryOrder.h"
#include "AppView/NowOrderFactory.h"
#include "UserView/User.h"
#include "UserView/WhatsappNotification.h"
#include "UserView/SMSNotification.h"

class Twiggy
{
    public:
    Twiggy()
    {
        std::cout << "\n App Loaded VERSION X-91 \n";
    }

    //Initializes Restaurants
    void Initialize()
    {
        Menu BurgerSinghMenu;
        
        //Create MenuItem
        MenuItem hotshockFries;
        hotshockFries.SetName("HotShockFries");
        hotshockFries.SetDescription("Spicy Hot Shock Fries Burger Singh Special");
        hotshockFries.SetID(1);
        hotshockFries.SetCost(120.0);
        BurgerSinghMenu.AddItem(hotshockFries);

        MenuItem dill6;
        dill6.SetName("Dill 6 Chese Fries");
        dill6.SetDescription("Spicy Dill6 Cheese Fries");
        dill6.SetID(2);
        dill6.SetCost(250.0);
        BurgerSinghMenu.AddItem(dill6);

        MenuItem udtaPunjab;
        udtaPunjab.SetName("Udta Punjab");
        udtaPunjab.SetDescription("Udta Punjab Extra Cheesey Mayo Burger");
        udtaPunjab.SetID(3);
        udtaPunjab.SetCost(300.0);
        BurgerSinghMenu.AddItem(udtaPunjab);

        Restaurant burgerSingh;
        burgerSingh.SetAddress("Noida");
        burgerSingh.SetID(1);
        burgerSingh.SetName("Burger Singh");
        burgerSingh.SetMenu(BurgerSinghMenu);


        //Burger King
        Menu BurgerKingMenu;
        
        //Create MenuItem
        MenuItem VegWhooper;
        VegWhooper.SetName("Veg Whooper");
        VegWhooper.SetDescription("Veg Whooper Extra Tikki Burger");
        VegWhooper.SetID(4);
        VegWhooper.SetCost(110.0);
        BurgerKingMenu.AddItem(VegWhooper);

        MenuItem PizzaPuff;
        PizzaPuff.SetName("Pizza Puff");
        PizzaPuff.SetDescription("Fun of Pizza in Puff");
        PizzaPuff.SetID(5);
        PizzaPuff.SetCost(50.0);
        BurgerSinghMenu.AddItem(PizzaPuff);

        Restaurant burgerKing;
        burgerKing.SetAddress("Delhi");
        burgerKing.SetID(2);
        burgerKing.SetName("Burger King");
        burgerKing.SetMenu(BurgerKingMenu);
        

        //Add Restaurants and Menu
        RestaurantManager::GetInstance().AddRestaurant(burgerSingh);
        RestaurantManager::GetInstance().AddRestaurant(burgerKing);
    }

    Restaurant *SearchRestaurant(std::string location)
    {
        return RestaurantManager::GetInstance().SearchRestaurant(location);
    }

    std::vector<MenuItem> GetMenu(Restaurant *restaurant)
    {
        if(restaurant == nullptr)
        {
            std::cout << "\n No Restaurant Selected";
            return;
        }
        std::vector<MenuItem> menuItems;
        restaurant->GetMenu().GetMenuItems(menuItems);
    }

    void OrderItems(User *user,std::vector<int> MenuItemsID,std::string time,std::string orderType,
        std::string paymentType,std::string notificationType)
    {
         Order* order;
        if(time.empty())
        {
            order = new NowOrderFactory();
            order->CreateOrder(orderType,)
        }
        else
        {

        }
         Order* CreateOrder(const std::string &Type,User *user,PaymentStrategy *payment,NotificationStrategy
     *strategy, int orderID,std::string time) = 0;

    }


};