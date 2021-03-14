#include <TeslaModelSConcreteBuilder.h>


std::vector<Wheel*> TeslaModelSConcreteBuilder::createWheels()
{
  std::vector<Wheel*>vec;
  for(int i = 0; i < 6; i++)
  {
    Wheel *wheel = new Wheel(50);
    vec.push_back(wheel);
  }

  return vec;
}

Battery *TeslaModelSConcreteBuilder::createBattery()
{
  return new Battery(90);
}

Body *TeslaModelSConcreteBuilder::createBody()
{
  return new Body(500,900);
}

std::string TeslaModelSConcreteBuilder::getModelName()
{
  return "Tesla Model S";
}
