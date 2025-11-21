#pragma once
#include <string>
#include "VehicleEnum.h"

struct TokenDetails
{
    std::string vehicleNumber;
    std::string InTime;
    std::string OutTime;
    std::string levelName;
    int TotalPayment;
    int ParkingID;
    VehicleEnum vehicleType;
    


    TokenDetails()
    {
        vehicleNumber = "";
        InTime = "";
        OutTime = "";
        levelName = "";
        vehicleType = VehicleEnum::CAR;
        TotalPayment = 0;
        
    }
};