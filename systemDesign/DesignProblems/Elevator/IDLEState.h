#pragma once
#include "ElevatorStates.h"


class IDLEState : public ElevatorStates
{
public:
    explicit IDLEState(class Elevator *elevator);
    void Step() override;

    ~IDLEState() = default;
};