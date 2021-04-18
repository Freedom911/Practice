#include <iostream>
#include "ColorImplementor.h"
#include "RectangleShapeRefinedAbstract.h"

void RectangleShapeRefinedAbstract::DrawShape()
{

  std::cout << "\n Drawing Rectangle \n";

  DrawRectangle(8,5);

}
    
void RectangleShapeRefinedAbstract::DrawRectangle(const int &Length,const int &Width)
{
  std::string text;
  for(int i = 0; i < Width; i++)
  {
    for(int j = 0; j < Length; j++)
    {
      text += "*";
    }
    text += "\n";
  }

  std::string color = implementation->GetColorString(text);
  std::cout << color;
  std::cout << "\n\n";
}
