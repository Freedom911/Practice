
/**
 * https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum
 * 
 * We basically have to find number of subarray with sum equal to zero.
 * Solution 1 - Brute force. 
 * so we will have two loops for i to n and for j = i to n;
 * is sum euals 0 we increment the count
 * 
 * Solution 2 Optimal
 * So basically we use the concept of prefix sum. and as soon as we get a prefix sum which is eual to any prefix sum detected earlier
 * then we increase the count by 1
 * eg  6,-1,-3,4,-2
 * pre 6,5,2,6,4
 * So 6 is detected at 0th index so anything we add between causes sum 0 
 * so we increase count by 1. if wad detected two times then we increment two times
 */
#include <iostream>
#include <vector>
#include <unordered_map>

int TotalCount(std::vector<int> vec)
{
   if(vec.size() == 0)
   {
    return 0;
   }

   std::unordered_map<int,int>us;
   int prefix = 0,total = 0;
   for(int i = 0; i <vec.size(); i++)
   {
    prefix += vec[i];

    //The edge case. if we detect 0 then at that point no one contributed
    if(vec[i] == 0)
    {
        total++;
        continue;
    }
    if(us.find(prefix) != us.end()) //means we got already the same no so rest in between contribute 0
    {
        total += us[prefix];
    }
    us[prefix]++;
   }

   return total;
}


int main()
{
    std::cout << "\n TOTAL = " << TotalCount({9, -3, 3, -1, 6, -5}  );
}
