#pragma once
#include "ElevatorStates.h"


class OpeningState : public ElevatorStates
{
public:
    explicit OpeningState(class Elevator *elevator) ;
    void Step() override;
    ~OpeningState() = default;
};