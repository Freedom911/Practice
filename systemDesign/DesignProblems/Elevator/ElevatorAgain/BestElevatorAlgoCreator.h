#pragma once

/**
 * Factory Class responible for choosing Best Elevator to Pick
 */
#include "ClosestElevator.h"
#include "SelectElevatorStrategy.h"
#include "ElevatorStrategyEnum.h"

class BestElevatorAlgoCreator
{
    public:
    std::unique_ptr<SelectElevatorStrategy> GetElevatorStrategy(ElevatorStrategyEnum strategy)
    {
        if(strategy == ElevatorStrategyEnum::CLOSEST)
        {
            return std::make_unique<ClosestElevator>();
        }
        return nullptr;
    }
};
