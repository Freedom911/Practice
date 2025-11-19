#pragma once


#include <iostream>
#include "DBConnection.h"
#include "EncryptedDB.h"

//This Class represnets COmposition Adapter

class DBConnectionCompositionAdapter : public DBConnection
{
    public:
    DBConnectionCompositionAdapter(EncryptedDB *ptr)
    {
        m_ptr = ptr;
    }
    void InitConnection(std::string userName,std::string password) override
    {
        m_ptr->CheckSSLAndConnect(userName,password);
    }
    void executeQuery(std::string query) override
    {
        m_encresults.clear();
        m_ptr->ExecuteQuery(query,m_encresults);
    }
    std::vector<std::string> getResults() override
    {
        return m_encresults;
    }

    private:
    EncryptedDB *m_ptr;
    std::vector<std::string> m_encresults;
};