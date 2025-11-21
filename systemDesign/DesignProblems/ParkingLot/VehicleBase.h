#pragma once
#include "VehicleEnum.h"
#include <string>
class VehicleBase
{
    public:
    VehicleBase(std::string VehicleNum)
    {
        m_vehicleNum = VehicleNum;
    }

    std::string GetVehicleNum()
    {
        return m_vehicleNum;
    }

    virtual VehicleEnum GetVehicleType() = 0;


    protected:
    std::string m_vehicleNum;

};