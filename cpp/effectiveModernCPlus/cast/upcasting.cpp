//Upcasting is a process of converting a derived class pointer to a parent class
//Upcasting helps in making programs generic

#include <iostream>


class Shape
{
  public:
    //Need to make sure it is virtual
    virtual void draw() 
    {
      std::cout << "\n Drawing Base Shape \n";
    }
};

class Rectangle:public Shape
{

  public:
    virtual void draw() 
    {
      std::cout << "\n Drawing Rectangle\n";
    }
};

class Square:public Shape
{

  public:
    virtual void draw() 
    {
      std::cout << "\n Drawing Square \n";
    }
};

//here rectanble or square will be treated as  shape
void start(Shape &s)
{
  s.draw();
}

int main()
{
  Rectangle rect;
  Square square;
  start(rect);
  start(square);
}
