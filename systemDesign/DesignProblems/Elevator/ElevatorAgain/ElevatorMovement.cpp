#include "Elevator.h"
#include "ElevatorMovement.h"

bool ElevatorMovement::Step(Elevator *elevator)
{
    bool isMoving = false;

    //Algo?
     //if elevator is moving up and user who is upper floor who also wants to go up 
    //presses then elevator takes that request and 
    if(elevator->m_currentDirection == Direction::UP)
    {
        //Find the next request
        auto it = elevator->m_reqUp.begin();
        if(it != elevator->m_reqUp.end())
        {
            int destination = it->floorDestination;

            //if current floor is lower
            if(elevator->m_currentFloor < destination)
            {
                elevator->Notify();
                elevator->m_currentFloor++;
                isMoving = true;
            }
            else if(elevator->m_currentFloor == destination)
            {
                elevator->Notify();
                elevator->m_reqUp.erase(it);
                isMoving = true;
            }
            //other case if user presses up and lift is upper then ignorewe handle when we move down
        }
        else
        {
            //no more request
            elevator->m_currentDirection = elevator->m_reqDown.empty() ? Direction::IDLE:Direction::DOWN;
        }
    }
    else if (elevator->m_currentDirection == Direction::DOWN)
    {
        //Find the next request.in down we proceess the largest
        auto it = elevator->m_reqDown.begin();
        if(it != elevator->m_reqDown.end())
        {
            int destination = it->floorDestination;

            //if current floor is Upper
            if(elevator->m_currentFloor > destination)
            {
                elevator->Notify();
                elevator->m_currentFloor--;
                isMoving = true;
            }
            else if(elevator->m_currentFloor == destination)
            {
                elevator->Notify();
                elevator->m_reqDown.erase(it);
                isMoving = true;
            }
            //other case if user presses down and lift is down then ignorewe handle when we move up
        }
        else
        {
            //no more request
            elevator->m_currentDirection = elevator->m_reqUp.empty() ? Direction::IDLE:Direction::UP;
        }
    }
    else //Idle case
    {
         if(elevator->m_reqUp.empty() == false)
        {
            
            elevator->m_currentDirection = Direction::UP;
        }
        else if(elevator->m_reqDown.empty() == false)
        {
            elevator->m_currentDirection = Direction::DOWN;
        }
    }
    return isMoving;
}