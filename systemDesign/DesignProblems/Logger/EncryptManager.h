#pragma once
#include "AES128Encrypt.h"
#include "BlowFishEncrypt.h"
#include <iostream>

class EncryptManager
{
    public:
    EncryptStrategy *GetEncryptAlgo(std::string type)
    {
        if(type == "AES")
        {
            return new AES128Encrypt;
        }
        else if(type == "Blowfish")
        {
            return new BlowFishEncrypt();
        }

        std::cout << "\n Invalid Algo passed\n";
        return nullptr;
    }
};