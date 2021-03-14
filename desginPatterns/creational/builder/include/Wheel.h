#pragma once

class Wheel
{
  public:
    Wheel(int size):wheelSize(size){}
    int getWheelSize();
  private:
    int wheelSize;
};
