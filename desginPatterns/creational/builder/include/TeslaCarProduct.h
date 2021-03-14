#pragma once
#include <vector>
#include <string>

class TeslaCarProduct
{

  public:

    void printSpecification();

    std::vector<class Wheel*> wheels;
    class Battery *battery;
    class Body *body;
    std::string modelName;
};
