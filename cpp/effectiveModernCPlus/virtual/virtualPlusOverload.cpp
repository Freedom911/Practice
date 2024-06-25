#include <iostream>

class A
{
  public:
     virtual void foo(int a)
    {
      std::cout << "\n A FOO " << a  << "\n";
    }
    virtual void too(int a,int b=100)
    {
      std::cout << "\n A TOO " << a  << "\n";
    }
};

class B:public A
{
  public:
    virtual void foo(int a,int b)
    {
      std::cout << "\n FOO B  " << a << "\n";;
    }
     virtual void too(int a,int b = 10)
    {
      std::cout << "\n B TOO " << a << " " << b << "\n";
    }
};
int main()
{
  B b;
  A*a = &b;
  a->too(3); // calss b too 3 but with default argmuent of a i.e 100
}
