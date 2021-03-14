#pragma once
#include <TeslaBuilder.h>
//Concrete Builder Class For Model S

class TeslaModelSConcreteBuilder:public TeslaBuilder
{
  public:
    virtual std::vector<Wheel*> createWheels();
    virtual Battery* createBattery();
    virtual Body *createBody();
    
    virtual std::string getModelName();

};
