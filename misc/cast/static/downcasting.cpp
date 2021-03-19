//We can use static cast for downcasting but it is not safe
//and its better to use dynamic cast which performs additional tests and returns a pointer if valid
//else null using RTII
#include <iostream>

class A
{
public:
   void hello()
  {
    std::cout << "\n A is HELLOW \n";
  }
};

class B:public A
{

public:
  void hello()
  {
    std::cout << "\n B is HELLOW \n";
  }
};

int main()
{
  B b;
  A &a = b; //Upcastingn implicit
  //A &a = static_cast<A&>(b); //Can also be used in upcasting

  a.hello(); // will print Bs

  //To DO DOWNCASTING i.e from parent to child
   //B b1  = a;//will give error
   B &b1 = static_cast<B&>(a);

   b1.hello();

}
