#include <iostream>
#include "ColorImplementor.h"
#include "CircleShapeRefinedAbstract.h"
#include <cmath>

void CircleShapeRefinedAbstract::DrawShape()
{
  std::cout << "\n Drawing Circle \n";
  DrawCircle(4);
}


//Not Important Part for this example
//Shamelessly taken from http://www.cplusplus.com/forum/beginner/62634/
void CircleShapeRefinedAbstract::DrawCircle(const int &circle_radius)
{
  std::string text;
  for (int i = 0; i <= 2*circle_radius; i++)
  {
    for (int j = 0; j <= 2*circle_radius; j++)
    {
      float distance_to_centre = sqrt((i - circle_radius)*(i - circle_radius) + (j - circle_radius)*(j - circle_radius));
      if (distance_to_centre > circle_radius-0.5 && distance_to_centre < circle_radius+0.5)
      {
        text += "*";
      }
      else
      {
        text+= " ";
      }
    }
    text += "\n";
  }

  std::string color = implementation->GetColorString(text);
  std::cout << color;
  std::cout << "\n\n";
}
