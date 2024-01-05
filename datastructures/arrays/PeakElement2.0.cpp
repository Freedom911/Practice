#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
		int n = nums.size();
		int r = n - 1;
		
		while(l <= r)
		{
			int mid = l + (r-l)/2;
			int prev = mid - 1;
			int next = mid + 1;
			
			if((prev < 0 && next >= n) || (prev >= 0 && next < n &&
			    nums[mid] > nums[prev] && nums[mid] > nums[next]) || (prev < 0 
				&& next < n && nums[mid] > nums[next])|| (next >= n && 
				prev >= 0 && nums[mid] > nums[prev]))
				{
					return mid;
				}
			
			else if((prev >= 0 && nums[mid] < nums[prev]) || (next >= n))
			{
				r = mid - 1;
			}
			else if((next < n && nums[mid] < nums[next]) || (prev < 0))
			{
				l = mid + 1;
			}
			
			   
			 
		}
		return 0;
    }
};

int main()
{
	Solution s;
	
	std::vector<int>v{1,2,1,3,5,6,4};
	std::cout << "\n Peak Element Found at = " << s.findPeakElement(v) << "\n";
	
}


