#pragma once
#include "GameState.h"
#include <memory>
#include "IInputProvider.h"
#include "IOutputProvider.h"

class GameType
{
    public:
    virtual void Initialize(std::shared_ptr<IInputProvider> input,std::shared_ptr<IOutputProvider> output) = 0;
    virtual  GameState Update() = 0;
};