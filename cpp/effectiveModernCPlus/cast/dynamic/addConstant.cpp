//Dynamic Cast can be used to add constantness static cast can do same
//but dynamic cast only works which classes


#include <iostream>

class A
{
  public:
    virtual void foo() const
    {
      std::cout << "\n A is FOO \n";

    }
};

class B:public A
{
  public:
    void foo() const
    {
      std::cout << "\n B is FOO \n";
    }
};


int main()
{
  int k = 10;
  //Dynamic cast wont work with normal primitive data type
  //const int j = dynamic_cast<const int*>(i);
  
  B*b = new B();

 const B*c = dynamic_cast<const B*>(b);
 if(c)
 {
   c->foo();
 }

 //Static Cast also works but doesn't do additional checks
 //as compared to dynamic cast 
 const B*d = static_cast<const B*>(b);
 d->foo();

  //This works also
  //const int &j = static_cast<const int&>(i);
}
