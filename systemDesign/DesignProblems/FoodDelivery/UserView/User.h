#pragma once

#include "Cart.h"

class User
{

    public:
    User (std::string name,int id,std::string address)
    {
        m_name = name;
        m_id = id;
        m_address = address;
    }
    std::string GetName() const
    {
        return m_name;
    }

    int GetID() const
    {
        return m_id;
    }

    std::string GetAddress() const
    {
        return m_address;
    }

    Cart GetCart() const
    {
        return m_cart;
    }

    void SetCart(const Cart &cart)
    {
        m_cart = cart;
    }

    private:

    std::string m_name;
    int m_id;
    std::string m_address;
    Cart m_cart;
};
