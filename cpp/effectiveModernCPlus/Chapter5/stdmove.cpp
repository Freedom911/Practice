#include <iostream>

class A
{
  public:
    A()
    {
      std::cout << "\n A Constructor \n";
    }
    A(const A&a)
    {
      std::cout << "\n A is copy Constructor \n";
    }
    A(A&&a)
    {
      std::cout << "\n A is MOVE Constructor \n";
    }
};

class B
{
  public:
    B(const A obj):value(std::move(obj)) //this wont call move constructor. because the result is rvalue of const A obj. and move constructor is without const
    {
      std::cout << "\n B Constructor \n";
    }

    A value;
};
int main()
{
  A a;
  B b(a);

}

