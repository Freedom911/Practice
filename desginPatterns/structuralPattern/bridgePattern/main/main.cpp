#include <iostream>
#include "Client.h"

int main()
{
  Client cl("Red","Circle");
  Client cl1("Blue","Circle");
  cl.StartDrawing();
  cl1.StartDrawing();
  Client cl2("Red","Rectangle");
  Client cl3("Blue","Rectangle");
  cl2.StartDrawing();
  cl3.StartDrawing();
}
