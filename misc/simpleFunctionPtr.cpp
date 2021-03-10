#include <iostream>
#include <functional>
//FUNCTION POINTER POINTS to code instead of data

void add(int a,int b)
{
  std::cout << a + b << "\n";
}

int addRet(int a,int b)
{
  return a+b;
}

int main()
{
  void (*addPtr)(int,int) = &add;
  (*addPtr)(10,3);

  int (*addRetPtr)(int,int) = &addRet;
  std::cout << (*addRetPtr)(10,30) << "\n";


  using FunctionFunc = std::function<int(int arg1, int arg2)>;
  //using FunctionFunc = int(int a,int b);

  FunctionFunc foo = &addRet;

  std::cout << "\n RSULT = " << foo(100,200);


  //We cannot have new for function pointer
  //int (*addRetPtr1)(int,int) = new int(1000);
}
