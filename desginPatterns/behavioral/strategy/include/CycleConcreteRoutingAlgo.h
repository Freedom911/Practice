//This is the concrete class implemneting the interface of strategy
#pragma once
#include "RoutingAlgoStrategy.h"

class CycleConcreteRoutingAlgo : public RoutingAlgoStrategy
{
  public:

    void BuildMinimumRoute() override;

    ~CycleConcreteRoutingAlgo()
    {

    }
};
