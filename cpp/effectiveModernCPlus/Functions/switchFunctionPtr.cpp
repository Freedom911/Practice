//Having array of function ptr
#include <iostream>
#include <functional>

int add(int a,int b)
{
  return a+b;
}
int sub(int a,int b)
{
  return a - b;
}
int mult(int a,int b)
{
  return a*b;
}

int division(int a,int b)
{
  if(b == 0)
  {
     std::cerr << "\n Throw by zero error \n";
     return -1;
  }
  return a/b;
}

int main()
{
  //for Array Pointer we have to use initializer ilst this will give error
  //int (*arrayFuncPtr[])(int,int) = &(add,sub,mult,div);
  int (*arrayFuncPtr[])(int,int) = {add,sub,mult,division};
  
  int a,b,ch ;
  std::cout << "\n Enter Two Numbers \n";
  std::cin >> a >> b;

  std::cout << "\n Enter Operation 1.ADD,2.SUB,3.MULT,4.DIV \n";
  std::cin >> ch;
  ch--;

  std::cout << (*arrayFuncPtr[ch])(a,b);
  std::cout << "\n";

  std::function<int(int ,int)> functionFoo[4] = {add,sub,mult,division};

  std::cout << functionFoo[ch](a,b) << "\n";;

}
