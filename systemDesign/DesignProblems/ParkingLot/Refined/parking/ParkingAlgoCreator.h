#pragma once
#include "ParkingAlgoEnum.h"
#include "ParkingStrategy.h"
#include "ClosestParking.h"


class ParkingAlgoCreator
{
    public:
     ParkingStrategy *CreateParkingAlgo(const ParkingAlgoEnum &type)
    {
        if(type == ParkingAlgoEnum::CLOSESTFIT)
        {
            return new ClosestParking();
        }
    }
};