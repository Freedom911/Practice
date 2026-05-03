#include <iostream>
#include "GameEngine.h"
#include "ConsoleInputProvider.h"
#include "ConsoleOutputProvider.h"\


int main()
{
    GameEngine SraEngine;

    SraEngine.Initialize(std::make_shared<ConsoleInputProvider>(),std::make_shared<ConsoleOutputProvider>());
    SraEngine.Start();
}