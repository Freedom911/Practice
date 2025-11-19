#pragma once
#include "GameState.h"

class GameType
{
    public:
    virtual void Initialize() = 0;
    virtual  GameState Update() = 0;
};