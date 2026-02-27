#pragma once

/**
 * State for Elevator
 */

 class ElevatorStates
 {
    public:
    explicit ElevatorStates(class Elevator *elev) : m_elevator{elev}{}
    virtual void Step() = 0;
    virtual ~ElevatorStates() = default;

    protected:
    class Elevator *m_elevator{};

 };