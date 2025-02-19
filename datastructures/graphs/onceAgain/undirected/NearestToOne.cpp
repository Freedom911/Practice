/**
https://takeuforward.org/graph/distance-of-nearest-cell-having-1/
Problem Statement: Given a binary grid of N*M.
Find the distance of the nearest 1 in the grid for each cell.

The distance is calculated as |i1  - i2| + |j1 - j2|, 
where i1, j1 are the row number and column number of the current cell,
 and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//so hamlog kya karenge
//see we will take all one in the grid and simultaneously expand them 
//to get to 0. so all those places where we have 1 initially we have output as 0
//because they are nerest to themself
//so basically it is level.we are basically returning level only.we use bfs as we expand parallely
//we can move in  4 directions like in rotten orange
struct Cell
{
	int r;
	int c;
	int dist;
};
std::vector<std::vector<int>>nearest(const std::vector<std::vector<int>> &grid)
{
	//1.check
	if(grid.size() == 0 || grid[0].size() == 0)
	{
		return {};
	}
	
	int tr = grid.size();
	int tc = grid[0].size();
	
	std::vector<std::vector<int>>vis(tr,std::vector<int>(tc,0));
	std::vector<std::vector<int>>op(tr,std::vector<int>(tc,0));
	std::queue<Cell> q;
	
	
	
	//2.Initialization
	//push all one
	for(int i = 0; i < tr; i++)
	{
		for(int j = 0; j < tc; j++)
		{
			if(grid[i][j] == 1)
			{
				q.push({i,j,0});
				vis[i][j] = 1;
			}
		}
	}
	
	//adj list for 4 directions
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,1,0,-1};
	//NOw Start exploring the deep sea
	while(q.empty() == false)
	{
		Cell c = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int ar = c.r + dr[i];
			int ac = c.c + dc[i];
			
			//Check Validity
			if(ar >= 0 && ar < tr && ac >=0 && ac < tc && vis[ar][ac] == 0 && grid[ar][ac] == 0)
			{
				int newDist = c.dist + 1;
				vis[ar][ac] = 1;
				q.push({ar,ac,newDist});//increment the distance/level/height
						//output row and col will be at that dist
				op[ar][ac] = newDist;
			}
		}	
	}
	
	return op;
	
	
	
}




int main()
{
    std::vector<std::vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	auto lambdaElement = [](const std::vector<int> & vec){
		
		std::for_each(vec.begin(),vec.end(),[](const int &elem){
			std::cout << elem << ",";
		});
		std::cout << "\n";
	};
	
	std::for_each(grid.begin(),grid.end(),lambdaElement);
	
	std::vector<std::vector<int>> op = nearest(grid);
	std::cout << "\n Output After Operation \n";
	std::for_each(op.begin(),op.end(),lambdaElement);
	
	
  }
