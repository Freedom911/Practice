//Concrete Product for Oracle database 
//Contains Exactly How oracle manages connection
//inherits DBInterface Product
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DBInterfaceProduct.h"

class OracleDBConcreteProduct:public DBInterfaceProduct
{
  public:

     void executeQuery(const std::string &query);
     std::vector<int> getResult() ;
     int getTotalRowCount();
     ~OracleDBConcreteProduct()
     {
       std::cout << "\n Shutting Down Client Connection to ORACLE Server \n";
     }

};



