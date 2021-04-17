#include<iostream>

class A
{
  public:
    A()
    {

    }
    //in c++ 11 cannot throw at all
    ~A()
    {
      throw 42;
    }
};

int main()
{
  try
  {
    A a;
    throw 32;
  }
  catch(int a)
  {
    std::cout << a << "\n";
  }
}
