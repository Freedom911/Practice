#include <iostream>
#include "GameEngine.h"


int main()
{
    GameEngine::GetInstance().Initialize();
    GameEngine::GetInstance().Start();
}