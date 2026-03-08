/**
 * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 *
 * Uses fruit  into basket code. with some modification and
 * Binary Subarray sum question
 *
 * So in fruit into basket we were finding max. so the inner loop we need not required to shrink the window
 * as we only wanted maximum here 
 * the thing is different the window size is variable
 *
 * it also uses binary subarray sum concept where we found at most k - atmost k - 1
 *
 */

class Solution {
public:

int helper(vector<int>& num, int k) {
        if(k < 0)
        {
            return 0;
        }
        std::unordered_map<int,int> us;
        int l = 0;
        int r = 0;
        int n = num.size();
        int cnt = 0;



        while(r < n)
        {
            us[num[r]]++;

            while(us.size() > k)
            {
                us[num[l]]--;

                if(us[num[l]] == 0)
                {
                    us.erase(num[l]);
                }
                l++;
            }
            //maxW = std::max(maxW,r-l+1);
           // if(us.size() <= k)
            cnt += r -l + 1;
            r++;
        }
        return cnt;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return helper(nums,k) - helper(nums,k-1);
    }
};
