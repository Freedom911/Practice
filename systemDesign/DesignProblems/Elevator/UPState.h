#pragma once
#include "ElevatorStates.h"

class UPState : public ElevatorStates
{
public:
    explicit UPState(class Elevator *elevator);
    void Step() override;

    ~UPState() = default;
};