//Check if two rectnagles overlap
//Two rectnagles overlap if top left y coordinate of one rectangble
//is greater than bottom right y coordinate of rectnagle and
//top left x coordinate is less than bottom right x coordinate
#include <iostream>
struct Rectangle
{
  int topLeftX;
  int topLeftY;
  int bottomRightX;
  int bottomRightY;

  Rectangle(int x,int y,int x1,int y1)
  {
    topLeftX = x;
    topLeftY = y;
    bottomRightX = x1;
    bottomRightY = y1;
  }

};

bool checkOverlap(const Rectangle &rect1,const Rectangle &rect2)
{
   if(rect1.topLeftY < rect2.bottomRightY || rect2.topLeftY < rect1.bottomRightY)
     return false;

   if(rect1.topLeftX > rect2.bottomRightX || rect2.topLeftX > rect1.bottomRightX)
     return false;

   return true;


}

int main()
{
  Rectangle r1{2,2,4,0};
  Rectangle r2{2,2,4,0};
  //Rectangle r2{3,4,6,1};
  std::cout << "\n DO THEY OVERLAP = " << checkOverlap(r1,r2) << "\n";
}
