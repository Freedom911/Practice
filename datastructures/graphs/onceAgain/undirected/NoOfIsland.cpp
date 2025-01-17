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

void BFS()
{

}

int GetIslands(std::vector<std::vector<char>> grid)
{
    if(grid.size() == 0)
    {
        return -1;
    }
    int tr = grid.size();
    int tc = grid[0].size();
    
    //Initialization in queue
    std::vector<std::vector<int>> visited(tr,std::vector<int>(tc,0));
    std::queue<std::pair<int,int>>q;
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(grid[i][j] == '1')
            {
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    //for all components/lands
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
               if(visited[i][j] == 0 &&  grid[i][j] == '1') //it is a island
               {
                   BFS(i,j,q,visited,grid);
                   cnt++;
               }
          
        }
    }

    while(q.empty() == false)
    {
       int row = q.front().first;
       int col = q.front().second;
       q.pop();

       for(int i = -1; i <= 1; i++)
       {
           for(int j = -1; j <= 1; j++)
           {
               int actRow = row + i;
               int actCol = col + j;

               //validity Check
               if(actRow >= 0 && actCol >= 0 && actRow < tr && actCol < tc && visited[actRow][actCol] == 0 &&
                  grid[actRow][actCol] == '1') //it is a island
               {
                      q.push({actRow,actCol});
                      visited[actRow][actCol] = 1;
               }
           }
       }

    } 
}

int main()
{
}

