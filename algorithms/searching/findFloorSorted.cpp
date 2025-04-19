/**
 * We Need to Find The Floor and Ceil in sorted array.
 * For Floor and Ceil if element is already present then we return the element directly
 * For Floor we return the lesser element . we could use linear search but to optimize we 
 * use bs. so the conecept is if element found we directly return else for floor when the elemnt
 * to find is greater than than arr mid so mid is a candidate for floor for that element
 * SImilalry for Ceil
 */ 

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
      minIndex = mid;
    }
    else
    {
      q = mid - 1;
    }

  }
  if(minIndex != -1)
  {
      return v[minIndex];
  }
  return minIndex;
}

int findCeil(std::vector<int> v,int k)
{ 

  std::cout << "FINDING CIEL OF " << k << " in array " << "\n";
  std::cout << v << "\n";
  if(k < v[0])
    return v[0];
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
    }
    else
    {
      q= mid - 1;
      minIndex = mid;
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
