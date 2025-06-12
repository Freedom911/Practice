/**
  Given An Array we need to Find the maximum sum we can get from subarray
  such that no two elements are adjacent.
  THis wont be solved by greedy as greey we might be tempted to pick max elements
  eg 
  2,3,20,4
  starting with 0th index. greedy would have picked 3 but after picking it we wont beable to pick 20
  which is clearly the max.
  
  Solution
  The solution we can think of is generating all subarray where elements are not adjacent
  then we pick the max of those
  
  So Recursive solution first we devise then we convert to dp as there is overlapping in subproblems
  */
  #include <iostream>
  #include <vector>
  
  // Hypothesis
  //this function returns the max sum by including/not including the elements
  int MaxSumRec(std::vector<int> &arr,int index)
  {
	  //Base Cases
	  if(index == 0) // means we have not included element 1st. so we can simply return 0th element
	  {
		  return max(0,arr[index])//i know arr[index] will be greater but just to explain i am writing max
	  }
	  
	  //Invalid case
	  if(index < 0)
	  {
		  return 0;
	  }
	  
	  //Induction -  we are doing choice based recursion aditya verma wala
	  //1st case INclude index element
	  //why 2? because we cant choose - 1 due to adj since we have choosen index
	  int inc = arr[index] + MaxSumRec(arr,index - 2);
	  //2nd Case Dont include indexth element
	  int dont = 0 + MaxSumRec(arr,index - 1);
	  
	  //Just pick the max one
	  return std::max(inc,dont);
	  
  }
  
  // DP SOLUTION TOP DOWN
  //this function returns the max sum by including/not including the elements
  int MaxSumDP(std::vector<int> &arr,int index,std::vector<int> &dp)
  {
	  //Base Cases
	  if(index == 0) // means we have not included element 1st. so we can simply return 0th element
	  {
		  return max(0,arr[index])//i know arr[index] will be greater but just to explain i am writing max
	  }
	  
	  //Invalid case
	  if(index < 0)
	  {
		  return 0;
	  }
	  
	  if(dp[index] != -1)
	  {
		  return dp[index];
	  }
	  
	  //Induction -  we are doing choice based recursion aditya verma wala
	  //1st case INclude index element
	  //why 2? because we cant choose - 1 due to adj since we have choosen index
	  int inc = arr[index] + MaxSumRec(arr,index - 2);
	  //2nd Case Dont include indexth element
	  int dont = 0 + MaxSumRec(arr,index - 1);
	  
	  //Just pick the max one
	  return dp[index] = std::max(inc,dont);
	  
  }
  
  // DP SOLUTION Bottom Up 
  //this function returns the max sum by including/not including the elements
  int MaxSumBottomUP(std::vector<int> &arr,int index)
  {

	  
	  std::vector<int> dp(arr.size(),0);
	  
	  dp[0] = arr[index];
	  
	  for(int i = 1; i < arr.size(); i++)
	  {
		   int inc = arr[index];
			if(i > 1)
		   inc+= dp[i - 2];
			//2nd Case Dont include indexth element
			int dont = 0 + dp[i - 1];
	  
	  //Just pick the max one
	   dp[index] = std::max(inc,dont);
	  }
		return dp[arr.size() - 1];
  }
  
    // DP SOLUTION Bottom Up  Space Optimized
  //this function returns the max sum by including/not including the elements
  int MaxSumBottomUpSpaceOptimized(std::vector<int> &arr,int index)
  {

	  
	  std::vector<int> dp(arr.size(),0);
	  
	  int a = 0;
	  int b = arr[index];
	  int c = 0;
	  
	  
	  for(int i = 1; i < arr.size(); i++)
	  {
		   int inc = arr[index];
			if(i > 1)
		   inc+= a;
			//2nd Case Dont include indexth element
			int dont = 0 + b;
	  
	  //Just pick the max one
	   c = std::max(inc,dont);
	   
	   a = b;
	   b = c;
	  }
		return c;
  }
  
  
  int main()
  {
  }
  