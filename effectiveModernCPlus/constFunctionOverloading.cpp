#include <iostream>

#if 0 //this class will give error as const argument without reference or pointer are not allowed
class A
{
  public:
    void foo(const int i)
    {
      std::cout << "\n Const FOO \n";
    }
    void foo( int i)
    {
      std::cout << "\n Normal FOO \n";
    }

};
#endif

//will compile
class AB
{
  public:
    void foo(int i) const
    {
      std::cout << "\n Const Member FOO \n";
    }
    void foo( int i)
    {
      std::cout << "\n Normal FOO \n";
    }

};

class ABC
{
  public:
    void foo(const int &i) 
    {
      std::cout << "\n Const Reference FOO \n";
    }
    void foo( int &i)
    {
      std::cout << "\n Normal FOO \n";
    }

};

//also works
class ABCD
{
  public:
    void foo(int &i) 
    {
      std::cout << "\n Reference FOO \n";
    }
    void foo(int i)
    {
      std::cout << "\n Normal FOO \n";
    }

};
int main()
{
  AB a;
  a.foo(3); //cals normall foo
  const AB aa;
  aa.foo(3); //calls const mem foo

  ABC ac;
  ac.foo(3); //this calls const reference foo

  ABCD d;
  d.foo(4);

}
