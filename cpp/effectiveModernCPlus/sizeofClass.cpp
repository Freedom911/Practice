//Virtual inheritance also creates vtable and bvptr
#include <iostream>

class E
{

};

class D1:public E{};

class D2:virtual public E{};

class D3:virtual public E
{
  char c;
};

class D4:public E
{
  char c;
};
class Dummy
{
  char c;
};

class lol
{
  int i;
};
class paul
{
  static int f;
};

int main()
{

  std::cout << sizeof(lol) << "\n";
  std::cout << sizeof(paul) << "\n"; //since static is not a part of a class so the size owuld be 1 only

  std::cout << sizeof(E) << "\n";
  std::cout << sizeof(D1) << "\n";
  std::cout << sizeof(D2) << "\n";
  std::cout << sizeof(D3) << "\n";
  std::cout << sizeof(D4) << "\n";
  std::cout << sizeof(Dummy) << "\n";
}


