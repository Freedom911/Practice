/**
 * https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/
 * G-36: Shortest Distance in a Binary Maze
 *
 * Problem Statement:
 * Given an n * m matrix grid where each element can either be 0 or 1. 
 * You need to find the shortest distance between a given source cell to a destination cell.
 * The path can only be created out of a cell if its value is 1.If the path is not possible
 * between the source cell and the destination cell, then return -1.
 * Note: You can move into an adjacent cell if that adjacent cell is filled with element 1.
 * Two cells are adjacent if they share a side. In other words, 
 * you can move in one of four directions, Up, Down, Left, and Right.
 *
 * We apply Dijkstra Algorithm. Herewehave two dimension
 *
 * Rest is same. Here the distance is one basically.
 *
 * The question here is do we need priority queue?
 * Answer to that is no. since we have unit weight and weinsert
 * in queue in order like first we insert 0 distance element
 * and so on
 *
 * We can see that the distances are increasing monotonically (because of constant edge weights).
 * Since greater distance comes at the top automatically, 
 * so we do not need the priority queue as the pop operation will always pop the smaller distance 
 * which is at the front of the queue. 
 *
 * eg phele 0,0 se 1 distnace wala queue m dalega then 2 distance wala and so on. jo pick hoga wo
 * smallest distance se hi hoga. if the weight was not constant then we would have required pq
 */


#include <iostream>
#include <queue>
#include <vector>

struct Cell
{
    int row;
    int column;
};

int shortestPath(std::vector<std::vector<int>> &grid,const std::pair<int, int> &source,
const std::pair<int, int> &destination)
{
  if(source.first == destination.first && source.second == destination.second)
  {
      return 0;
  }

  //Applying Dijkstra uncle algo
  std::queue<std::pair<int,Cell>> q; //dist,row,col
  int tr = grid.size();
  int tc = grid[0].size();
  //not taking int max as we do + 1 check which causesoverflow
  std::vector<std::vector<int>> dist(tr,std::vector<int>(tc,1e9));  //Initializing in queue and distance vector
  q.push({0,{source.first,source.second}});
  dist[source.first][source.second] = 0;

  int dr[4] = {-1,0,1,0};
  int dc[4] = {0,1,0,-1};

  while(q.empty() == false)
  {
      int d = q.front().first;
      Cell cell = q.front().second;
      q.pop();

      //add list will be 4 direction
      for(int i = 0; i < 4; i++)
      {
          int ar = cell.row + dr[i];
          int ac = cell.column + dc[i];
          if(ar >= 0 && ac >=0 && ar < tr && ac < tc && grid[ar][ac] == 1 && 
             d + 1 < dist[ar][ac])
          {
              //return as soon as we get the destination because we know it isconstant weight
              //and further entries would be greater only
              if(ar == destination.first && ac == destination.second)
              {
                  return d + 1;
              }

              dist[ar][ac] = d + 1;
              q.push({d + 1,{ar,ac}});
          }
      }

  }

  return -1;//not found
}
int main()
{
    // Driver Code.

    std::pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    std::vector<std::vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};


    int res = shortestPath(grid, source, destination);

    std::cout << res;
    std::cout << std::endl;

    return 0;
}
