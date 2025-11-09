#pragma once
#include <string>
#include "Menu.h"

class Restaurant
{

    public:
    void SetName(const std::string &name)
    {
        m_name = name;
    }

    void SetID(const int &id)
    {
        m_id = id;
    }

    void SetAddress(const std::string &address)
    {
        m_address = address;
    }

    void SetMenu(const Menu &menu)
    {
        m_menu = menu;;
    }

    std::string GetName() const
    {
        return m_name;
    }

    std::string GetAddress() const
    {
        return m_address;
    }

    int GetID() const
    {
        return m_id;
    }

    Menu GetMenu() const
    {
        return m_menu;
    }

    private:

    std::string m_name;
    int m_id;
    std::string m_address;
    Menu m_menu;
};

