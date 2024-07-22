#pragma once
#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include <unordered_set>

class SonyTVConcreteSubject : public Subject
{
  public:

  std::string GetProductName() override
  {
      return "Sony Bravia 95 inch";
  }
  float GetDiscountPercentage() override
  {
      return 20.0;
  }
  float GetPrice() override
  {
      return 1999999;
  }

};
