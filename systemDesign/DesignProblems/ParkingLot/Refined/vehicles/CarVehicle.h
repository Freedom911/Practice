#pragma once

#include "VehicleBase.h"
#include "VehicleEnum.h"
#include <string>

class CarVehicle:public VehicleBase
{

    public:
    CarVehicle(std::string vehicle):VehicleBase(vehicle){}

    VehicleEnum GetVehicleType() override
    {
        return VehicleEnum::CAR;
    }
} ;