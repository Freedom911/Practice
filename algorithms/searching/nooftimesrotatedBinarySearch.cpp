#include <iostream>
#include <vector>

/**
 * Doesnt work on duplicate:wq
 *
 * No Of Times the Array is rotated
 *
 * Solution 
 * 1 2 3 4 5 6 7
 *  Here min element is at 0th Index. if we opbserve the rotation array
 *
 *  4 5 6 7 1 2 3
 *  Here min element is at 4th index.
 *  So number of times the array is rotated is len(arr) - min(index)
 *  7 - 4 = 3
 *
 *  Now we can simple do linear search and find minimumn in O(n)
 *
 *  for better we use binary search
 *
 *  for binary search we require 2 things
 *  ans part
 *  movement part
 *
 *  1. Ans Part
 *  To check if an element is minimum we compare with both previous and next
 *  next element = (mid + 1) % N. For cyclic thingy
 *  For previous thingy we can simply do mid - 1 but it may be negative since we have cyclic thingy means 1 can appear
 *  at last
 *  for that we simply add mid + N and then minus 1 modulo N to get previous element simply
 *  (mid + N - 1)%N
 *
 *  2. Movement Part. we need to decide where the minimum element will be found. 
 *  The minimum element will be found in the unsorted array part.
 */ 

int nooftimes(std::vector<int>v)
{
  int times = -1;
  int p = 0;
  int q = v.size() - 1;
  int mid = -1;
  int S = v.size();
  while(p <= q)
  {
    mid = p + (q-p)/2;
    int next = (mid + 1) % v.size();
    int prev =  (mid + v.size() -  1)  % v.size();

    if(v[mid] <= v[prev] && v[mid] <= v[next])
    {
      return S-mid;
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
  std::cout << nooftimes({8,11,12,15,18,2,5,6,8,8}) << "\n";
  std::cout << nooftimes({5,6,7,8,1,2,3,4}) << "\n";
 //std::cout << nooftimes({18,2,5,6,8,11,12,15}) << "\n";
 //std::cout << nooftimes({2,5,6,8,11,12,15}) << "\n";
 //std::cout << nooftimes({2,1}) << "\n";
}
