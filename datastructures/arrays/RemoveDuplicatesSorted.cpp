//Problem no 26
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		
        int i = 1;
		int j = 0;
		
		while(i < nums.size())
		{
			while(i < nums.size() && nums[i] == nums[j])
			{
				i++;
			}
			
			if(i >= nums.size())
			{
				return j + 1;
			}
			
			j++;
			if(j < nums.size())
			nums[j] = nums[i];
			i++;
		}
		return j + 1;
    }
};

