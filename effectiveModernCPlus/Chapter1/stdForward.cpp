//Forwards lvalues as either lvalues or as rvalues, depending on T
//Like in case of template if we have a function && then 
//if we pass lbalue then it is treaded as lvalue
//if we pass rvalue then it is treated as rvalue

//THIS CONCEPT IS PERFECT FORWARDING


#include <iostream>
#include <utility>


void set (int&&val)
{
  std::cout << "\n THIS IS AN R VAL FUNCTION \n";
}

void set (int&val)
{
  std::cout << "\n THIS IS AN L VAL FUNCTION \n";
}

template<class T>
void foo(T &&val)
{
  //if we comment this in both the following case we will have lvalue vcall
  set(std::forward<T>(val));
  //set(val);
}

int main()
{
  int a = 100;
  foo(a);
  foo(100);
  
}
