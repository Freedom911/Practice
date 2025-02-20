/**
 * https://takeuforward.org/data-structure/number-of-distinct-islands/
 *
 * Problem Statement: Given a boolean 2D matrix grid of size N x M. 
 * You have to find the number of distinct islands where a group of connected 
 * 1s (horizontally or vertically) forms an island. Two islands are considered 
 * to be distinct if and only if one island is equal to another (not rotated or reflected).
 *
 * Solution - 
 * so first we need to know how to get total island. which is easy. we start with every cell
 * and we connect island in 4 directions
 * 
 * Now if we have
 * 1 1 0
 * 0 0 0
 * 1 1 0
 *
 * Out of total 2 island([0,0],[0,1]) and ([2,0] and [2,1]) we have 1 distinct island
 * because shapewise it is same
 *
 * so how we say the 2 island are same.
 * we use unordered set and store vector of pair
 * also we subtract the base element from destination
 * [0,0] - [0,0] = [0,0]
 * [0,1] - [0,0] = [0,1]
 *
 * and 
 * [2,0] - [2,0] = [0,0]
 * [2,1] - [2,0] = [0,1]
 *  
 *  So Both Turns out to be same. Hip Hip Hurray
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

//it will do dfs traversal and store in vector
void dfs(const int &baseRow,const int &baseCol,int row,int col, std::vector<std::vector<int>> &vis,
         const std::vector<std::vector<int>>&grid,std::vector<std::pair<int,int>> & res)
{
  vis[row][col] = 1;
  //Storing in result after subtracting from base col
  res.push_back({row - baseRow,col - baseCol});
  int tr = grid.size();
  int tc = grid[0].size();
  int dr[4] = {-1,0,1,0};
  int dc[4] = {0,1,0,-1};

  for(int i = 0; i < 4; i++)
  {
      int ar = dr[i] + row;
      int ac = dc[i] + col;
      
      //Validity Check
      if(ar >= 0 && ac >= 0 && ar < tr && ac < tc && vis[ar][ac] == 0 && grid[ar][ac] == 1)
      {
          dfs(baseRow,baseCol,ar,ac,vis,grid,res);
      }
  }
}

int countDistinctIslands(const std::vector<std::vector<int>>&grid)
{
    int tr = grid.size();
    int tc = grid[0].size();
    std::vector<std::vector<int>> vis(tr,std::vector<int>(tc,0));
    std::set<std::vector<std::pair<int,int>>>us;


    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(vis[i][j] == 0 && grid[i][j] == 1) // it is land
            {
                std::vector<std::pair<int,int>>res;
                int br = i;
                int bc = j;
                dfs(br,bc,i,j,vis,grid,res);
                us.insert(res);
            }
        }
    }

    return us.size();
}

int main()
{
    std::vector<std::vector<int>> grid
    {
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

  std::cout << countDistinctIslands(grid) << "\n";;
}
