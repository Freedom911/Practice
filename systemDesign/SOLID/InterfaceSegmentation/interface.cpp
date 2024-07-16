#include <iostream>

//example of class breaking interface segmentation principle
class Vehicle
{
    public:
        virtual void StartEngine() = 0;
        virtual void StopEngine() = 0;
        virtual void Move(int x,int y) = 0;
        virtual void ShiftGear(int gearNo) = 0;

};

class Bike:public Vehicle
{
    public:
        void StartEngine()
        {
            std::cout << "\n Engine of Bike is starting Up \n";
        }
        void StopEngine()
        {
            std::cout << "\n Engine of Bike is stopping \n";
        }
        void Move(int x,int y)
        {
            std::cout << "\n Moving = " << x << " " << y << "\n";
        }
        void ShiftGear(int gearNo)
        {
            std::cout << "\n Shifting gear to = " << gearNo << "\n";
        }


};

//Here Cycle is having functions from interface that need not be implemented in cycle class
class Cycle:public Vehicle
{
    public:
        void StartEngine()
        {
            //Not applicable
        }
        void StopEngine()
        {
            //Not applicable
        }
        void Move(int x,int y)
        {
            std::cout << "\n Moving = " << x << " " << y << "\n";
        }
        void ShiftGear(int gearNo)
        {
            //Not applicable
        }
};

//solutions

class VehicleUpdated
{
    public:
        virtual void Move(int x,int y) = 0;

};

class MotorVehicleUpdated : public VehicleUpdated
{
    public:
        virtual void StartEngine() = 0;
        virtual void StopEngine() = 0;
        virtual void ShiftGear(int gearNo) = 0;

};

class NonMotorVehicleUpdated : public VehicleUpdated
{
    public:
        virtual void StartPedalling() = 0;
        virtual void StopPedalling() = 0;
};

class MotorCycleUpdated:public MotorVehicleUpdated
{
    public:
        void StartEngine()
        {
            std::cout << "\n Engine of Bike is starting Up \n";
        }
        void StopEngine()
        {
            std::cout << "\n Engine of Bike is stopping \n";
        }
        void Move(int x,int y)
        {
            std::cout << "\n Moving = " << x << " " << y << "\n";
        }
        void ShiftGear(int gearNo)
        {
            std::cout << "\n Shifting gear to = " << gearNo << "\n";
        }
};

class CycleUpdated:public NonMotorVehicleUpdated
{
    public:
        void StartPedalling()
        {
            std::cout << "\n Pedalling quickly \n";
        }
        void StopPedalling()
        {
            std::cout << "\n Stop pedalling\n";
        }
        void Move(int x,int y)
        {
            std::cout << "\n Moving = " << x << " " << y << "\n";
        }
};

int main()
{

}
