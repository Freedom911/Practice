
#include <iostream>
#include <vector>
#include <limits>

std::ostream &operator <<(std::ostream &out,const std::vector<int> &v)
{
  for(int i = 0; i < v.size(); i++)
  out << v[i] << " " ;

  return out;
}

int findFloor(std::vector<int> v,int k)
{
  int min = std::numeric_limits<int>::max();
  int p = 0;
  int q = v.size() - 1;
  int mid = -1,minIndex;
  while(p <= q)
  {
    mid = p + (q-p)/2;
    if(v[mid] == k)
      return v[mid];

    if(k > v[mid])
    {
      p = mid + 1;
      if(min > (k - v[mid]))
      {
        min = k - v[mid];
        minIndex = mid;
      }
    }
    else
    {
      q= mid - 1;
    }

  }
  if(min != std::numeric_limits<int>::max())
  return v[minIndex];
  else
    return -1;
}

int findCeil(std::vector<int> v,int k)
{ 

  if(k < v[0])
    return v[0];
  int min = std::numeric_limits<int>::max();
  int p = 0;
  int q = v.size() - 1;
  int mid = -1,minIndex = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;
    if(v[mid] == k)
      return v[mid];

    if(k > v[mid])
    {
      p = mid + 1;
      if(min > (k - v[mid]))
      {
        min = k - v[mid];
        minIndex = mid + 1;
        if(minIndex >= v.size())
          return -1;
      }
    }
    else
    {
      q= mid - 1;
    }

  }
  if(minIndex != -1)
  return v[minIndex];
  else
    return -1;
}

int findDiff(std::vector<int>v,int k)
{
  std::cout << findFloor(v,k) << "\n";
  std::cout << findCeil(v,k) << "\n";
  return std::min(std::abs(k - findFloor(v,k)),std::abs( k -findCeil(v,k)));
}

int main()
{
  std::cout << findDiff({1,2,3,4,8,10,13,19},12) << "\n";;

  return 0;
}
