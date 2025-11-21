#pragma once
#include <string>
#include "VehicleEnum.h"

class ParkingSpace
{
    public:
    ParkingSpace(VehicleEnum parkingType)
    {
        g_parkingID++;
        m_currentParkingID = g_parkingID;
        m_parkingType = parkingType;
        m_isOccupied = false;
    }

    bool CanOccupyParking(VehicleEnum carType)
    {
        if(carType == m_parkingType && m_isOccupied == false)
        {
            m_isOccupied = true;
            return true;
        }
        else
        {
            return false;
        }
    }

    void ReleaseParking()
    {
        m_isOccupied = false;
    }

    int GetParkingID() const
    {
        return m_currentParkingID;
    }

    VehicleEnum GetParkingType() const
    {
        return m_parkingType;
    }

    bool IsOccupied() const
    {
        return m_isOccupied;
    }

    private:
    static int g_parkingID;
    int m_currentParkingID;
    VehicleEnum m_parkingType;
    bool m_isOccupied;

};

int ParkingSpace::g_parkingID = 0;