//https://leetcode.com/problems/majority-element/submissions/
//https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
//we sort then just count the element appearing maximum times in one for loop
class Solution {
public:
   
   //using boyer moore majority algorithm/
   //concept is if a number is appearing more than n/2 times then other numbers 
   //should be less than n/2 as total sum should be n/2
   //then we find the candidate with most votes
   //then we find how many times candidate isappearing
    int majorityElement(vector<int>& arr) 
	{
		int votes = 0;
		int count = 0;
		int n = arr.size();
		int candidate = -1;
		for(int i = 0; i < n; i++)
		{
			if(votes == 0)
			{
				//switch candidate
				candidate = arr[i];
				votes = 1;
			}
			else
			{
				if(candidate == arr[i])
				{
					votes++;
				}
				else
					votes --;
			}
		}
		
		for(int i = 0;i<n;i++)
		{
			if(candidate == arr[i])
			{
				count++;
				if(count > n/2)
				{
					return arr[i];
				}
			}
		}
		return -1;
	}
    
    //O(nlogn)
    int majorityElement1(vector<int>& arr) {
		
		if(arr.size() == 1)
		{
			return arr[0];
		}
	
	  std::sort(arr.begin(),arr.end());
	  int count = 1;
	  int prev = 0;
	  int n = arr.size();
	  for(int i = 1; i < n; i++)
	  {
	    if(arr[i] == arr[prev])
		{
		   count++;
		   if(count > (n/2))
		   {
		     return arr[i];
		   }
		}
		else
		{
		  count = 1;
		}
		prev = i;
	  }
	  return -1;
        
    }
};