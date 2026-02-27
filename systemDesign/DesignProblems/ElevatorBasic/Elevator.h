#pragma once

#include "Requests.h"
#include <queue>
#include <iostream>
class Elevator
{
    public:
    void pushRequest(Requests req)
    {
        m_reqQ.push(req);
    }
    void step()
    {
        if(m_reqQ.empty() == true)
        {
            return;
        }

        Requests req = m_reqQ.front();
        

        //If reached destination then open gate and pop the requests and this has been served
        if(currentFloor == req.floorDestination)
        {
            currentDirection = Direction::IDLE;
            std::cout << "\n OPening Gate";
            m_reqQ.pop();
        }

        currentDestination = req.floorDestination;
        if(currentFloor < req.floorDestination && (currentDirection == Direction::UP || currentDirection == Direction::IDLE))
        {
            currentDirection = Direction::UP;
            currentFloor++;
        }

        else if(currentFloor > req.floorDestination && (currentDirection == Direction::DOWN || currentDirection == Direction::IDLE))
        {
            currentDirection = Direction::DOWN;
            
            currentFloor--;
        }
    }

    void Display()
    {
        std::cout << "\n ELEVATOR AT " << currentFloor << " ";
        std::string str;
        if(currentDirection == Direction::DOWN)
        {
            str = " Moving Down For Floor = " + std::to_string(currentDestination);
        }
        else if(currentDirection == Direction::UP)
        {
            str = " Moving Down For Floor = " + std::to_string(currentDestination);
        }
        else
        {
            str = " IDLE ";
        }

        std::cout << str << "\n";
    }


    private:
    int currentFloor = 0;
    int currentDestination = 0;
    std::queue<Requests> m_reqQ;
    Direction currentDirection;
};

