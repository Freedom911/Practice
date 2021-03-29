//Creator Class - Concrete class for creating Oracle Creator


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DBInterfaceProduct.h"
#include "DBCreator.h"

class OracleCreator:public DBCreator
{ 
  public:
    ~OracleCreator()
    {

    }
  protected:

     DBInterfaceProduct *getProduct();

  
};
