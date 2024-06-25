//Object Splicing Happens in case of upcasting when we 
//dont use pointer or reference

#include <iostream>


class Shape
{
  public:
    virtual void draw() 
    {
      std::cout << "\n Drawing Base Shape \n";
    }
};

class Rectangle:public Shape
{

  public:
    void draw() 
    {
      std::cout << "\n Drawing Rectangle\n";
    }
};

class Square:public Shape
{

  public:
    void draw() 
    {
      std::cout << "\n Drawing Square \n";
    }
};

//IMPORTANT
//OBJECT SLICING WILL HAPPEN HERE
void start(Shape s)
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
