#pragma once

class Battery
{
  public:
    Battery(float watt):batteryWatt(watt) {}

    float getBatteryWatt() const;

  private:

    float batteryWatt;
};
