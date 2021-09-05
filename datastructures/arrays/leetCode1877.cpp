class Solution {
public:
    int minPairSum(vector<int>& nums) {
     
      std::sort(nums.begin(),nums.end());
      int n = nums.size();
      int max = -1;
      for(int i = 0; i < n/2;++i)
      {
        max = std::max(max,nums[i] + nums[n-i-1]);
      }
      
      return max;
      
    }
};
