//Abstract Class which defines an interface for domain specific fields
#pragma once

#include "ColorImplementor.h"

class ShapeAbstract
{
  public:
    ShapeAbstract():implementation(NULL){}
    virtual void DrawShape() = 0;
    virtual ~ShapeAbstract() {};

  protected:
   class ColorImplementor *implementation;
};
