#pragma once
#include <iostream>

//using static this is available only in this
//on removing static it will give multple definition error
static void fo()
{
  std::cout << "\n FO \n";
}

class A
{
  public:
    A();
    void foo()
    {
      fo();
      //std::cout << "\n A is Foo = " << i << "\n";
    }
};
