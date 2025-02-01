/**
https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/
Problem Statement: Given a matrix mat of size N x M where every element 
is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is 
surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be 
surrounded by ‘X’ if there are ‘X’ at locations just below, 
just above just left, and just right of it.
*/

/**
 *  Think of 0 as surface and x as water. if surface is surrounded by water on all 4 sides then water will enter and
 * sub merge the island. If the island is at residing at the boundary i.e having drainage then all the connecting
 * islands wont have water or it will not stay
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<char>> SurroundingBFS(std::vector<std::vector<char>> &mat)
{
	//1.Check 
	if(mat.size() == 0 || mat[0].size() == 0)
	{
		return {};
	}
	
	int tr = mat.size();
	int tc = mat[0].size();
	
	std::vector<std::vector<int>> vis(tr,std::vector<int>(tc,0));
	std::vector<std::vector<char>> op = mat;
	std::queue<std::pair<int,int>>q;
	
	//2. Initialization. Exploring On Boundaries
	//1st and last column
	for(int i = 0; i < tr; i++)
	{
		if(mat[i][0] == 'O') 
		{
			q.push({i,0});
		}
		 if(mat[i][tc-1] == 'O')
		{
			q.push({i,tc-1});
		}
	}
	
	//Exploring 1st and last row
	for(int j = 0; j < tc; j++)
	{
		if(mat[0][j] == 'O')
		{
			q.push({0,j});
		}
		 if (mat[tr-1][j] == 'O')
		{
			q.push({tr - 1,j});
		}
	}
	
	
	//3.Explore
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,1,0,-1};
	while(q.empty() == false)
	{
		
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int ar = row + dr[i];
			int ac = col + dc[i];
			if(ar >=0 && ac >= 0 && ar < tr && ac < tc && vis[ar][ac] == 0 && mat[ar][ac] == 'O')
			{
				vis[ar][ac] = 1;
				
			}
		}
		
	}
	
	for(int i = 0; i <  tr; i++)
	{
		for(int j = 0; j < tc; j++)
		{
			if(vis[i][j] == 1 && mat[i][j] == 'O')
			{
				std::cout << "\n HERE \n";
				op[i][j] = 'X';
			}
		}
	}
	
	return op;
	
}


int main()
{
	 std::vector<std::vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

	
	auto lambdaElement = []<typename T>(const std::vector<T> & vec){
		
		std::for_each(vec.begin(),vec.end(),[](const T &elem){
			std::cout << elem << ",";
		});
		std::cout << "\n";
	};
	
	std::for_each(mat.begin(),mat.end(),lambdaElement);
	
	
	std::cout << "\n After Processing \n";
	
	std::vector<std::vector<char>> res = SurroundingBFS(mat);
	
	std::for_each(res.begin(),res.end(),lambdaElement);
	

	
	
  }