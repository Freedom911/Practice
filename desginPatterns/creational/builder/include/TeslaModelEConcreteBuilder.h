#pragma once
#include <TeslaBuilder.h>
#include <Wheel.h>
#include <Battery.h>
#include <Body.h>
#include <vector>
//Concrete Builder Class For Model E

class TeslaModelEConcreteBuilder:public TeslaBuilder
{
  public:
    virtual std::vector<Wheel*> createWheels();
    virtual Battery* createBattery();
    virtual Body *createBody();
   
    virtual std::string getModelName();

};
