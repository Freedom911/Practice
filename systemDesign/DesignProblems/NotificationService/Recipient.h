#pragma once

/**
 * Class having User Details
 */
#include <string>
class Recipient
{

    public:
    Recipient(std::string l_id,std::string l_name,std::string l_email,std::string l_phone,std::string l_token):
    userId{l_id},userName{l_id},email{l_email},phone{l_phone},token{l_token}
    {

    }

    std::string getUserID()
    {
        return userId;
    }
    std::string getUserName()
    {
        return userName;
    }
    std::string getEmail()
    {
        return email;
    }
    std::string getPhone()
    {
        return phone;
    }
    std::string getToken()
    {
        return token;
    }
    private:
    std::string userId;
    std::string userName;
    std::string email;
    std::string phone;
    std::string token;
};
