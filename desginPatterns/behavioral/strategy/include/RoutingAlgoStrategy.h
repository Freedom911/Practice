//This is aclass which provides the interface for the algorithm

#pragma once

class RoutingAlgoStrategy
{
  public:
    virtual void BuildMinimumRoute() = 0;
    virtual ~RoutingAlgoStrategy(){}
};

