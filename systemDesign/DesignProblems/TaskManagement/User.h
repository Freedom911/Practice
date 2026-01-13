#pragma once
#include <string>
#include <iostream>
#include "Observer.h"
/**
 * Class Repsobible for Users 
 */
class User : public Observer
{
    public:
    User(std::string l_name,int l_id,std::string l_email)
    {
        name = l_name;
        id = l_id;
        email = l_email;
    }

    std::string GetName() const 
    {
        return name;
    }

    void Update(std::string message) override
    {
        std::cout << name << " Notified for changes = " << message << "\n";
    }

    private:
    std::string name;
    int id;
    std::string email;
};
