#include <iostream>
#include <TeslaCarProduct.h>
#include <Wheel.h>
#include <Battery.h>
#include <Body.h>


void TeslaCarProduct::printSpecification()
{
  std::cout << "\n ================================= Model = " << modelName << "================================= \n";
  std::cout << "\n Total Wheels = " << wheels.size() << "\n";

  std::cout << "\n Wheel Size = ";
  for(Wheel*wheel:wheels)
  {
    std::cout  << wheel->getWheelSize() << ",";
  }

  int width = -1,height = -1;

  if(body)
  {
    body->getBodyDetails(width,height);
    std::cout << "\n Body Height in cm = " << height ;
    std::cout << "\n Body Width in cm = " << width;
  }


  std::cout << "\n Battery Wattage = " << battery->getBatteryWatt() << "\n";

}
