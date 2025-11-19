#pragma once


#include <iostream>
#include "DBConnection.h"
#include "EncryptedDB.h"

//This Class represnets Inheritance Adapter

class DBConnectionInheritanceAdapter : public DBConnection,EncryptedDB
{
    public:

    void InitConnection(std::string userName,std::string password) override
    {
        EncryptedDB::CheckSSLAndConnect(userName,password);
    }
    void executeQuery(std::string query) override
    {
        m_encresults.clear();
        EncryptedDB::ExecuteQuery(query,m_encresults);
    }

    std::vector<std::string> getResults() override
    {
        return m_encresults;
    }

    private:

    std::vector<std::string> m_encresults;
};