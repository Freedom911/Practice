#include <iostream>

template<typename T,typename U>
struct is_same
{
  static const bool value = false;
};


template<typename T>
struct is_same<T,T>
{
 static const bool value = true;
};

template<class A,class B>
bool isSameClass()
{
  return is_same<A,B>::value;
}

class A
{

};

class B
{

};

int main()
{
  A a,b;
  std::cout << isSameClass<A,B>(); 
}
