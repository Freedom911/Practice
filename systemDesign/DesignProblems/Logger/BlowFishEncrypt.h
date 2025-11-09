#pragma once
#include "EncryptStrategy.h"

class BlowFishEncrypt : public EncryptStrategy
{
    public:
     std::string Encrypt(std::string plainText) override
     {
        if(plainText.length() > 0)
            return "BlowFish" + plainText;
        else
            return "";
     }
     std::string Decrypt(std::string encText) override
     {
        if(encText.length() > 0 && encText.find("BlowFish") != std::string ::npos)
        {
              return encText.substr(8);
        }
        else
        {
            return encText;
        }
     }
};