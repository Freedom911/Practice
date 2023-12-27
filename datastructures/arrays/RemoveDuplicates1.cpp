//Problem no 27
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		//we use two pointers approach and we replace element != val to delete so that all
		//elemtns that are != val are moved to left
		int i = 0;
		int j = 0;
		
		while(i < nums.size())
		{
			if(nums[i] != val)
			{
				nums[j] = nums[i];
				j++;
			}
			i++;
		}
		
		
		return j;
        
    }
};