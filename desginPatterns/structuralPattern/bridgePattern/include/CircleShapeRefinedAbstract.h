//Refined Abstraction inheriting the abstract interface and 
//implements accordingly
#pragma once
#include "ShapeAbstract.h"

class CircleShapeRefinedAbstract:public ShapeAbstract
{ 
  public:
    CircleShapeRefinedAbstract(class ColorImplementor *ptr)
    {
      implementation = ptr;
    }

    void DrawShape();

    ~CircleShapeRefinedAbstract()
    {

    }

  private:
    void DrawCircle(const int &radius);

};
