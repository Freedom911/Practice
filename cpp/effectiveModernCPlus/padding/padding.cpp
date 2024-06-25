// Padding There in  both struct and class
#include <iostream>

struct abc
{
  char a;
  char b;
  int c;
};
struct abc1
{
  char a;
  int c;
  char b;
};
class abcd
{
  char a;
  char b;
  int c;
};
class abcd1
{
  char a;
  int c;
  char b;
};

int main()
{
  struct abc z;
  struct abc1 z2;
  abcd z3;
  abcd1 z4;

  std::cout << "\n Size of struct  abc = " << sizeof(z) << "\n";
  std::cout << "\n Size of struct abc1 = " << sizeof(z2) << "\n";
  std::cout << "\n Size of class abcd = " << sizeof(z3) << "\n";
  std::cout << "\n Size of class abcd1 = " << sizeof(z4) << "\n";


}
