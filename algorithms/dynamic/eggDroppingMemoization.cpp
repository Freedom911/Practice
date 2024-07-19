//Egg Dropping Memoization
//IN Egg Dropping we have to minimize tries for the worst case 
//while finding where the egg breaks.
//we dont have to find the number at which the egg breaks/
//rather the minimum tries
//we use mcm as a concept
//eg for floors 5 we have 1,2,3,4,5 floors
//for every k we find the worst case and then we minimize that
//the worst case is actually base case here and it is basically
//when we have one egg and  the egg breaks at last floor and we start
//from begininng then we have tries = Total no of floors
#include <iostream>
#include <algorithm>
#include <vector>

//Hypothesis
int solve(int e,int n)
{
	//base condiions
	if(n == 1 || n == 0)//means 1 or 0 floor
	{
		return n;// these many ties if 1 floor then 1 try if 0 then 0 try
	}
	
	if(e == 1)//only one egg then n tries
	{
		return n;
	}
	
	//choices
	int minT = std::numeric_limits<int>::max();
	for(int k = 1; k <= n; k++)
	{
		int eggBroken = solve(e-1,k-1);//egg broken at k  so we go neeche to check
		int eggNotBroken = solve(e,n-k);//go uppar with n - k floors to check
		int tempAns = 1 + std::max(eggBroken,eggNotBroken);//1 for try
		
		minT = std::min(tempAns,minT);
	}
	return minT;
}

//Hypothesis
int solveDP(int e,int n,std::vector<std::vector<int>> &t)
{
	//base condiions
	if(n == 1 || n == 0)//means 1 or 0 floor
	{
		return n;// these many ties if 1 floor then 1 try if 0 then 0 try
	}
	
	if(e == 1)//only one egg then n tries
	{
		return n;
	}
	if(t[e][n] != -1)
	{
		return t[e][n];
	}
	
	//choices
	int minT = std::numeric_limits<int>::max();
	for(int k = 1; k <= n; k++)
	{
		int eggBroken = t[e-1][k-1],eggNotBroken = t[e][n-k];
		if(eggBroken == -1)
		 eggBroken = solveDP(e-1,k-1,t);//egg broken at k  so we go neeche to check
		
		if(eggNotBroken == -1)
		 eggNotBroken = solveDP(e,n-k,t);//go uppar with n - k floors to check
		int tempAns = 1 + std::max(eggBroken,eggNotBroken);//1 for try
		
		minT = std::min(tempAns,minT);
	}
	return t[e][n] = minT;
}

int main()
{
	int eggs = 2;
	int floors = 10;
	std::vector<std::vector<int>> t(eggs+1,std::vector<int>(floors+1,-1));
	
	std::cout << "\n Minimum number of tries for worst case = " << solve(eggs,floors) << "\n";
	
	std::cout << "\n DP Minimum number of tries for worst case = " << solveDP(eggs,floors,t) << "\n";
}