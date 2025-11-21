#pragma once

#include "VehicleBase.h"
#include "VehicleEnum.h"
#include <string>

class BikeVehicle:public VehicleBase
{

    public:
    BikeVehicle(std::string vehicle):VehicleBase(vehicle){}

    VehicleEnum GetVehicleType() override
    {
        return VehicleEnum::BIKE;
    }
} ;