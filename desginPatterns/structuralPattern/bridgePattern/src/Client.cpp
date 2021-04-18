#include "Client.h"
#include "ShapeAbstract.h"
#include "ColorImplementor.h"
#include "BlueColorConcreteImplementor.h"
#include "RedColorConcreteImplementor.h"
#include "RectangleShapeRefinedAbstract.h"
#include "CircleShapeRefinedAbstract.h"
#include <algorithm>

Client::Client(std::string color,std::string shape)
{
  transform(color.begin(), color.end(), color.begin(), ::toupper);
  transform(shape.begin(), shape.end(), shape.begin(), ::toupper);

  if(color == "RED")
    Color = new RedColorConcreteImplementor();
  else
    Color = new BlueColorConcreteImplementor();

  if(shape == "RECTANGLE")
    Shape = new RectangleShapeRefinedAbstract(Color);
  else
    Shape = new CircleShapeRefinedAbstract(Color);

}

void Client::StartDrawing()
{
  Shape->DrawShape();
}

Client::~Client()
{
  delete Shape;
  Shape = NULL;
  delete Color;
  Color = NULL;
}

