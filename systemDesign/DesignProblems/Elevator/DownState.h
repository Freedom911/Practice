#pragma once
#include "ElevatorStates.h"


class DownState : public ElevatorStates
{
public:
    explicit DownState(class Elevator *elevator);
    void Step() override;
    
    ~DownState() = default;
};