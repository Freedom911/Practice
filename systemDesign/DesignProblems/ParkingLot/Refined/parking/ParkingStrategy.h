#pragma once

// Base Class FOr Handing Vehicle Parking Algo
#include "TokenDetails.h"
#include "Level.h"
#include "PaymentStrategy.h"
#include "VehicleBase.h"
#include <unordered_map>

class ParkingStrategy
{
public:
    // Return true if vehicle Parked false otherwise
    virtual bool ParkVehicle(VehicleBase *vehicle, std::string time,std::vector<Level> &level) = 0;

    bool UnParkVehicle(VehicleBase *vehicle,std::string time, TokenDetails &details,std::vector<Level> &levels)
    {   
         if (vehicle == nullptr || m_parkingInfo.find(vehicle->GetVehicleNum()) == m_parkingInfo.end())
        {
            return false;
        }

        std::string vehicleNum = vehicle->GetVehicleNum();
        details = m_parkingInfo[vehicleNum];

        details.OutTime = time;
       
        for (Level &level : levels)
        {
            if(level.GetLevelName() == m_parkingInfo[vehicleNum].levelName)
            {
                level.ReleaseParking(m_parkingInfo[vehicleNum].ParkingID);
                m_parkingInfo.erase(vehicleNum);
                return true;
            }
        }

        return false;

    }

    protected:
    std::unordered_map<std::string, TokenDetails> m_parkingInfo;
};
