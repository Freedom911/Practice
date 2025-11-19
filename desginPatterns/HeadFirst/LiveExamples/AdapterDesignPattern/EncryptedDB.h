#pragma once

#include <iostream>
#include <string>
#include <vector>
class EncryptedDB
{
    public:

    void CheckSSLAndConnect(std::string username,std::string password)
    {
        std::cout << "\n CHECKING SSL CONNECTION FIRST";
        std::cout << "\n Encrypting Username and Password ";
        username = Encrypt(username);
        password = Encrypt(password);
        std::cout << "\n CONNECTION DONE " << username << " " << password << "\n";
    }

    void ExecuteQuery(std::string query,std::vector<std::string> &results)
    {
        query = Encrypt(query);
        std::cout << "\n EXEUCTING QUERY = " << query;
        results.push_back("ENC_ABCD");
        results.push_back("ENC_DDCD");
    }

    private:

    std::string Encrypt(std::string plainText)
    {
        return "enc" + plainText + "enc";
    }

};