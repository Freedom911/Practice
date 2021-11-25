#include <iostream>
#include <vector>

int nooftimes(std::vector<int>v)
{
  int times = -1;
  int p = 0;
  int q = v.size() - 1;
  int mid = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;
    int next = (mid + 1) % v.size();
    int prev =  (mid + v.size() -  1)  % v.size();

    if(v[mid] <= v[prev] && v[mid] <= v[next])
    {
      return mid;
    }
    //if it mid is less than starting element then we need to move left towards
    //unsorted part as the minimum will lie there


    else if(v[0] <= v[mid])
    {
      p = mid + 1;
    }
    else if(v[mid] <= v[v.size() - 1])
    {
      //p = mid + 1;
      q = mid - 1;
    }
    
  }

  return times;
}

int main()
{
  std::cout << nooftimes({11,12,15,18,2,5,6,8}) << "\n";
  std::cout << nooftimes({18,2,5,6,8,11,12,15}) << "\n";
  std::cout << nooftimes({2,5,6,8,11,12,15}) << "\n";
  std::cout << nooftimes({2,1}) << "\n";
}
