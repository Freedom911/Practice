//Creator Class - This is an interface which caontains method to interact
//with products remember client doesnt interact with product directly
//Sub class will define the methods


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DBInterfaceProduct.h"

class DBCreator
{ 
  public:
     void runQuery(const std::string &query);
     virtual ~DBCreator()
     {

     }

  protected:

     virtual DBInterfaceProduct *getProduct() = 0;

  
};
