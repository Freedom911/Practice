  /**
    *
	https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/
	
	We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.

	At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
	
	Greedy Approach Here it will not work
	
	Previous Knowledge
	We gonna use our previous knowledge of finding maximum in triangle matrix.
	
	Here are two changes Required
	1. The answer can be found at any column of starting or ending row. This means 
	starting and ending position is not fixed.
	2. We have three movement 
	*/
  
  #include <iostream>
  #include <vector>
  
  //Hypothesis - This Function Returns Maximum Path Sum 
  int TotalDPTopDownHelper(std::vector<std::vector<int>> &mat,int currRow,int currCol,std::vector<std::vector<int>> &dp)
  {
	  //Base Conditions
	  if(currRow < 0 || currRow >= mat.size() || currCol < 0 || currCol >= mat[0].size())
	  {
		  return -1e9;
	  }
	  
	  if(currRow == 0)
	  {
		  return mat[currRow][currCol];
	  }
	  
	  if(dp[currRow][currCol] != -1)
	  {
		  return dp[currRow][currCol];
	  }
	  
	  int up = mat[currRow][currCol] + TotalDPTopDownHelper(mat,currRow-1,currCol,dp);
	  int upleft = mat[currRow][currCol] + TotalDPTopDownHelper(mat,currRow-1,currCol-1,dp);
	  int upright = mat[currRow][currCol] + TotalDPTopDownHelper(mat,currRow-1,currCol+1,dp);
	  
	  //Induction - IN induction we move up or move left which is opposite
					  //up                                //left
	  return dp[currRow][currCol] = std::max(up,std::max(upleft,upright));
  }
  
  int TotalDPTopDown(std::vector<std::vector<int>> &mat)
  {
	  int n = mat.size();
	  int m = mat[0].size();
	  //we need to try for all j
	  std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1)); // Memoization table to store computed results
    
	  int maxE = -1e9;
	  for(int j = 0; j < m; j++)
	  {
		  maxE = std::max(maxE,TotalDPTopDownHelper(mat,n-1,j,dp));
	  }
	  return maxE;
  }
  
  int TotalDPBottomUp(std::vector<std::vector<int>> &mat)
  {
	  	  int n = mat.size();
	  int m = mat[0].size();	
	  std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1e9));
  
	  
	  for(int i = 0; i < n; i++)
	  {
		for(int j = 0; j < m; j++)  
		{
		  {
			  if(i == 0)
			  {
				  dp[i][j] = mat[0][j];//std::max(dp[i][k],mat[0][k]);
				  continue;
			  }
			  
			  int up = -1e9;
			  
			  int upleft = -1e9;
			  
			  int upright = -1e9;
			  
			  
			  if(i > 0)
			  {
				  up = mat[i][j] + dp[i-1][j];
			  
				  if(j - 1 >= 0)
					upleft = mat[i][j] + dp[i-1][j-1];
			  
				  if(j + 1 < m)
			        upright = mat[i][j] + dp[i-1][j+1];
			  
					dp[i][j] = std::max(up,std::max(up,std::max(upleft,upright)));
		  }
		  
	  }
	  }
	  }
	  
	  int maxE = -1e9;
	  for(int i = 0; i < m; i++)
	  {
		  maxE = std::max(maxE,dp[n-1][i]);
	  }
	  
	  return maxE;
	  
  }
  
  int main()
  {
	   // Define the matrix as a 2D vector
    std::vector<std::vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
								
	std::cout << TotalDPTopDown(matrix) << "\n";
	std::cout << TotalDPBottomUp(matrix) << "\n";
  }	