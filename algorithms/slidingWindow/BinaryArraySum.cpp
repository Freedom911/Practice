/**
 * We can solve using the hash map which we did in fidning subarray with sum
 *  there we have O(n) for both time and space.
 * Here the case is the numbers are positive and only 0 and 1. so we do without extra space using sliding window
 * Here if we try to do directly to find exactly then we miss numbers
 * eg 
 * 0 1 0 0 1 0 1
 *   l         r
 * then we can form many
 * so we try to do atmost sum which we can directly add missing by length of window
 */
class Solution {
public:

    int helper(vector<int>& nums, int goal)
    {
       int l = 0;
       int r = 0;
       int n = nums.size();
       int sum = 0;
       int cnt = 0;

       while(r < n)
       {
          sum += nums[r];

          while(sum > goal)
          {
            sum -= nums[l];
             l++;
             
          }
          cnt += (r - l + 1);
          r++;
       }
       return cnt;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
      
       return helper(nums,goal) - helper(nums,goal - 1);
       
       
    }
};