/**
 * Not Exactly a sliding Window
 * So we need to find total Subarray whose sum is k
 * I think we can sole with dp but n2 hai wo
 *
 * So we use the concept of prefix sum
 *
 * eg  2,1,7,-4,2,1
 * pre 2 3 10 6 8 9
 *
 *
 * So at any point we just ask is prefix sum - k is already present ?
 * at 4th index we have 8 so 8-6 .k = 6 here
 * so yes we have seen 2 so there is a subarray
 */ 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
       std::unordered_map<int,int> us;
       int pre = 0;
       us[0] = 1;//for 0 we include why? if we get k in array then we can include
       int total = 0;

       for(int i = 0; i < nums.size(); i++)
       {
           pre += nums[i];

           if(us.find(pre - k) != us.end())
           {
               total+= us[pre-k];
           }
           us[pre]++;
       }
    }
    return total;
};
