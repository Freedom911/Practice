#pragma once
#include<string>

class IOutputProvider
{
    public:
    virtual void DisplayMessage(const std::string &message) = 0;
};