
/**
 * https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum
 * 
 * Extension of total Subarry with sum 0
 * 
 * Here in the map we maintain the index instead of count
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
   int prefix = 0;
   int maxWSize = 0;
   for(int i = 0; i <vec.size(); i++)
   {
    prefix += vec[i];

    //The edge case. if we detect 0 then at that point no one contributed
    if(vec[i] == 0)
    {
        maxWSize = std::max(maxWSize,i + 1);
        continue;
    }
    if(us.find(prefix) != us.end()) //means we got already the same no so rest in between contribute 0
    {
        maxWSize = std::max(maxWSize,i - us[prefix]);

    }
    else //we need not update the index as we want the max length so only the earliest one we insert in map
    {
       us[prefix] = i;
    }
    
   }

   return maxWSize;
}


int main()
{
    std::cout << "\n TOTAL = " << TotalCount({9, -3, 3, -1, 6, -5}  );
}
