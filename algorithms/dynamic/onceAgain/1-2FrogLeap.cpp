/**
 * We have to Find the minimum Energy such that a frog can reach the last step using 1 or 2 jump
 * This is based on Fibonacci
 
*/
#include <iostream>
#include <vector>
#include <limits>

//Hypothesis 
//This Function returns the min cost to reach till index
int rec(std::vector<int> &heights,int index)
{
	//Base Condition . NO Stairs Left
	if(index == 0)
	{
		return 0;
	}
	
	//Induction Step
	int ones = rec(heights,index-1) + std::abs(heights[index] - heights[index-1]);
	int twos = std::numeric_limits<int>::max();
	if(index - 2 >= 0)
	{
		twos = rec(heights,index-2) + std::abs(heights[index] - heights[index-2]);
	}
	return std::min(ones,twos);
}

//Hypothesis 
//This Function returns the min cost to reach till index
int topwdown(std::vector<int> &heights,std::vector<int> &dp,int index)
{
	//Base Condition . NO Stairs Left
	if(index == 0)
	{
		return 0;
	}
	
	if(dp[index] != -1)
	{
		return dp[index];
	}
	
	//Induction Step
	int ones = topwdown(heights,dp,index-1) + std::abs(heights[index] - heights[index-1]);
	int twos = std::numeric_limits<int>::max();
	if(index - 2 >= 0)
	{
		twos = topwdown(heights,dp,index-2) + std::abs(heights[index] - heights[index-2]);
	}
	return dp[index] = std::min(ones,twos);
}


//Bottom Up
int bottomUp(std::vector<int> &heights)
{
	
	//Base Condition . NO Stairs Left
	if(heights.size() == 0 || heights.size() == 1)
	{
		return 0;
	}
	std::vector<int> dp(heights.size() , -1);
	
	dp[0] = 0;
	
	
	for(int i = 1; i < heights.size(); i++)
	{
		int x = dp[i-1] + std::abs(heights[i] - heights[i-1]);
		
		int y = std::numeric_limits<int>::max();
		
		if(i-2 >= 0)
		{
			y = dp[i-2] + std::abs(heights[i] - heights[i-2]);
		}
		
		dp[i] = std::min(x,y);
	}
	
	return dp[heights.size() - 1];
	
}

//Space Optimized . We only Require previous two values
int spaceOptimized(std::vector<int> &heights)
{
	
	//Base Condition . NO Stairs Left
	if(heights.size() == 0 || heights.size() == 1)
	{
		return 0;
	}

    int x = 0;
    int y = std::numeric_limits<int>::max();;	
	int z;
	
	
	for(int i = 1; i < heights.size(); i++)
	{
		int jump1 = x  + std::abs(heights[i] - heights[i-1]);
		int jump2 = std::numeric_limits<int>::max();
		
		if(i-2 >= 0)
		{
			jump2 = y + std::abs(heights[i] - heights[i-2]);
		}
		
		z = std::min(jump1,jump2);

		y = x;
		x = z;
	}
	
	return z;
	
}

int main()
{
std::vector<int> v{30,10,60,10,60,50};
std::vector<int> dp(v.size() , -1);
std::cout << "\n RECURSIVE = " << rec(v,v.size() - 1) << "\n";
std::cout << "\n TOP DOWN = " << topwdown(v,dp,v.size() - 1) << "\n";
std::cout << "\n Bottom Up = " << bottomUp(v) << "\n";
std::cout << "\n Space Optimized = " << spaceOptimized(v) << "\n";
}