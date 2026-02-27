#pragma once
#include "ElevatorStates.h"
#include "Elevator.h"
#include "Requests.h"

DownState::DownState(Elevator *elevator) : ElevatorStates{elevator}
{
 
}
void DownState::Step()
{
    Requests req;
    if (m_elevator->GetTopRequest(req))
    {

        if (req.floorDestination < m_elevator->GetCurrentFloor())
        {
            // move to Down
            m_elevator->SetCurrentFloor(-1);
        }

        else if (req.floorDestination == m_elevator->GetCurrentFloor())
        {
            m_elevator->SetState(m_elevator->GetIdleState());
        }
    }
}
