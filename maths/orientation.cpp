//Check Whether Three points are clockwise anti clockwise or colinear
//Idea here is to use sloes
//if slope of p1 and p2 is greater than p2 and p3 then its clocwise


#include <iostream>
struct Point
{
  int x;
  int y;

  Point(int a,int b)
  {
    x = a;
    y = b;
  }
};

std::ostream & operator << (std::ostream &out,const Point &P)
{
  out << "(" <<  P.x << "," << P.y << ")" ;
  return out;

}

void checkOrientation(const Point &A,const Point &B,const Point &C)
{
  float slope1 = (B.y - A.y)/(B.x - A.x);
  float slope2 = (C.y - B.y)/(C.x - B.x);

   //clockwise
  if(slope1 - slope2 > 0)
  {
    std::cout << "\n CLOCKWISE \n";
  }
  else if(slope1 - slope2 < 0)
  {
    std::cout << "\n ANTI CLOCKWISE \n";
  }
  else
  {
    std::cout << "\n COLINEAR \n";
  }

}


int main()
{
  Point A(0,0),B(10,30),C(20,0);
  checkOrientation(A,B,C);
}
