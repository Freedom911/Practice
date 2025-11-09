#pragma once

#include <string>

//This Class represents the menu item for a restaurant

class MenuItem
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

    void SetDescription(const std::string &description)
    {
        m_description = description;
    }

    void SetCost(const double &cost)
    {
        m_cost = cost;
    }

    std::string GetName() const
    {
        return m_name;
    }

    std::string GetDescription() const
    {
        return m_description;
    }

    int GetID() const
    {
        return m_id;
    }

    double GetCost() const
    {
        return m_cost;
    }

    private:

    std::string m_name;
    int m_id;
    std::string m_description;
    double m_cost;
};
