#pragma once
#include <vector>
#include "Elevator.h"
#include "SelectElevatorStrategy.h"
class ClosestElevator : public SelectElevatorStrategy
{
    public:

     //we use direction and penalty system
     //if elevator going up and user presses up button
     //Cost = distance + DirectionPenalty + load penalty
     //SO basically the load penalty means if the elevator is idle and it has to start moving. we choose 5
     //now if the elevator is moving up and user is at upper floor then cost would be
     // Cost = abs(current - destination) + 0 + 0; ..Direction penalty will be 0 since in same direction
     //if user is down and elevator movinf awy then heavy penalty
     //cost = abs(current - destinatino) + 100 + 0;

     int GetBestElevator(const std::vector<std::unique_ptr<Elevator>> &elevators,
        const int &lastEleavator,const Requests &req) override
     {
        //Just Pick the closest elevator
        int minCost = std::numeric_limits<int>::max();
        int currentBestElevator = 0;
        for(int i = 0; i < elevators.size(); i++)
        {

            
            int currentFloor = elevators[i]->GetCurrentFloor();
            Direction direction = elevators[i]->GetCurrentDirection();
            int destinFloor = req.floorDestination;
            //Cost = distance + direction + load
            int cost = 0;
            int distancePenalty = std::abs(currentFloor - destinFloor);
            int directionPenalty = 0,loadPenalty = 0;

            if(direction == Direction::IDLE)
            {
                loadPenalty = 5;
            }
            else if(direction == Direction::DOWN)
            {
                if(currentFloor > destinFloor)//neche he going
                {
                    directionPenalty = 0;
                }
                else //destination is upper
                {
                    directionPenalty = 100;//give punishment as lift is going down 
                }
            }
            else
            {
               if(currentFloor < destinFloor)//Up he going
                {
                    directionPenalty = 0;
                }
                else //destination is neche
                {
                    directionPenalty = 100;//give punishment as lift is going down 
                }  
            }
            cost = distancePenalty + directionPenalty + distancePenalty;


            if(cost <= minCost)
            {
                currentBestElevator = i;
                minCost = cost;
            }
        }

        return currentBestElevator;
     }

     ~ClosestElevator() = default;
};