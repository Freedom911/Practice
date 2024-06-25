
#include <iostream>
#include <vector>



//DECLTYPE HELPING IN TELLING THE RETURN TYPE base
// on the container and index. vector[i] will return a reference
#if 1
auto returnSomething(std::vector<int>str,int i)->decltype(str[i])
{
  return str[i];
}


/*
decltype(auto) returnSomething(std::vector<int>str,int i)
{
  return str[i];
}
*/


#else
//This will give error since auto will strip down &
//but a[i] is suppose to return reference
auto returnSomething(std::vector<int>str,int i)
{
  return str[i];
}
#endif
int main()
{
  std::vector<int> a{1,2};
  returnSomething(a,1) = 3;

  std::cout << a[1] << "\n";

}

