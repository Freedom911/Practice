//This is the concrete class implemneting the interface of strategy
#pragma once
#include "RoutingAlgoStrategy.h"

class CarConcreteRoutingAlgo : public RoutingAlgoStrategy
{
  public:

    void BuildMinimumRoute() override;

    ~CarConcreteRoutingAlgo()
    {

    }
};
