class Solution {
public:

//o(space)
//logic is we find anamolies from both sides
//and then we check if more elements ot include 
int findUnsortedSubarray(vector<int>& nums) 
	{
		int n = nums.size();
		int l = -1;
		for(int i = 0; i < n - 1; i++)
		{
			if(nums[i] > nums[i+1])
			{
				//1st anamoly fromleft side
				l = i;
				break;
			}
		}
		//Allreadu Sorted
		if(l == -1)
		{
			return 0;
		}
		
		int r = -1;
		for(int j = n-1; j > 0; j--)
		{
			if(nums[j] < nums[j-1])
			{
				r = j;
				break;
			}
		}
		
		//Now we need to check if more elements to be included
		//so if there is number in between l and r which is minimum then element on the left side
		//so that means that the number of left side should be included in sorting as well
		//similarly for right side if there is an element in l to r is greater than element on the 
		//right side then that element on right should be included
		//1st find min and max
		int max = std::numeric_limits<int>::min(),min = std::numeric_limits<int>::max();
		for(int i = l ; i <= r; i++)
		{
			if(nums[i] >= max)
			{
				max = nums[i];
			}
			if(nums[i] <= min)
			{
				min = nums[i];
			}
		}
		
		//now for left side
		for(int i = 0; i < l; i++)
		{
			if(nums[i] >  min)
			{
				l = i;
				break;
			}
		}
		
		//for right side
		for(int i = n - 1; i > r; i--)
		{
			if(nums[i] < max)
			{
				r = i;
				break;
			}
		}
		
		return r - l + 1;
		
		
    }
	
	//o(nlogn) time and o(n) space
    int findUnsortedSubarray1(vector<int>& nums) {
        vector<int> v = nums;
		
		std::sort(nums.begin(),nums.end());
		
		int count = 0;
		int start = -1,last = -1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != v[i])
			{
				if(start == -1)
				{
					start = i;
				}
				if(last == -1 || i > last)
				{
					last = i;
				}

			}
		}
		if(start == -1 )
		{
			return 0;
		}
		return last - start + 1;
    }
};