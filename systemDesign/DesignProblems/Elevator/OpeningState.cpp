#pragma once
#include "ElevatorStates.h"
#include "Elevator.h"
#include "Requests.h"

OpeningState::OpeningState(Elevator *elevator) : ElevatorStates{elevator}
{
    
}
void OpeningState::Step()
{
    Requests req;
    if (m_elevator->GetTopRequest(req))
    {
        if (req.floorDestination == m_elevator->GetCurrentFloor())
        {
            m_elevator->CompleteRequest();
            m_elevator->SetState(m_elevator->GetIdleState());
        }
    }
}
