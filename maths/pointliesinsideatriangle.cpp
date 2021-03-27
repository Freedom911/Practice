//Check Whether a point lies inside a triangle
//The Approach here is we find area fromt the point
//to all other vertices and sum them up and
//compare with main triangle if it is qual then it lies inside


//Area of triangle with three points
//(Ax(By-Cy) + Bx(Cy-Ay) + Cx(Ay-By))/2


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

//Area of Triangle b * h * 1/2

float findArea(const Point &A,const Point &B,const Point &C)
{
  float area =(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y))/2;
  return area;
}

bool checkPointLies(const Point &A,const Point &B,const Point &C,const Point P)
{
  
  float totalArea = findArea(A,B,C);
  float area1 = findArea(P,A,B);
  float area2 = findArea(P,B,C);
  float area3 = findArea(P,A,C);

  std::cout << "\n Total Area = " << totalArea ;
  std::cout << "\n Total Area1 = " << area1 ;
  std::cout << "\n Total Area2 = " << area2 ;
  std::cout << "\n Total Area3 = " << area3 ;

  return (totalArea == (area1 + area2 + area3)) ? true:false;

}

int main()
{
  Point A(0,0),B(10,30),C(20,0);
  Point P(10,100);

  if(checkPointLies(A,B,C,P))
    std::cout << "\n Point P = " << P << " lies inside the triangle" << A << " " << B << " " << C << "\n";
  else
    std::cout << "\n Point P = " << P << " Doesnt lies inside the triangle" << A << " " << B << " " << C << "\n";

}
