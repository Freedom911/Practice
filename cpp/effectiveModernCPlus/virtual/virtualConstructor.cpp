#include <iostream>
class A
{
  public:
    virtual A() //error as no flag except inline is allowed
    {
      std::cout << "\n VIRTUAL CONSTRUCTOR \n";
    }
};
int main()
{
  A a;
}
