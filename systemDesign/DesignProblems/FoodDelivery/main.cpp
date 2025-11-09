#include <iostream>
#include <string>
#include "User.h"
#include "RestaurantView/RestaurantManager.h"

int main()
{

  //Add Restaurants and Menu
  RestaurantManager *mgr = RestaurantManager::GetInstance();

  mgr->AddRestaurant(burgerSingh);
  mgr->AddRestaurant(burgerKing);

  //Create User
  User *user = new User("Dant Manjan",0,"Mars Sector Alta");

  
}
