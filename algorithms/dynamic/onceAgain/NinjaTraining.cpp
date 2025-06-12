/**
  Ninja Training 
  GIven nx3 matrix where n represents number of days and 3 represents training
  three types of training are
  1.Running
  2.Gym
  3.Acrobat
  
  int xp[n][3]. for each day we are given xp for each tasks. We have to pick training 
  for each day such that we get maximum xp such that we dont do same training on consequtive days
  
 Day 1 10 50 1
 Day 2 11 100 10

 Greedy Approach Fails for example
 For Day 1 we pick max which is 50
 For Day 2 we can pick tasks 0 or 2
 Total XP = 50 + 11 = 61
 But Max XP we can get is
 Tasks 0 on 1st Day and Task 1 on 2nd Day

 So We need to generate all combination. thus we use recursion
 
 This is DP Problem as there are overlapping subproblems

*/ 
#include <iostream>
#include <vector>

// Hypothesis
//The Function retursn the max XP we get till day given that
//the ninja has done last day training of type lastDayTraining
int MaxXPRec(std::vector<std::vector<int>>tasks,int day,int lastDayTraining)
{
	//Base Case
	//ONly one day
	if(day == 0)
	{
		int maxE = -1;
		for(int i = 0; i < 3; i++)
		{
			if(i != lastDayTraining)
			{
				maxE = std::max(maxE,tasks[0][i]);
			}
		}
		return maxE;
	}
	
	//Induction
	int maxE = -1;
	for(int i = 0; i < 3; i++)
	{
		if(i != lastDayTraining)
		{
			maxE = std::max(tasks[day][i] + MaxXPRec(tasks,day - 1,i),maxE);
		}
	}
	return maxE;
}

// Hypothesis
//The Function retursn the max XP we get till day given that
//the ninja has done last day training of type lastDayTraining
//DP TOP DOWN
int MaxXPDP(std::vector<std::vector<int>>tasks,int day,int lastDayTraining,
			std::vector<std::vector<int>>&dp)
{
	//Base Case
	//ONly one day
	if(day == 0)
	{
		int maxE = -1;
		for(int i = 0; i < 3; i++)
		{
			if(i != lastDayTraining)
			{
				maxE = std::max(maxE,tasks[0][i]);
			}
		}
		return maxE;
	}
	
	if(dp[day][lastDayTraining] != -1)
	{
		return dp[day][lastDayTraining];
	}
	
	//Induction
	int maxE = -1;
	for(int i = 0; i < 3; i++)
	{
		if(i != lastDayTraining)
		{
			maxE = std::max(tasks[day][i] + MaxXPDP(tasks,day - 1,i,dp),maxE);
		}
	}
	return dp[day][lastDayTraining] = maxE;
	
}


// Hypothesis
//The Function retursn the max XP we get till day given that
//the ninja has done last day training of type lastDayTraining
//DP BOTTOMUP
//THe Answer is found at the last cell
//so a cell represents the max xp we can get till that day. which is represents on x axis
//in which we did training on day represented on y axis
int MaxXPDPBottom(std::vector<std::vector<int>>tasks)
{
	int n = tasks.size();
	//Base Case
	//ONly one day
	std::vector<std::vector<int>>dp(n,std::vector<int>(4,-1));
	//this means for day 0 what max training we can do given that we did traning 0 last
	dp[0][0] = std::max(tasks[0][1],tasks[0][2]);
	//this means for day 0 what max training we can do given that we did traning 1 last and so on
	dp[0][1] = std::max(tasks[0][0],tasks[0][2]);
	dp[0][2] = std::max(tasks[0][0],tasks[0][1]);
	//we havent started training
	dp[0][3] = std::max(tasks[0][0],std::max(tasks[0][1],tasks[0][2]));
	


	//Two Variables were changin in recursion
	//so we do 2 loops and 1 loop for work
	
	for(int day = 1; day < n; day++)
	{
		for(int last = 0; last < 4; last++)//4 means no training done so we can choose any
		{
			dp[day][last] = 0;
			for(int i = 0; i < 3; i++)
			{
				if(i != last)
				{
					dp[day][last] = std::max(tasks[day][i] + dp[day-1][i],dp[day][last]);
				}
			}
		}
	}
	return dp[n-1][3];
	

	
}

// Hypothesis - Space
//The Function retursn the max XP we get till day given that
//the ninja has done last day training of type lastDayTraining
//DP BOTTOMUP SPace Optimized
//THe Answer is found at the last cell
//so a cell represents the max xp we can get till that day. which is represents on x axis
//in which we did training on day represented on y axis
int MaxXPDPBottomSpace(std::vector<std::vector<int>>tasks)
{
	int n = tasks.size();
	//Base Case
	//ONly one day
	std::vector<std::vector<int>>dp(2,std::vector<int>(4,-1));
	//this means for day 0 what max training we can do given that we did traning 0 last
	dp[0][0] = std::max(tasks[0][1],tasks[0][2]);
	//this means for day 0 what max training we can do given that we did traning 1 last and so on
	dp[0][1] = std::max(tasks[0][0],tasks[0][2]);
	dp[0][2] = std::max(tasks[0][0],tasks[0][1]);
	//we havent started training
	dp[0][3] = std::max(tasks[0][0],std::max(tasks[0][1],tasks[0][2]));
	


	//Two Variables were changin in recursion
	//so we do 2 loops and 1 loop for work
	
	for(int day = 1; day < n; day++)
	{
		for(int last = 0; last < 4; last++)//4 means no training done so we can choose any
		{
			dp[day][last] = 0;
			for(int i = 0; i < 3; i++)
			{
				if(i != last)
				{
					dp[1][last] = std::max(tasks[day][i] + dp[0][i],dp[1][last]);
				}
			}
		}
		dp[0] = dp[1];
	}
	return dp[1][3];
	

	
}


int main()
{
	int n = 2;
	std::vector<std::vector<int>>tasks(n,std::vector<int>(3,0));
	tasks[0][0] = 10;
	tasks[0][1] = 50;
	tasks[0][2] = 1;
	tasks[1][0] = 11;
	tasks[1][1] = 100;
	tasks[1][2] = 10;
	std::vector<std::vector<int>>dp(n,std::vector<int>(4,-1));
	
	
	std::cout << "\n MAX XP = " << MaxXPRec(tasks,n - 1,3) << "\n"; 
	std::cout << "\n MAX XP = " << MaxXPDP(tasks,n - 1,3,dp) << "\n"; 
	std::cout << "\n MAX XP = " << MaxXPDPBottom(tasks) << "\n"; 
	std::cout << "\n MAX XP = " << MaxXPDPBottomSpace(tasks) << "\n"; 
	
}