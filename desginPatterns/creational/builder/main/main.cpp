#include <iostream>
#include <TeslaCarProduct.h>
#include <chrono>
#include <thread>
#include <TeslaDirector.h>
#include <TeslaModelEConcreteBuilder.h>
#include <TeslaModelSConcreteBuilder.h>
#include <Body.h>

int main()
{

  std::cout << "\n========================== Welcome To Tesla Factory.==========================\n";

  while(true)
  {
    std::cout << "\n This Factory is able to Build Model S and Model E. Choose anyone of them ";
    std::cout << "\n1. Model S\n2. Model E\n3. Exit Building\n";
    int ch;
    std::cin >> ch;

    if(ch != 1 && ch != 2)
    {
      break;
    }
 
    TeslaCarProduct *finalCarProduct = NULL;
    TeslaModelSConcreteBuilder *modelS = NULL;
    TeslaModelEConcreteBuilder *modelE = NULL;
    TeslaDirector director;


    //Model S
    if(ch == 1)
    {
      modelS = new TeslaModelSConcreteBuilder;
      director.setTeslaBuilder(modelS);
    }
    //Model E
    else if(ch == 2)
    {
      modelE = new TeslaModelEConcreteBuilder;
      director.setTeslaBuilder(modelE);
    }

    std::cout << "\n Manufacturing Car. DON'T PANIC \n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    finalCarProduct = director.manufactureCar();

    std::cout << "\n Model Manufactured .Following are the Specs \n";
    finalCarProduct->printSpecification();

    delete finalCarProduct;
    delete modelS;
    delete modelE;

  }


  std::cout << "\n ============================FINISH ============================\n";

}
