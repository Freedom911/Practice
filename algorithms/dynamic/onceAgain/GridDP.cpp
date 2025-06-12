/**
  Grid On Unique Path DP
  Given a M * N matrix. Find the total unique paths we can reach from 0,0
  If min distance was asked we would have used Dijikstra which is graph based
  Grreedy allgo
  
  So we gonna solve using Recursion. we start from last node and decrement row and column
  other way could be we star from 0. but in top down we then need to start from last node in table
  So I prefer going from last in recursion so that it starts from 0 in tabular
  .This is a DP problem as there happens overlapping
  
  */
  #include <iostream>
  #include <vector>
  
  //Hypothesis - This Function Returns Total number of unique till 0 till curr row
  int TotalRec(int currRow,int currCol)
  {
	  //Base Conditions
	  if(currRow < 0 || currCol < 0)
	  {
		  return 0;
	  }
	  if (currRow == 0 && currCol == 0)
	  {
		  return 1;
	  }
	  
	  //Induction - IN induction we move up or move left which is opposite
					  //up                                //left
	  return TotalRec(currRow - 1,currCol) + TotalRec(currRow,currCol - 1);
  }
  
  //Hypothesis - This Function Returns Total number of unique till 0 till curr row
  int TotalDPTopDown(int currRow,int currCol,std::vector<std::vector<int>> &dp)
  {
	  //Base Conditions
	  if(currRow < 0 || currCol < 0)
	  {
		  return 0;
	  }
	  if (currRow == 0 && currCol == 0)
	  {
		  return 1;
	  }
	  
	  if(dp[currRow][currCol] != -1)
	  {
		  return dp[currRow][currCol];
	  }
	  
	  //Induction - IN induction we move up or move left which is opposite
					  //up                                //left
	  return dp[currRow][currCol] = TotalDPTopDown(currRow - 1,currCol,dp) + TotalDPTopDown(currRow,currCol - 1,dp);
  }
  
  //BOttom Up
  int TotalDPBottom(int m,int n)
  {

	  if(m == 0)
	  {
		  return 0;
	  }
	  

	  if(n == 0)
	  {
		  return 0;
	  }
	  
	  std::vector<std::vector<int>> dp(m + 1,std::vector<int>(n + 1,0));
	  dp[0][0] = 1;
	  
	  for(int i = 0; i <=m; i++)
	  {
		  for(int j = 0; j <= n; j++)
		  {
			  if(i == 0 && j == 0)
				  continue;
			  
			  int up = 0,left = 0;
			  if( i > 0)
			  {
				  up = dp[i-1][j];
			  }
			  
			  if (j > 0 )
			  {
				  left = dp[i][j-1];
			  }
			  dp[i][j] = up + left;
			  
		  }
	  }
	  
	  return dp[m][n];
  }
  
  //BOttom Up
  int TotalDPBottomSpace(int m,int n)
  {

	  if(m == 0)
	  {
		  return 0;
	  }
	  

	  if(n == 0)
	  {
		  return 0;
	  }
	  
	  std::vector<int> prev(n + 1,0);
	  
	  
	  for(int i = 0; i <=m; i++)
	  {
		  std::vector<int> currRow(n + 1,0);
		  for(int j = 0; j <= n; j++)
		  {
			  if(i == 0 && j == 0)
			  {
				  currRow[i] = 1;
				  continue;
			  }
			  
			  int up = 0,left = 0;
			  if( i > 0)
			  {
				  up = prev[j];
			  }
			  
			  if (j > 0 )
			  {
				  left = currRow[j-1];
			  }
			  
			  currRow[j] = up + left;
			  
		  }
		  prev = currRow;
	  }
	  
	  return prev[n];
  }
  
  int main()
  {
	   int m = 2;
    int n = 2;
	  std::vector<std::vector<int>> dp(m,std::vector<int>(n,-1));

    // Call the countWays function and print the result.
    std::cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << TotalRec(m-1, n-1) << std::endl;
	    std::cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << TotalDPTopDown(m-1, n-1,dp) << std::endl;
		    std::cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << TotalDPBottom(m-1, n-1) << std::endl;
			std::cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << TotalDPBottomSpace(m-1, n-1) << std::endl;

    return 0;
  }