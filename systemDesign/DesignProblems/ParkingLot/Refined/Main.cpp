#include <iostream>
#include <string>
#include "VehicleBase.h"
#include "VehicleCreator.h"
#include "ParkingSystem.h"

int main()
{
    ParkingSystem &system = ParkingSystem::GetInstance();
    system.Initialize();

    VehicleCreator creator;
    VehicleBase *vehicle1 = creator.CreateVehicle("UP9006123",VehicleEnum::CAR);
    system.ParkVehicle(vehicle1,"09:11:10");

    VehicleBase *vehicle2 = creator.CreateVehicle("VI1006123",VehicleEnum::SUV);
    system.ParkVehicle(vehicle2,"10:11:10");

    VehicleBase *vehicle3 = creator.CreateVehicle("DL1006123",VehicleEnum::SUV);
    system.ParkVehicle(vehicle3,"11:21:10");

    VehicleBase *vehicle4 = creator.CreateVehicle("HR1006123",VehicleEnum::SUV);
    system.ParkVehicle(vehicle4,"12:21:10");

    VehicleBase *vehicle5 = creator.CreateVehicle("UK1006123",VehicleEnum::SUV);
    system.ParkVehicle(vehicle5,"13:21:10");

    {
         int amount = system.UnParkVehicle(vehicle1,"11:10:10");
         std::cout << "\n PAYING = " << amount << "\n";
    }

    {
         int amount = system.UnParkVehicle(vehicle2,"11:10:10");
         std::cout << "\n PAYING = " << amount << "\n";
    }

    VehicleBase *vehicle6 = creator.CreateVehicle("AUK1006123",VehicleEnum::SUV);
    system.ParkVehicle(vehicle6,"14:21:10");



    

}