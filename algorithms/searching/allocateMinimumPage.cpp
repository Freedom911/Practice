//Allocate minimum no pf pages so that there is least stress
//we need to minimize maximum no of pages a student has to read
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>

//if total required student == k then valid
//else no
bool isValid(std::vector<int>v,int sum,int k,int &req)
{
   req = 1;
   int s = 0;
   for(int i:v)
   {
     s += i;
     if(s > sum)
     {
       req++;
       s = i;
     }
   }

   if(req <= k)
     return true;
   return false;
}

int getPages(std::vector<int>v,int k) //k = no of students
{
  int p = 0;
  int q = std::accumulate(v.begin(),v.end(),0);
  

  int min = std::numeric_limits<int>::max();
  while(p <= q)
  {
    int midSum = p + (q-p)/2;
    int req = 0;
    if(isValid(v,midSum,k,req))
    {
      if(min > midSum)
        min = midSum;
      q = midSum - 1;
    }

    else
      p = midSum + 1;
  }

  return std::max(min,*max_element(v.begin(), v.end()));
}

int main()
{
 // std::cout << getPages({2,3,1,2,4,3},5) << "\n";
  std::cout << getPages({1,5,10},1) << "\n";
}
