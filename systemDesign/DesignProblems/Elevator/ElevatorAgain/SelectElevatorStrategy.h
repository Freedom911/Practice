#pragma once
#include <vector>
#include "Elevator.h"
class SelectElevatorStrategy
{
    public:

    virtual int GetBestElevator(const std::vector<std::unique_ptr<Elevator>> &elevators,const int &lastEleavator,const Requests &req) = 0;
    virtual ~SelectElevatorStrategy() = default;
};