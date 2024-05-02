//Program For Solving 01 Knapsack using both memoization and top down approach
//for dp first step is to identify its a dp problem.Generally if there are two are more
//recursive calls then we can apply dp . Also We need to make the solution optimial is a second requirement
//0 1knapsack recursive,memoization
#include <iostream>
#include <cstring>
#include <vector>

int KnapsackRecursive(const std::vector<int> &wt,const std::vector<int>&val,const int&n,const int&W)
{
	if(n == 0 || W == 0)
	{
		return 0;
	}
	
	//Weight of n - 1 item is less than capacity then we have two choices
	//either include or exclude
	if(wt[n-1] <= W)
	{
		return std::max((val[n-1] + KnapsackRecursive(wt,val,n-1,W - wt[n-1])),//INclude
						 KnapsackRecursive(wt,val,n-1,W));
	}
	else
	{
		return KnapsackRecursive(wt,val,n-1,W);
	}
}

int t[5][8];
int KnapsackMemoization(const std::vector<int> &wt,const std::vector<int>&val,const int&n,const int&W)
{
	if(n == 0 || W == 0)
	{
		return 0;
	}
	
	if(t[n][W] != -1)
	{
		return t[n][W];
	}
	
	//Weight of n - 1 item is less than capacity then we have two choices
	//either include or exclude
	if(wt[n-1] <= W)
	{
		t[n][W] = std::max((val[n-1] + KnapsackMemoization(wt,val,n - 1,W - wt[n-1])),//INclude
						 KnapsackMemoization(wt,val,n-1,W));
		return t[n][W];
	}
	else
	{
		t[n][W] =  KnapsackMemoization(wt,val,n-1,W);
		return t[n][W];
	}
}

int t1[5][8];
int KnapsackTabular(const std::vector<int> &wt,const std::vector<int>&val,const int&n,const int&W)
{
	
	for(int i = 0; i < n + 1; i++)
	{
		for(int j = 0; j < W + 1; j++)
		{
			if(i == 0 || j == 0)
			{
				t1[i][j] = 0;
			}
		}
	}
	
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < W + 1; j++)
		{
			if(wt[i-1] <= j)
			{
				t1[i][j] = std::max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else
			{
				t1[i][j] = t[i-1][j];
			}
		}
	}
	return t1[n][W];
	
}



int main()
{
	std::vector<int> wt{1,3,4,5};
	std::vector<int> profit{1,4,5,7};
	int MaxCapacity = 7;
	

	
	std::cout << "\n Max Profit Using KnapsackRecursive is = " << KnapsackRecursive(wt,profit,wt.size(),MaxCapacity);

	
	std::memset(t,-1,sizeof(t));
	
	std::cout << "\n Max Profit Using KnapsackMemoization is = " << KnapsackMemoization(wt,profit,wt.size(),MaxCapacity);
	
	
	std::memset(t1,-1,sizeof(t));
	
	std::cout << "\n Max Profit Using KnapsackTabular is = " << KnapsackTabular(wt,profit,wt.size(),MaxCapacity);
	
}
