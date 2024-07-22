#pragma once
#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include <unordered_set>

class IphoneConcreteSubject : public Subject
{
  public:

  std::string GetProductName() override
  {
      return "Iphone Ultra Pulta Pro Max";
  }
  float GetDiscountPercentage() override
  {
      return 20.0;
  }
  float GetPrice() override
  {
      return 499999.1;
  }

};
