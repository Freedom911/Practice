#include <iostream>
#include <vector>
int SumTail(std::vector<int> v,int curr)
{
  if(v.size() == 0)
  return curr;
  
  int elem = v.back();
  v.pop_back();
  return SumTail(v,curr+elem);
  
}

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};//n*(n+1)/2
	std::cout << SumTail(v,0) << "\n";
}