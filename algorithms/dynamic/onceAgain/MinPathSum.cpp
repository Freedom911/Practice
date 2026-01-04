//https://leetcode.com/problems/minimum-path-sum/
//https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11
//DP 10. Minimum Path Sum in Grid
//So we are at 0,0 we have to find the min path sum till last node of the matrix bottom most right
//I Will solve using dp and also i give solution using dijikstra. as we can solve with this method also
//we use pqueue to pick the min weight

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //Hypothesis - This Function Returns the the min Path Sum till i and j
    int minPathSumRec(vector<vector<int>>& grid,int i , int j)
    {
       //Base condition
       if(i == 0 && j == 0)
       {
          return grid[0][0];
       }
       else if(i < 0 || j < 0)
       {
           //assign Penalty
           return 1e9;
       }

       int up = grid[i][j] + minPathSumRec(grid,i-1,j);
       int left = grid[i][j] + minPathSumRec(grid,i,j-1);
       return std::min(up,left);
    }


    //Hypothesis - This Function Returns the the min Path Sum till i and j
    int minPathSumTopDown(vector<vector<int>>& grid,int i , int j,vector<vector<int>> &dp)
    {
       //Base condition
       if(i == 0 && j == 0)
       {
          return grid[0][0];
       }
       else if(i < 0 || j < 0)
       {
           //assign Penalty
           return 1e9;
       }
       else if(dp[i][j] != -1)
       {
           return dp[i][j];
       }

       int up = grid[i][j] + minPathSumTopDown(grid,i-1,j,dp);
       int left = grid[i][j] + minPathSumTopDown(grid,i,j-1,dp);
       return dp[i][j] = std::min(up,left);
    }

    //Hypothesis - This Function Returns the the min Path Sum till i and j
    int minPathSumBottomUp(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        //return minPathSumRec(grid,n-1,m-1);
        vector<vector<int>> dp(n,std::vector<int>(m,-1));

        for(int i = 0; i < n; i++)
        {

            int up = 0,left = 0;
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                else
                {
                    up = grid[i][j];
                    if(i - 1 >= 0)
                    {
                        up +=  dp[i-1][j];
                    }
                    else
                    {
                        up += 1e9;
                    }
                    left = grid[i][j];
                    if(j - 1 >= 0)
                    {
                        left +=  dp[i][j-1];
                    }
                    else
                    {
                        left += 1e9;
                    }
                }
                dp[i][j] = std::min(up,left);
            }
        }

       return dp[n-1][m-1];
    }


        //as we can see we only need previous
    int minPathSumBottomUpSpace(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        //return minPathSumRec(grid,n-1,m-1);
        vector<int> prevDP(m,-1);
        vector<int> currDP(m,-1);

        for(int i = 0; i < n; i++)
        {

            int up = 0,left = 0;
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    currDP[j] = grid[i][j];
                    prevDP[j] = grid[i][j];
                    continue;
                }
                else
                {
                    up = grid[i][j];
                    if(i - 1 >= 0)
                    {
                        up +=  prevDP[j];
                    }
                    else
                    {
                        up += 1e9;
                    }
                    left = grid[i][j];
                    if(j - 1 >= 0)
                    {
                        left +=  currDP[j-1];
                    }
                    else
                    {
                        left += 1e9;
                    }
                }
                currDP[j] = std::min(up,left);
            }
                prevDP = currDP;
        }

       return currDP[m-1];
    }


    int MinimumEffort(std::vector<std::vector<int>> &heights)
{
    //min heap
    std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>,std::greater<std::pair<int,std::pair<int,int>>>>pq;

    int tr = heights.size();
    int tc = heights[0].size();
    std::vector<std::vector<int>> bestEffort(tr,std::vector<int>(tc,1e9));

    //adj list will be for directions
    int dr[2] = {1,0};
    int dc[2] = {0,1};

    //Initialization part
    pq.push({heights[0][0],{0,0}});
    bestEffort[0][0] = heights[0][0];

    //start processing
    while(pq.empty() == false)
    {
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int currentEffort = pq.top().first;

        pq.pop();

        //as told earlier and i have explaiend in one note
        //that we stop when we pop the element from ququq and we get the destination
        //because this means we have got the best effort till now for the destination
        //and aage koi mai ka lal nahi h ise better hone ka
        if(row == tr - 1 && col == tc - 1)
        {
            return currentEffort; //this will automatically be having the max effort which is the minimum one
        }

        for(int i = 0; i < 2; i++)
        {
            int ar = row + dr[i];
            int ac = col + dc[i];

            //check validity
            if(ar >= 0 && ac >=0 && ar < tr && ac < tc)
            {
                int effort = std::abs(heights[ar][ac] + bestEffort[row][col]);


                //we need to update in the bestaffort array if it is better
                //also we wont explore if the best effort array is less
                //there is no point. as we ill keep on looping
                if(effort < bestEffort[ar][ac])
                {
                    bestEffort[ar][ac] = effort;
                    //also add in pq
                    pq.push({effort,{ar,ac}});
                }

            }
        }
    }
    return -1;
}




    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<int>> dp(n,vector<int> (m,-1));
        //return minPathSumTopDown(grid,n-1,m-1,dp);
        //return minPathSumBottomUpSpace(grid);
        return MinimumEffort(grid);
    }
};



int main()
{
    vector<vector<int>> grid{{0}};
    Solution s;
    std::cout << s.minPathSum(grid) << "\n";
}
