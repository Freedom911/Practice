//This is a target class which is responisble for defining the
//domain specifi interface. Here in this case domain is related to drawing
//so it contains drawing realted code
#pragma once

class ShapeTarget
{
  public:
    virtual void MoveShape(const int &x,const int &y) = 0;
};

