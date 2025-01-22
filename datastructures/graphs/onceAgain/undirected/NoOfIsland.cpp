//https://takeuforward.org/data-structure/number-of-islands/
// This problem is a real application of graph. 
//given a grid of size NxM consisting of 0 water 1 land
//find the number of island
//an island is surrounded by water and connected lands formed in 8 directions
//It is like number of provinces
//we will use bfs/dfs 
//Input will be a 2d vector of char of 0 and 1
//output needs to be islands
//In the queue we push pair
//so a pair means r,c so for a matrix 3x3 we have 9 nodes
//we will have visisted of 2d
//we wont be given adj list. adj list will be in 8 direction
//eg adj node of 0,0 will be thesemany
//               -1,1     0,1   1,1
//               -1,0     0,0   1,0
//               -1,-1    0,-1  1,-1
// so r will vary from -1 to 1 and col will vary from -1 to 1

#include <iostream>
#include <vector>
#include <queue>

void dfs(int row,int col,std::vector<std::vector<int>>&visited,std::vector<std::vector<char>> &grid)
{
    visited[row][col] = 1;
    int tr = grid.size();
    int tc = grid[0].size();

    //now to get adjaceny list we know for a cell there will be 8 directions
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int actRow = row + i;
            int actCol = col + j;

            //check if the index is valid
            if(actRow >= 0 && actCol >= 0 && actRow < tr && actCol < tc && visited[actRow][actCol] == 0 &&
                    grid[actRow][actCol] == '1')
            {
                //modifying the grid as well
                dfs(actRow,actCol,visited,grid);
            }

        }
    }
}

void bfs(int sr,int sc,std::vector<std::vector<int>>&visited,std::vector<std::vector<char>> &grid)
{
    std::queue<std::pair<int,int>>q;
    q.push({sr,sc});
    visited[sr][sc] = 1;
    int tr = grid.size();
    int tc = grid[0].size();

    while(q.empty() == false)
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        //now to get adjaceny list we know for a cell there will be 8 directions
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                int actRow = row + i;
                int actCol = col + j;
                if(actRow >= 0 && actCol >= 0 && actRow < tr && actCol < tc && visited[actRow][actCol] == 0 &&
                        grid[actRow][actCol] == '1')
                {
                    visited[actRow][actCol] = 1;
                    q.push({actRow,actCol});

                }
            }
        }


    }

}

//Gets The number of island
int GetIslands(std::vector<std::vector<char>> &grid)
{
    int tr = grid.size();
    int tc = grid[0].size();

    std::vector<std::vector<int>>visited(tr,std::vector<int>(tc,0));
    int cnt = 0;
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(visited[i][j] == 0 && grid[i][j] == '1') //means land not visited yet
            {
                //dfs(i,j,visited,grid);
                bfs(i,j,visited,grid);
                cnt++;
            }
        }
    }

    return cnt;



}

int main()
{
    // n: row, m: column
    std::vector<std::vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
            {'0', '0', '1', '1', '0', '1', '0'}
    };


    std::cout << GetIslands(grid) << "\n";
}

