#include <iostream>

//Example of class breaking liskov substitution
class MotorVehicle
{
    public:
    virtual void StartEngine()
    {
        std::cout << "\n Start Engine \n";
    }

    virtual void Move()
    {
        std::cout << "\n Moving Vehicle\n";
    }
};

class Cycle:public MotorVehicle
{
    public:
    void Move() override
    {
        std::cout << "\n Moving Cycle \n";
    }

    //this give exception and is breaking the functionality
    void StartEngine() override
    {
        //not applicable
        throw "not applicable";
    }

};

void StartProcessing(MotorVehicle &v)
{
   v.StartEngine();
   v.Move();
}

//SOlution 
//is we divide into multiple interfaces
class VehicleUpdated
{
   public:

};

class MotorVehicleUpdated:public VehicleUpdated
{

};

class NonMotorVehicle:public VehicleUpdated
{

};

class CycleUpdated : public NonMotorVehicle
{

};

class Bike: public MotorVehicleUpdated
{

};


int main()
{
  Cycle c;
  StartProcessing(c);//upcasting
}
