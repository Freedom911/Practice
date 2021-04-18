//concrete class implementor that inherits the implementation interface
#pragma once
#include "ColorImplementor.h"
#include <string>

class RedColorConcreteImplementor:public ColorImplementor
{
  public:
    std::string GetColorString(const std::string &field) ;
    ~RedColorConcreteImplementor()
    {

    }
};
