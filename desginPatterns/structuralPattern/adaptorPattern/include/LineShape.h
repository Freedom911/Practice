//Normal Class inheirting Shape class
#pragma once
#include "ShapeTarget.h"

class LineShape:public ShapeTarget
{
  public:
  void MoveShape(const int&x,const int &y) override;
};
