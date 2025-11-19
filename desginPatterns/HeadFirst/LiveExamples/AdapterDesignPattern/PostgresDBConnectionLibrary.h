#pragma once

#include<iostream>
#include "DBConnection.h"
//class for db connection used everywhere in our traffic mon project and challan

class PostgresDBConnectionLibrary : public DBConnection
{
    public:
    void InitConnection(std::string userName,std::string password) override
    {
        m_userName = userName;
        m_password = password;

        std::cout << "\n Initiating POSTGRESQL Connection \n";
    }
    void executeQuery(std::string query) override
    {
        std::cout << "\n EXECUTING QUERY = " << query;
    }
    std::vector<std::string> getResults() override
    {
        std::vector<std::string>results;
        results.push_back("ABCD");
        results.push_back("DDCD");
        return results;

    }
};