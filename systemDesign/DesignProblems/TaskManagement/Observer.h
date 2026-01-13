#pragma once
#include <iostream>

class Observer
{
  public:
  virtual void Update(std::string message) = 0;
};

