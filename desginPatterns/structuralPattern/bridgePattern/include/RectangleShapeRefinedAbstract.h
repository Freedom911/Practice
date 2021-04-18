//Refined Abstraction inheriting the abstract interface and 
//implements accordingly
#pragma once
#include "ShapeAbstract.h"

class RectangleShapeRefinedAbstract:public ShapeAbstract
{ 
  public:
    RectangleShapeRefinedAbstract(class ColorImplementor *ptr)
    {
      implementation = ptr;
    }

    void DrawShape();

    ~RectangleShapeRefinedAbstract()
    {

    }

  private:
    void DrawRectangle(const int &Length,const int &Width);
};
