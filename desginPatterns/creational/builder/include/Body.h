#pragma once
#include <iostream>

class Body
{
  public:

    Body(int h,int w):height(h),width(w){}

    void getBodyDetails(int &h,int &w);

  private:
    int height,width;
};
