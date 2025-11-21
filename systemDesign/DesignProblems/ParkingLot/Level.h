#pragma once

#include "VehicleEnum.h"
#include "ParkingSpace.h"
#include <vector>
#include <iostream>

//The Class maintains list of Parking Spaces
//and exposes function to ParkingSystem
class Level
{
    public:
    Level(std::string LevelName,std::vector<VehicleEnum> & totalParkingSpaces)
    {
        m_levelName = LevelName;
        std::cout << "\n Creating = " << LevelName << " With Total Parking = " << totalParkingSpaces.size() << "\n";
        for(VehicleEnum &details : totalParkingSpaces )
        {
            m_totalParkingSpaces.push_back(ParkingSpace(details));
        }
    }

    bool GetFreeParking(VehicleEnum carType,int &ParkingID,std::string &LevelName)
    {
        for(ParkingSpace &obj : m_totalParkingSpaces)
        {
            if(obj.CanOccupyParking(carType))
            {
                ParkingID =  obj.GetParkingID();
                LevelName = m_levelName;
                return true;
            }
        }
        return false;
    }

    void ReleaseParking(int ParkingID)
    {
       for(ParkingSpace &obj : m_totalParkingSpaces)
        {
            if(obj.GetParkingID() == ParkingID)
            {
                std::cout << "\n PARKING = " << ParkingID << " EMPTY \n";
                obj.ReleaseParking();
            }
        } 
    }

    std::string GetLevelName() const
    {
        return m_levelName;
    }


    private:

    std::vector<ParkingSpace> m_totalParkingSpaces;
    std::string m_levelName;

};