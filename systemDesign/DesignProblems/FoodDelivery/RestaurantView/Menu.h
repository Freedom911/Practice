#pragma once

#include <string>
#include "MenuItem.h"

class Menu
{
    public:

    void GetMenuItems(std::vector<MenuItem> & items) const
    {
        items = menuItem;
    }

    void AddItem(const MenuItem &menuItem)
    {
        menuItems.push_back(menuItem);
    }

    void RemoveItem(const int &id)
    {
        for(int i = 0; i < menuItems.size(); i++)
        {
            if(menuItems[i].GetID() == id)
            {
                menuItems.erase(menuItems.begin() + i);
            }
        }

    }
    private:
    std::vector<MenuItem> menuItems;

};
