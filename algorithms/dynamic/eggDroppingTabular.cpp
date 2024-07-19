class Solution {
public:
    int superEggDropLinearSearch(int e, int f) {
        int t[e+1][f+1];
		memset(t,0,sizeof(t));
		
		//Base conditions in recursion were
		//if(e == 1) return f
		//if(f == 0 || f == 1) return f
		
		//Base conditions
		//1st row will be equal to number of floors
		//as there are only one eggs
		
		for(int j = 0; j <= f; j++)
		{
			//means egg = 1
			t[1][j] = j;
		}
		
		//0th column will be 0
		for(int i = 0; i<= e; i++)
		{
			//1st column will be 1 
			{
				//means no of floors = 1 or 0
				t[i][1] = 1;
				t[i][0] = 0;
			}
		}
		
		//choices
		
		for(int i = 2; i <= e; i++)
		{
			for(int j = 2; j <= f; j++)
			{
				t[i][j] = std::numeric_limits<int>::max();
				
				for(int k = 1; k <= j; k++)
				{
					int ans = 1 + std::max(t[i-1][k-1],t[i][j-k]);
					t[i][j] = std::min(ans,t[i][j]);
				}
			}
		}
		
		return t[e][f];
		
    }
	
	//Using Binary Search for more optimziation
	int superEggDropBinarySearch(int e, int f) {
        int t[e+1][f+1];
		memset(t,0,sizeof(t));
		
		//Base conditions in recursion were
		//if(e == 1) return f
		//if(f == 0 || f == 1) return f
		
		//Base conditions
		//1st row will be equal to number of floors
		//as there are only one eggs
		
		for(int j = 0; j <= f; j++)
		{
			//means egg = 1
			t[1][j] = j;
		}
		
		//0th column will be 0
		for(int i = 0; i<= e; i++)
		{
			//1st column will be 1 
			{
				//means no of floors = 1 or 0
				t[i][1] = 1;
				t[i][0] = 0;
			}
		}
		
		//choices
		
		for(int i = 2; i <= e; i++)
		{
			for(int j = 2; j <= f; j++)
			{
				t[i][j] = std::numeric_limits<int>::max();
				
				int low = 1;
				int high = j;
				int temp = 0;
				
				while(low <= high)
				{
					int mid = low + (high-low)/2;
					int left = t[i-1][mid-1];
					int right = t[i][j-mid];
					
					temp  = 1 + std::max(left,right);
					
					//where to move now
					//we have to move to right side as we have to find worst case
					
					if(left < right) 
					{
						low = mid + 1;
					}
					else
					{
						high = mid - 1;
					}
					t[i][j] = std::min(temp,t[i][j]);
				}
			}
		}
		
		return t[e][f];
		
    }
};

//https://leetcode.com/problems/super-egg-drop/solutions/792736/cpp-explained-recursive-memoization-optimization-dp-well-explained-easy-to-understand/