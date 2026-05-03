#pragma once
#include <iostream>
#include <string>
#include "IInputProvider.h"


class ConsoleInputProvider:public IInputProvider
{
    public:
    int GetInputAsInt(const std::string &message) override
    {
        std::cout << message << "\n";
        int input;
        std::cin >> input;
        return input;
    }
    
    std::string GetInputAsString(const std::string &message) override
    {
        std::cout << message << "\n";
        std::string input;
        std::cin >> input;
        return input;
    }
};