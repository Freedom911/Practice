//Number of enclaves
//https://takeuforward.org/graph/number-of-enclaves/
//Problem Statement: You are given an N x M binary matrix grid, 
//where 0 represents a sea cell and 1 represents a land cell. 
//A move consists of walking from one land cell to another
//adjacent (4-directionally) land cell or walking off the boundary of the grid. 
//Find the number of land cells in the grid for which we 
//cannot walk off the boundary of the grid in any number of mov
//Problem very similar to Surrounding X
//so basically corner par jo 1 h usse we can exit. these are laddars to other world
//now any cell having 1 and connected to 1 oncorner canmove out of the world
// We have to calculate where we have 1 but cant exit
//eg 0,0,0,0
//   1,0,1,0
//   0,1,1,0
//   0,0,0,0

//From (1,0) we can move out.
//Rest one are not connectedin4 directions with this. So we hhave 3 ways were we can stay
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int NumberOfEnclaves(std::vector<std::vector<int>> &grid)
{
  std::queue<std::pair<int,int>> q;
  int tr = grid.size();
  int tc = grid[0].size();
  int vis[tr][tc] = {0};
  //1st step initialization
  //for 1st row ,last row,1st col and last col
  for(int i = 0; i < tr; i++)
  {
      for(int j = 0; j < tc; j++)
      {
          if(i == 0 || i == tr - 1 || j == 0 || j == tc - 1)
          {
              if(grid[i][j] == 1)
              {
                  q.push({i,j});
                  vis[i][j] = 1;
              }
          }

      }
  }
  
  int dr[4] = {-1,0,1,0};
  int dc[4] = {0,1,0,-1};
  while(q.empty() == false)
  {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      //4 directions
      for(int i = 0; i < 4; i++)
      {
          int ar = r + dr[i];
          int ac = c + dc[i];

          //Validity Check\
          //Connect all ones 
          if(ar >= 0 && ar < tr && ac >=0 && ac < tc && vis[ar][ac] == 0 && grid[ar][ac] == 1)
          {
              vis[ar][ac] = 1;
              q.push({ar,ac});
          }

      }
  }

  int cnt = 0;

  //Count where vis map is 0 and gridis 1
  for(int i = 0; i < tr; i++)
  {
      for(int j = 0; j < tc; j++)
      {
          if(grid[i][j] == 1 && vis[i][j] == 0)
          {
              cnt++;
          }
      }
  }

    return cnt;

}

int main()
{
    std::vector<std::vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

   //Printing grid
   auto lambdaPrint = []<typename T>(const std::vector<T> & elem){
       std::for_each(elem.begin(),elem.end(),[](const T &val){
           std::cout << val << ",";
       });
       std::cout << "\n";
   };

   std::cout << "\n GRID = ";
   std::for_each(grid.begin(),grid.end(),lambdaPrint);

   std::cout << "\n Number ofenclaves " << NumberOfEnclaves(grid) << "\n";
}
