#include <iostream>

constexpr int returnVal()
{
  int i = 3;

  return i;
}

//ConstExr function Can't be void
constexpr void what()
{
  std::cout << "\n HI\n";
}


int main()
{
  int i ;
  std::cin >> i;

  
  const int j = i*i;
  std::cout << j << "\n";

  //ConstExpr is at compile time only
// constexpr int k = i*i;
// std::cout << k << "\n";

  constexpr int k = 3*3;
  std::cout << k << "\n";

std::cout << returnVal() << "\n";
what();

}
