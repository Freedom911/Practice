//Given a 2d grid with 2,1,0. 2 denotes rotten oranges 1 fresh 0 no orrange
//return the minimum time such that all oranges get rotten. in the end all oranges should be rotten
//Hre we will use BFS. as DFS will go to depth first .we need to explore nodes with rotten oranges parallely
//So here we just use dfs.
//Here time act as level

#include <iostream>
#include <queue>
#include <vector>

//return -1 if not all new oranges rotten
int orangesRotting(std::vector<std::vector<int>> & grid)
{
    std::vector<std::vector<int>> gridCopy = grid;
    std::queue<std::pair<int,int>>q;

    int tr = grid.size();
    int tc = grid[0].size();

    //1st step is to initialize queue
    //we push all entries where the orange is rotten
    int totalFresh = 0, rotten = 0;
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(gridCopy[i][j] == 2)
            {
                q.push({i,j});
            }

            else if(gridCopy[i][j] == 1)
            {
                totalFresh++;
            }
        }
    }


    //now explore
    //Initially Time is 0
    int initTime = 0;

    while(q.empty() == false)
    {
        int totalChildren = q.size();

        for(int i = 0; i < totalChildren; i++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};

            for(int j = 0; j < 4; j++)
            {
                int ar = r + dr[j];
                int ac = c + dc[j];

                //Checking Validity
                if(ar >= 0 && ac >= 0 && ar < tr && ac < tc && gridCopy[ar][ac] == 1)
                {
                    gridCopy[ar][ac] = 2;
                    rotten++;
                    q.push({ar,ac});
                }
            }

        }
         
        //Means we have more to explore so increment the time
        //jab queue m push kiya means more explore karna h
        //This condition only fails in last iteration
        //in that case we dont want to increase inittime
        if(q.size() > 0)
        {
            initTime++;
        }


    }


    return totalFresh == rotten ? initTime -1 : -1;
}

int main()
{
    std::vector<std::vector<int>> v
    {{0}
        //{ 2,0,0},
        //{ 0,0,0},
        //{ 0,0,0}
    };

    std::cout << "\n TOTAL Time = " << orangesRotting(v);
}
