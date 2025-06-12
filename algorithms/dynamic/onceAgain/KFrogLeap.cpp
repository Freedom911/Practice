/**
 * We have to Find the minimum Energy such that a frog can reach the last step using K jump
 * This is based on Fibonacci
 
*/
#include <iostream>
#include <vector>
#include <limits>

//Hypothesis 
//This Function returns the min cost to reach till index
int rec(std::vector<int> &heights,int index,int k)
{
	//Base Condition . NO Stairs Left
	if(index == 0)
	{
		return 0;
	}
	
	//Induction Step

	int minJump = std::numeric_limits<int>::max();
	
	//Jump from 1 to k
	for(int i = 1; i <= k; i++)
	{
		if(index - i < 0)
			break;
		minJump = std::min(minJump,rec(heights,index - i,k) + std::abs(heights[index] - heights[index-i]));
	}
	
	return minJump;
}

//Hypothesis 
//This Function returns the min cost to reach till index
int topwdown(std::vector<int> &heights,std::vector<int> &dp,int index,int k)
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
	
	int minJump = std::numeric_limits<int>::max();
	
	//Jump from 1 to k
	for(int i = 1; i <= k; i++)
	{
		if(index - k < 0)
			break;
		if(dp[index - k] != -1)
		{
			minJump = dp[index - k];
		}
		else
		{
			minJump = std::min(minJump,rec(heights,index - i,k) + std::abs(heights[index] - heights[index-i]));
		}
	}
	
	return dp[index] = minJump;
}


//Bottom Up
int bottomUp(std::vector<int> &heights,int k)
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
		int minJump = std::numeric_limits<int>::max();
		for(int j = 1; j <= k; j++)
		{
			if(i - j  < 0)
			{
				break;
			}
			minJump = std::min(minJump,dp[i-j] + std::abs(heights[i] - heights[i-j]));
		}
		
		
		dp[i] = minJump;
	}
	
	return dp[heights.size() - 1];
	
}


int main()
{
std::vector<int> v{30,10,60,10,60,50};
std::vector<int> dp(v.size() , -1);
int  k = 5;
std::cout << "\n RECURSIVE = " << rec(v,v.size() - 1,k) << "\n";
std::cout << "\n TOP DOWN = " << topwdown(v,dp,v.size() - 1,k) << "\n";
std::cout << "\n Bottom Up = " << bottomUp(v,k) << "\n";

}