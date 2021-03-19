//DOWNCASTING IS A WAY of converting parent object to child
//Not possible without casting

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

void startRectangle(Rectangle &s)
{
  s.draw();
}

int main()
{
  Shape *rectangle = new Rectangle();
  //startRectangle(rectangle); //GIVES ERROR
  Rectangle *rect = dynamic_cast<Rectangle*>(rectangle); // This is downcasting
  //Static Cast can also be used
  //Rectangle *rect = static_cast<Rectangle*>(rectangle); // This is downcasting
  if(rect)
    rect->draw();
}
