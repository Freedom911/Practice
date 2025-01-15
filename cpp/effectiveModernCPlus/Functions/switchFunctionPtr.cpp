//Having array of function ptr
#include <iostream>

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

int div(int a,int b)
{
  if(b == 0)
  {
     std::cerr << "\n Throw by zero error \n";
     return -1;
  }
}

int main()
{
  //for Array Pointer we have to use initializer ilst this will give error
  //int (*arrayFuncPtr[])(int,int) = &(add,sub,mult,div);
  int (*arrayFuncPtr[])(int,int) = {add,sub,mult,div};
  
  int a,b,ch ;
  std::cout << "\n Enter Two Numbers \n";
  std::cin >> a >> b;

  std::cout << "\n Enter Operation 1.ADD,2.SUB,3.MULT,4.DIV \n";
  std::cin >> ch;
  ch--;

  std::cout << (*arrayFuncPtr[ch])(a,b);

}
