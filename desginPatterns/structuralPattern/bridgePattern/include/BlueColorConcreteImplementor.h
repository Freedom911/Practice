//concrete class implementor that inherits the implementation interface
#pragma once
#include "ColorImplementor.h"
#include <string>

class BlueColorConcreteImplementor:public ColorImplementor
{
  public:
    std::string GetColorString(const std::string &text) ;
    ~BlueColorConcreteImplementor()
    {

    }
};
