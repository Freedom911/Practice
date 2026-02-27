#pragma once
#include "ElevatorStates.h"
#include "Elevator.h"
#include "Requests.h"

UPState::UPState(Elevator *elevator) : ElevatorStates{elevator}
{
 
}
void UPState::Step()
{
    Requests req;
    if (m_elevator->GetTopRequest(req))
    {

        if (req.floorDestination > m_elevator->GetCurrentFloor())
        {
            // move to up
                       
            m_elevator->Notify();
            m_elevator->SetCurrentFloor(1);
        }

        else if (req.floorDestination == m_elevator->GetCurrentFloor())
        {
            std::cout << "\n TRANS\n";
            m_elevator->SetState(m_elevator->GetIdleState());
        }
    }
}
