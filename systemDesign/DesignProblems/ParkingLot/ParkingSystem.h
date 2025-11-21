#pragma once
#include "VehicleBase.h"
#include "Level.h"
#include "VehicleEnum.h"
#include "TokenDetails.h"
#include "PaymentCreator.h"
#include "PaymentStrategy.h"
#include <string>
#include <vector>
#include <unordered_map>

class ParkingSystem
{

public:
    static ParkingSystem &GetInstance()
    {
        static ParkingSystem g_ParkingSystem;
        return g_ParkingSystem;
    }

    void Initialize()
    {
        std::vector<VehicleEnum> parkingTypes{VehicleEnum::CAR, VehicleEnum::CAR, VehicleEnum::CAR, VehicleEnum::SUV, VehicleEnum::SUV};
        m_levels.push_back({"Basement", parkingTypes});

        std::vector<VehicleEnum> parkingTypes1{VehicleEnum::CAR, VehicleEnum::SUV, VehicleEnum::BIKE, VehicleEnum::BIKE, VehicleEnum::BIKE};
        m_levels.push_back({"First Floor", parkingTypes1});

        PaymentCreator creator;
        m_payMethod = creator.CreatePaymentMethod(PaymentType::VARIABLE);

        // Can Add mOre
    }

    bool ParkVehicle(VehicleBase *vehicle, std::string time)
    {
        if (vehicle == nullptr)
        {
            return false;
        }
        int parkingID = 0;
        std::string LevelName;
        TokenDetails details;
        for (Level &level : m_levels)
        {
            if (m_parkingInfo.find(vehicle->GetVehicleNum()) == m_parkingInfo.end() &&
                level.GetFreeParking(vehicle->GetVehicleType(), parkingID, LevelName))
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

    int UnParkVehicle(VehicleBase *vehicle, std::string time)
    {
        if (vehicle == nullptr || m_parkingInfo.find(vehicle->GetVehicleNum()) == m_parkingInfo.end())
        {
            return 0;
        }

        std::string vehicleNum = vehicle->GetVehicleNum();

        m_parkingInfo[vehicleNum].OutTime = time;
        m_payMethod->CalculateCost(m_parkingInfo[vehicleNum]);
        std::cout << "\n PLEASE PAY = " << m_parkingInfo[vehicleNum].TotalPayment << "\n";
		int cost = m_parkingInfo[vehicleNum].TotalPayment;

        for (Level &level : m_levels)
        {
            if(level.GetLevelName() == m_parkingInfo[vehicleNum].levelName)
            {
                level.ReleaseParking(m_parkingInfo[vehicleNum].ParkingID);
            }
        }

        m_parkingInfo.erase(vehicleNum);

        return cost;
    }

    ParkingSystem(const ParkingSystem &obj) = delete;
    ParkingSystem &operator=(const ParkingSystem &obj) = delete;

private:
    ParkingSystem() = default;
    std::vector<Level> m_levels;
    std::unordered_map<std::string, TokenDetails> m_parkingInfo;
    PaymentStrategy *m_payMethod;
};