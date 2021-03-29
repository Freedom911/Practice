//Concrete Product for PSQL database 
//Contains Exactly How PSQL manages connection
//inherits DBInterface Product
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DBInterfaceProduct.h"

class PSQLDBConcreteProduct:public DBInterfaceProduct
{ 
  public:
    
     void executeQuery(const std::string &query);
     std::vector<int> getResult() ;
     int getTotalRowCount();
     ~PSQLDBConcreteProduct()
     {
       std::cout << "\n Shutting Down Client Connection to PSQL Server \n";
     }
  
};
