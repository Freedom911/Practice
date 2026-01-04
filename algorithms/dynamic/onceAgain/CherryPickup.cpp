/**
 *
 * Cherry Pickup . Its a 3d grid based problem.Given N*M matrix with Two people FinalRockstar and MsFinalRockstar
   are present at 0 and last  column of 1st row. The Matrix represents the chocolate present. we need to maximimize
   The number of choclate that can be picked in the path by both the people. If the cell is common only one can picked
   
   We will use our previous knowldge of finding maximum falling path. Here the destination is variable with two starting points
   Means. the end position could be anywhere in the last row.we could move down,downleft and down right
   
   So we need 4 variables in our function i1,j1 and i2,j2 representing position of both Rockstars.
   But if we look carefully i1 will always be equal to i2 as the row position is always incremented by 1
   
   so we take 3 vairableonly i1,j1,j2 that it
 */
 
 #include <iostream>
 #include <vector>
 
 //Hypothesis - This function is responible for getting max choclate by both rockstars
 //given that it starts from i1,j1 and i1,j2 
 // Sicne we start from last the answer is found by index at 0 but 0 is computed at bottom right
 int GetMaxTopDown(std::vector<std::vector<int>> &mat,int i1,int j1,int j2,int n,int m,std::vector<std::vector<std::vector<int>>> &dp)
 {
	 //Base Conditions
	 //INvalid Cases
	 if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
	 {
		 return -1e9;
	 }
	 //Valid Case
	 //if at last row then we are at destination
	 if(i1 == n-1)
	 {
		 
		 //if common cell then take only one
		 if(j1 == j2)
		 {
			 return mat[i1][j2];
		 }
		 else
		 {
			 return mat[i1][j1] + mat[i1][j2];
		 }
	 }
	 
	 if(dp[i1][j1][j2] != -1)
	 {
		 return dp[i1][j1][j2];
	 }
	 
	 //Induction
	 //Now we need to generate all combination of j1 and j2
	 //we know j1 can range from j1-1 to j1 + 1
	 //so we run two loops
	 int maxE = -1e9;
	 for(int dj1 = -1; dj1 <= 1; dj1++)
	 {
		 
		 for(int dj2 = -1; dj2 <= 1; dj2++)
		 {
			 int actj1 = dj1 + j1;
			 int actj2 = dj2 + j2;
			 
			 if(j1 == j2)
			 {
				 maxE = std::max(maxE,mat[i1][j2] + GetMaxTopDown(mat,i1 + 1,actj1,actj2,n,m,dp));
			 }
			 else
			 {
				 maxE = std::max(maxE,mat[i1][j1] + mat[i1][j2] +  GetMaxTopDown(mat,i1 + 1,actj1,actj2,n,m,dp));
			 }
		 }
		 
		 
	 }
	 
	 return dp[i1][j1][j2] = maxE;
	 
 }
 
 //Bottom Up Approach. we check how many variable were changing in top down.
 //Three so we declare 3d matrix. a cell 2,1,2 means the max choclate that can be picked up 
 //when FinalRockstar is at 2,1 and MsFinalRockstar is at 2,2
 int GetMaxBottomUp(std::vector<std::vector<int>> &mat)
 {
	 
	int n = mat.size();
    int m = mat[0].size();
	//dp of size n * m * m
	std::vector<std::vector<std::vector<int>>> dp(n,std::vector<std::vector<int>>(m,std::vector<int>(m,-1)));

	//So We start from last row as we expect out previous one is compute that is i + 1 is computed
	
	for(int i1 = n - 1; i1 >= 0; i1--)
	{
		//For Mr Final Rockstar
		for(int j1 = 0; j1 < m; j1++)
		{
			//For Ms Final Rockstar
			for(int j2 = m - 1; j2 >= 0; j2--)
			
			{
				//Initialization. Taking Help from Valid Base case from Top DOwn
				if(i1 == n- 1)
				{
					 //if common cell then take only one
					if(j1 == j2)
					{
						dp[i1][j1][j2] =  mat[i1][j2];
					}
					else
					{
						dp[i1][j1][j2] =  mat[i1][j1] + mat[i1][j2];
					}
					continue;
				}
				
				 int maxE = -1e9;
				 for(int dj1 = -1; dj1 <= 1; dj1++)
				 {
		 
					 for(int dj2 = -1; dj2 <= 1; dj2++)
					 {
						 int actj1 = dj1 + j1;
						 int actj2 = dj2 + j2;
						 
						 //check Validity
						  if( i1 + 1 >= n || actj1 < 0 || actj1 >= m || actj2 < 0 || actj2 >= m)
						 {
							dp[i1][j1][j2] = std::max((int)-1e9,dp[i1][j1][j2]);
					     }
						 else
						 {
 
							 if(j1 == j2)
							 {
								 dp[i1][j1][j2] = std::max(dp[i1][j1][j2],mat[i1][j2] + dp[i1+1][actj1][actj2]);
							 }
							 else
							 {
								 dp[i1][j1][j2] = std::max(dp[i1][j1][j2],mat[i1][j1] + mat[i1][j2] +  dp[i1+1][actj1][actj2]);
							 }
						 }
					 }
		 
				}
	 			
			}
			
		}
	}
	
	return dp[0][0][m-1]; 
	
	 
 }
 
 int main()
 {
	 // Define the grid as a 2D vector
    std::vector<std::vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };
	
	

    int n = matrix.size();
    int m = matrix[0].size();
	//dp of size n * m * m
	std::vector<std::vector<std::vector<int>>> dp(n,std::vector<std::vector<int>>(m,std::vector<int>(m,-1)));

    // Call the maximumChocolates function and print the result
    std::cout << GetMaxTopDown(matrix,0,0,m-1,n,m,dp) << "\n";
	std::cout << GetMaxBottomUp(matrix) << "\n";
 }
 
 
