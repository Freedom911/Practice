#pragma once

#include <Wheel.h>
#include <Battery.h>
#include <Body.h>
#include <vector>
#include <string>

class TeslaBuilder
{
 public:
   virtual std::vector<Wheel*> createWheels(){std::vector<Wheel*> wheels;return wheels;}
   virtual Battery* createBattery(){return NULL;}
   virtual Body *createBody(){return NULL;}
   virtual std::string getModelName(){return "";};
};
