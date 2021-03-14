#include <TeslaModelEConcreteBuilder.h>


std::vector<Wheel*> TeslaModelEConcreteBuilder::createWheels()
{
  std::vector<Wheel*>vec;
  for(int i = 0; i < 4; i++)
  {
    Wheel *wheel = new Wheel(20);
    vec.push_back(wheel);
  }

  return vec;
}

Battery *TeslaModelEConcreteBuilder::createBattery()
{
  return new Battery(20);
}

Body *TeslaModelEConcreteBuilder::createBody()
{
  return new Body(100,200);
}

std::string TeslaModelEConcreteBuilder::getModelName()
{
  return "Tesla Model E";
}
