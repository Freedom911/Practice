//This is a Product Interface Class which contains methods
//that needs to be defined in subclasses

#pragma once
#include <iostream>
#include <string>
#include <vector>

class DBInterfaceProduct
{
  public:

    virtual void executeQuery(const std::string &query) = 0;
    virtual std::vector<int> getResult() = 0;
    virtual int getTotalRowCount() = 0;
    virtual ~DBInterfaceProduct() 
    {

    }

  protected:
    std::vector<int> result;

};
