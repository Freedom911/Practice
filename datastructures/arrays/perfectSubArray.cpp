#include <iostream>
#include <vector>
#include <cmath>
int main()
{
  std::vector<int>v{2,3,-5,6,-7,4};
  int count = 0;
  for(int i = 0; i < v.size() - 1; i++)
  {
    int sum = v[i];
    for(int j = i+1;j < v.size();j++)
    {
      sum+= v[j];
      int sqr = std::sqrt(sum);
      if(sqr * sqr == sum)
      {
        count++;
      }
    }
  }
  int sqr = std::sqrt(v[v.size() - 1]);
  if(sqr * sqr == v[v.size() - 1])
  {
    count++;
  }
  
  std::cout << count << "\n";
}
