//Dnamic casting for upcasting and downcasting
#include <iostream>
class A
{
  public:
    virtual void foo()
    {
      std::cout << "\n A is FOO \n";
    }
};

class B:public A
{
  public:
    void foo()
    {
      std::cout << "\n B is FOO \n";
    }
};


int main()
{
  B b;
  //A &a = b;
  //upcasting using dnamic cast
  A &a = dynamic_cast<A&>(b);
  a.foo();
  B &d = dynamic_cast<B&>(a);
  d.foo();
}
