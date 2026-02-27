#pragma once
#include <string>
#include <vector>
//Parent Class for DB related functionalities
class DBConnection
{
    public:
    virtual void InitConnection(std::string userName,std::string password) = 0;
    virtual void executeQuery(std::string query) = 0;
    virtual std::vector<std::string> getResults() = 0;


    protected:
    std::string m_userName;
    std::string m_password;
};