#pragma once

#include "ParkingStrategy.h"

class ClosestParking : public ParkingStrategy
{
public:
    bool ParkVehicle(VehicleBase *vehicle, std::string time, std::vector<Level> &levels) override
    {
        TokenDetails details;

        if (vehicle == nullptr)
        {
            return false;
        }
        int parkingID = 0;
        std::string LevelName;
        for (Level &level : levels)
        {
            if (level.GetFreeParking(vehicle->GetVehicleType(), parkingID, LevelName))
            {
                details.ParkingID = parkingID;
                details.InTime = time;
                details.levelName = LevelName;
                details.vehicleNumber = vehicle->GetVehicleNum();
                details.vehicleType = vehicle->GetVehicleType();

                m_parkingInfo[details.vehicleNumber] = details;

                std::cout << "\n CAR = " << vehicle->GetVehicleNum();
                std::cout << " PARKED AT LEVEL = " << details.levelName;
                std::cout << " AT SPACE = " << parkingID << "\n";

                return true;
            }
        }

        std::cout << "\n SPACE FULL PLEASE WAIT \n";

        return false;
    }
};