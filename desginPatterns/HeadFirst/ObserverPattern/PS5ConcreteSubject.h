#pragma once
#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include <unordered_set>

class PS5ConcreteSubject : public Subject
{
  public:

  std::string GetProductName() override
  {
      return "PS5 Pro GTA VI Bundle";
  }
  float GetDiscountPercentage() override
  {
      return 10.0;
  }
  float GetPrice() override
  {
      return 65000;
  }

};
