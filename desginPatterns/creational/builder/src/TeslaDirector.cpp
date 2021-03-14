#include <TeslaDirector.h>
#include <TeslaCarProduct.h>
#include <TeslaBuilder.h>

#include <Wheel.h>
#include <Battery.h>
#include <Body.h>

TeslaDirector::TeslaDirector()
{
  builder = NULL;
}

void TeslaDirector::setTeslaBuilder(TeslaBuilder *builder)
{
 this->builder = builder;
}

TeslaCarProduct *TeslaDirector::manufactureCar()
{
  if(builder == NULL)
    return NULL;

  TeslaCarProduct *freshCar = new TeslaCarProduct();
  freshCar->wheels = builder->createWheels();
  freshCar->battery = builder->createBattery();
  freshCar->body = builder->createBody();
  freshCar->modelName = builder->getModelName();

  return freshCar;

}

