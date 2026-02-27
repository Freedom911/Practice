#pragma once
#include <vector>
#include "Elevator.h"
#include "SelectElevatorStrategy.h"
class ClosestElevator : public SelectElevatorStrategy
{
    public:

     int GetBestElevator(const std::vector<std::unique_ptr<Elevator>> &elevators,const int &lastEleavator,const Requests &req) override
     {
        //Just Pick the closest elevator
        int minDistance = std::numeric_limits<int>::max();
        int currentBestElevator = 0;
        for(int i = 0; i < elevators.size(); i++)
        {

            
            int currentFloor = elevators[i]->GetCurrentFloor();

            int destinFloor = currentFloor;

            Requests request;
            if(elevators[i]->GetTopRequest(request))
            {
                destinFloor = request.floorDestination;
            }

            if(std::abs(req.floorDestination - destinFloor) <= minDistance)
            {
                std::cout << "ELEVATOR = " << i << " " << req.floorDestination << " " << destinFloor << "\n";
                currentBestElevator = i;
                minDistance = std::abs(req.floorDestination - destinFloor);
            }
        }

        return currentBestElevator;
     }

     ~ClosestElevator() = default;
};