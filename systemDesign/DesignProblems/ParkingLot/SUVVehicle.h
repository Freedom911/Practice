#pragma once

#include "VehicleBase.h"
#include "VehicleEnum.h"
#include <string>

class SUVVehicle:public VehicleBase
{

    public:
    SUVVehicle(std::string vehicle):VehicleBase(vehicle){}

    VehicleEnum GetVehicleType() override
    {
        return VehicleEnum::SUV;
    }
} ;