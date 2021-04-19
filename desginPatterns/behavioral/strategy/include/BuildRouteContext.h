//This is the class which interacts with the strategy class for the particular
//algorithm using composition.It keeps a reference to strategy class
#pragma once

class BuildRouteContext
{

  public:
    BuildRouteContext(class RoutingAlgoStrategy *ptr);

    void BuildRoute();

    ~BuildRouteContext();

  private:
    class RoutingAlgoStrategy* m_ptr;
};
