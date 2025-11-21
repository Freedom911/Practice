#pragma once
#include "VehicleBase.h"
#include "VehicleEnum.h"
#include "CarVehicle.h"
#include "BikeVehicle.h"
#include "SUVVehicle.h"


class VehicleCreator
{
    public:

    VehicleBase *CreateVehicle(std::string vehicleNum,VehicleEnum type)
    {
        if(type == VehicleEnum::CAR)
        {
            return new CarVehicle(vehicleNum);
        }
        else if(type == VehicleEnum::BIKE)
        {
            return new BikeVehicle(vehicleNum);
        }
        else
        {
            return new SUVVehicle(vehicleNum);
        }
    }
};

