//Graph can be represent by Adjacency  list or matrix
//graph allows to represent real world problems
//https://www.geeksforgeeks.org/graph-and-its-representations/
//We are using vector for adjancey list impelemntation
//because of cache friendliness
//
//          0---1----4
//          |  /|
//          | / |
//          2---3

//So adjacency list will have
//0-1-2
//1-0-2-3-4
//2-0-1-3
//3-1-2
//4-1
#include <iostream>
#include <vector>

void addEdge(std::vector<int>g[],int a,int b)
{
  g[a].push_back(b);
  g[b].push_back(a);
}

void printGraph(std::vector<int>g[],int v)
{
  for(int i = 0; i < v;i++)
  {
    std::cout << " HEAD = " << i << "-->";

    for(int e = 0; e < g[i].size(); e++)
    {
      std::cout << g[i][e] << "--- ";
    }

    std::cout << "\n";


  }
}

int main()
{
  int v = 5;
  std::vector<int> g[v];
  addEdge(g,0,1);
  addEdge(g,0,2);
  addEdge(g,1,2);
  addEdge(g,1,3);
  addEdge(g,1,4);

  addEdge(g,2,3);

  printGraph(g,v);

}
