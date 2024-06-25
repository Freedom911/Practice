//LValue is an expression for which we can access the memory address
//xValue is an expression(eXpiring) which in the end of the lifecycle 
//we have rvalue reference for it
#include <iostream>
#include <string>
int main()
{
  std::string i = "abc";

  std::string a = i; // both are l values

  //static cast for converting lvalue i to xvalue
  std::string b = static_cast<std::string&&>(i);

  std::cout << "\n Value of A,B,I = " << a << "," << b << "," <<  i << "\n"; //i would be empty
}
