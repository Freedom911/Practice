#pragma once

#include "Restaurant.h"

//Single ton Class
class RestaurantManager
{
    public:

    
    static RestaurantManager &GetInstance()
    {
        static RestaurantManager restaurantManager_g;
        return restaurantManager_g;
    }

    //Delete copy Constructor and equal
    RestaurantManager(const RestaurantManager &mgr) = delete;
    RestaurantManager & operator = (const RestaurantManager &mgr) = delete;

    void AddRestaurant(const Restaurant &restaurant)
    {
        m_restaurants.push_back(restaurant);
    }

    void RemoveRestaurant(const int &id)
    {
        for(int i = 0; i < m_restaurants.size(); i++)
        {
            if(m_restaurants[i].GetID() == id)
            {
                m_restaurants.erase(m_restaurants.begin() + i);
            }
        }

    }

    void  GetRestaurants(std::vector<Restaurant> &restaurants)
    {
        restaurants = m_restaurants;
    }


    private:
    RestaurantManager() =  default;
    std::vector<Restaurant> m_restaurants;

};
