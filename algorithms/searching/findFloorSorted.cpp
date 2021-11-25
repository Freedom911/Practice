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
  std::cout << "FINDING FLOOR OF " << k << " in array " << "\n";
  std::cout << v << "\n";
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

  std::cout << "FINDING CIEL OF " << k << " in array " << "\n";
  std::cout << v << "\n";
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

int main()
{
  std::cout << findFloor({1,2,3,4,8,10,10,12,19},5) << "\n";;
 std::cout << findFloor({1,2,3,4,8,10,10,12,19},1) << "\n";;
 std::cout << findFloor({1,2,3,4,8,10,10,12,19},19) << "\n";;
 std::cout << findFloor({1,2,3,4,8,10,10,12,19},20) << "\n";;
 std::cout << findFloor({1,2,3,4,8,10,10,12,19},10) << "\n";;
 std::cout << findFloor({1,2,3,4,8,10,10,12,19},11) << "\n";;

 std::cout << "\n ======= FINDING CEIL ====== \n";
 std::cout << findCeil({1,2,3,4,8,10,10,12,19},5) << "\n";;
 std::cout << findCeil({1,2,3,4,8,10,10,12,19},1) << "\n";;
 std::cout << findCeil({1,2,3,4,8,10,10,12,19},19) << "\n";;
 std::cout << findCeil({1,2,3,4,8,10,10,12,19},10) << "\n";;
 std::cout << findCeil({1,2,3,4,8,10,10,12,19},11) << "\n";;
 std::cout << findCeil({2,3,4,8,10,10,12,19},1) << "\n";;
 std::cout << findCeil({2,3,4,8,10,10,12,19},20) << "\n";;
 std::cout << findCeil({2,4},1) << "\n";;

  return 0;
}
