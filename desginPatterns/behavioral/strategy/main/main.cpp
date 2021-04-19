#include <iostream>
#include "BuildRouteContext.h"
#include "CarConcreteRoutingAlgo.h"
#include "CycleConcreteRoutingAlgo.h"

int main()
{
  int op;
  std::cout << "\n Do You want to use 1.Cycle or 2.Car Enter 1/2 \n";
  std::cin >> op;

  if(op == 1)
  {
    BuildRouteContext obj(new CycleConcreteRoutingAlgo);
    obj.BuildRoute();
  }
  else if (op == 2)
  {
    BuildRouteContext obj(new CarConcreteRoutingAlgo);
    obj.BuildRoute();
  }
  else
  {
    std::cout << "\n No Valid OPtion Choosen\n";
  }

}
