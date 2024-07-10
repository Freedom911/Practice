#include <iostream>
int fact(int n,int curr)
{
  if(n == 1)
  return curr;
  
  return fact(n-1,n * curr);
  
}

int main()
{
	std::cout << fact(5,1) << "\n";
}