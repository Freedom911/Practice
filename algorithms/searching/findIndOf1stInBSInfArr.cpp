#include <iostream>
#include <vector>

int findEndIndex(std::vector<int> v,int k)
{
  int p = 0;
  int q = 0;
  while(p <= q && q < v.size()) //in infinite array we dont have size but here we are doing to avoid exception
  {
    if(v[q] == k)
      return q;
    p = q;
    q = 2*p + 1;
  }
  return q;
}

int findFirstOne(std::vector<int> v,int k)
{
  int p = 0;
  int q = findEndIndex(v,k);
  int end = q;
  int mid = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;
    if(v[mid] == k)
    {
      int prev = mid - 1;
      int next = mid + 1;
      if(prev < 0 || next > end)
        return mid;

      //means at previous also we have one then move left to get to 1st index
      if(v[prev] == k)
      {
        q = mid - 1;
      }
      //means the previous is not one so return mid
      else
      {
        return mid;
      }
    }
    else
    {
      if(v[mid] > k)
        q = mid - 1;
      else
        p = mid + 1;
    }
  }
  return -1;
}
int main()
{
  std::cout << "\n INDEX OF 1 = " << findFirstOne({0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},1) ;
  std::cout << "\n INDEX OF 1 = " << findFirstOne({0,0,0,0,0,1},1) ;
  std::cout << "\n INDEX OF 1 = " << findFirstOne({1},1) ;
  std::cout << "\n INDEX OF 1 = " << findFirstOne({0},1) ;
}
