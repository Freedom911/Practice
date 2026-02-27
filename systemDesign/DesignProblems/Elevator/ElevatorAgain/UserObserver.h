#pragma once

#include "Observer.h"


class UserObserver : public Observer
{
    public:
    UserObserver(const std::string &name)
    {
        m_name = name;
    }
    ~UserObserver()
    {
    }
    void Update(const int &elevatorid,const int &floor) override
    { 
       std::cout << "\n User = " << m_name << " Observed Elevator ID = " <<  elevatorid << " At Floor = " << floor << "\n";
    }

    private:
    std::string m_name{};
};