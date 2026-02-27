#pragma once
#include "ElevatorStates.h"
#include "Elevator.h"
#include "Requests.h"

IDLEState::IDLEState(Elevator *elevator) : ElevatorStates{elevator}
{

}
void IDLEState::Step()
{
    Requests req;
    
    if (m_elevator->GetTopRequest(req))
    {
        std::cout << "\n HERE \n";
        // IDLE TO UP State
        if (req.floorDestination > m_elevator->GetCurrentFloor())
        {
            // move to up
            m_elevator->SetState(m_elevator->GetUpState());
        }
        else if (req.floorDestination < m_elevator->GetCurrentFloor())
        {
            m_elevator->SetState(m_elevator->GetDownState());
        }

        else if (req.floorDestination == m_elevator->GetCurrentFloor())
        {
            m_elevator->SetState(m_elevator->GetOpeningState());
        }
    }
}
