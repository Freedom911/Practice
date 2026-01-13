#pragma once

#include <string>
#include "User.h"

class ActivityLog
{
    public:
    ActivityLog(std::string comment,std::string date,User *user)
    {
        m_comment = comment;
        m_date = date;
        m_user = user;
    }

    std::string GetLog()
    {
        std::string comment = m_date + " " + m_user->GetName() + " : " + m_comment;
        return comment;
    }

    void Display()
    {
        std::cout << "\n" << GetLog() << "\n";
    }

    private:
    std::string m_comment;
    std::string m_date;
    User *m_user;
};
