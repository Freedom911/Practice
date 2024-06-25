//g++ -S file.cpp
//name mangling is a procedure by which compiler can differentiate between
//functions with same name and different arguments. it adds character after each function to differentiate
#include <iostream>

extern "C"{ //if we remove extern we will see in dump file that we have fooi and fooc
void foo(int a)
{
  std::cout << "a";
}
}
void foo(char a)
{
  std::cout << "string";
}

int main()
{
  foo(3);
}
