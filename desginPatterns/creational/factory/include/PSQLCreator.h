//Creator Class - Concrete class for creating PSQL product


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DBInterfaceProduct.h"
#include "DBCreator.h"

class PSQLCreator:public DBCreator
{ 
  public:
    ~PSQLCreator()
    {
     
    }

  protected:

     DBInterfaceProduct *getProduct();

  
};
