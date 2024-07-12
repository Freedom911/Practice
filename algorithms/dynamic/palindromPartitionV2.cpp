#include <iostream>
#include <string>
#include <vector>
#include <limits>

bool isPalindrome(std::string str,int i, int j)
{
	//Means only one element
	if(i >= j)
	{
		return true;
	}
	
	while(i <= j)
	{
		if(str[i] != str[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
	
}

//Hypothesis
int MinPartition(std::string str,int i,int j)
{
	//Means there is only one element and we dont need partition
	if(i == j || isPalindrome(str,i,j))
	{
		return 0;
	}
	//choices/induction step
	int minCost = std::numeric_limits<int>::max();
	for(int k = i+1; k <= j; k++)
	{
		int c1 = MinPartition(str,i,k-1);
		int c2 = MinPartition(str,k,j);
		int c3 = 1;
		int totalCost = c1 + c2 + c3;
		minCost = std::min(totalCost,minCost);
	}
	return minCost;
}

//Here we pass table 2d vector as well
int MinPartitionDP(std::string str,int i,int j,std::vector<std::vector<int>> &t)
{
	//Base condition 1
	if(i == j)
	{
		return 0;
	}
	
	//Means already processed
	if(t[i][j] != -1)
	{
		return t[i][j];
	}
	
	//Base condition 2
	//done after t[i][j] to avoid evalutating again and again
	if(isPalindrome(str,i,j))
	{
		return t[i][j] = 0;
	}
	
	int minCost = std::numeric_limits<int>::max();
	//Choices
	for(int k = i + 1; k<= j; k++)
	{
		int c1,c2,c3;
		if(t[i][k-1] != -1)
		{
			c1 = t[i][k-1];
		}
		else
		{
			c1 = MinPartitionDP(str,i,k-1,t);
		}
		if(t[k][j] != -1)
		{
			c2 = t[k][j];
		}
		else
		{
			c2 = MinPartitionDP(str,k,j,t);
		}
		
		c3 = 1;
		int totalCost = c1 + c2 + c3;
		minCost = std::min(totalCost,minCost);
		
	}
	
	return t[i][j] = minCost;
}

int main()
{
	std::string str = "abcdaefkkfalwefghjgdw";
	int n = str.length();
	if(0 && isPalindrome(str,0,n))
	{
		std::cout << "0";
		return 0;
	}
    //this will be so slow without dp
	std::cout << MinPartition(str,0,n-1) << "\n";
    //return 1;
	
    std::vector<std::vector<int>> t( n + 1 , std::vector<int> (n+1,-1));
    	
	
	std::cout << "DP = " << MinPartitionDP(str,0,n-1,t) << "\n";
}
