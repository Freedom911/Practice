#pragma once
#include<string>

class IInputProvider
{
    public:
    virtual int GetInputAsInt(const std::string &message) = 0;
    virtual std::string GetInputAsString(const std::string &message) = 0;
};