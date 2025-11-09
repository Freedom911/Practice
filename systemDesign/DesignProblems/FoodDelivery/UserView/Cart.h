#pragma once

#include "MenuItem.h"

class Cart
{
    public:
    
    void AddItem(const MenuItem &item)
    {
        m_items.push_back(item);
    }


    void RemoveItem(const int &id)
    {
        for(int i = 0; i < m_items.size(); i++)
        {
            if(m_items[i].GetID() == id)
            {
                m_items.erase(m_items.begin() + i);
            }
        }
    }

    void ClearCart()
    {
        m_items.clear();
    }

    double GetTotalCost()
    {
        double cost = 0.0;
        for(MenuItem item : m_items)
        {
            cost += item.GetCost();
        }

        return cost;
    }

    private:
    std::vector<MenuItem> m_items;
};
