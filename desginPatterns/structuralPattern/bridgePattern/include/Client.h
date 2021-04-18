//Client Class Which is responsible for interacting with implementation
#pragma once
#include "BlueColorConcreteImplementor.h"
#include "RedColorConcreteImplementor.h"
#include "RectangleShapeRefinedAbstract.h"
#include "CircleShapeRefinedAbstract.h"

class Client
{
  public:
    Client(std::string color,std::string shape);

    void StartDrawing();

    ~Client();

    class ShapeAbstract *Shape;
    class ColorImplementor *Color;
};
