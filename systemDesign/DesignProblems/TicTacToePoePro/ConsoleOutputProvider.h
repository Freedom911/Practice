#pragma once
#include <iostream>
#include <string>
#include "IOutputProvider.h"


class ConsoleOutputProvider:public IOutputProvider
{
    public:

    void DisplayMessage(const std::string &message) override
    {
        std::cout << message;
    }
};