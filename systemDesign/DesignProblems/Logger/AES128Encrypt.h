#pragma once
#include "EncryptStrategy.h"

class AES128Encrypt : public EncryptStrategy
{
    public:
     std::string Encrypt(std::string plainText) override
     {
        if(plainText.length() > 0)
            return "AES128" + plainText;
        else
            return "";
     }
     std::string Decrypt(std::string encText) override
     {
        if(encText.length() > 0 && encText.find("AES128") != std::string::npos)
        {
              return encText.substr(6);
        }
        else
        {
            return encText;
        }
     }
};