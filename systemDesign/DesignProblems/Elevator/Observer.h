#pragma once
#include <iostream>

class Observer
{
  public:
  virtual void Update(const int &elevatorid,const int &floor) = 0;
};
