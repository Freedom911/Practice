#pragma once
#include "VehicleBase.h"
#include "Level.h"
#include "VehicleEnum.h"
#include "TokenDetails.h"
#include "PaymentCreator.h"
#include "PaymentStrategy.h"
#include "ParkingStrategy.h"
#include "ParkingAlgoCreator.h"
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

        ParkingAlgoCreator algoCreator;
        m_parkingStrategy = algoCreator.CreateParkingAlgo(ParkingAlgoEnum::CLOSESTFIT);

        // Can Add mOre
    }

    bool ParkVehicle(VehicleBase *vehicle, std::string time)
    {
        return m_parkingStrategy->ParkVehicle(vehicle, time, m_levels);
    }

    int UnParkVehicle(VehicleBase *vehicle, std::string time)
    {
        TokenDetails details;
        if (m_parkingStrategy->UnParkVehicle(vehicle, time, details, m_levels))
        {
            m_payMethod->CalculateCost(details);
            std::cout << "\n PLEASE PAY = " << details.TotalPayment << "\n";
            return details.TotalPayment;
        }

        return -1;
    }

    ParkingSystem(const ParkingSystem &obj) = delete;
    ParkingSystem &operator=(const ParkingSystem &obj) = delete;

private:
    ParkingSystem() = default;
    std::vector<Level> m_levels;

    PaymentStrategy *m_payMethod;
    ParkingStrategy *m_parkingStrategy;
};