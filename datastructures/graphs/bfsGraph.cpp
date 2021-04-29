//Bread First Search is a level order traversal 
//Similar to the tree one
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
//Here we mark result to avoid visiting same node
#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

void bfs(std::vector<int> v[],int n)
{
  if(n == 0)
    return;
  bool visited[n];
  for(int i = 0; i < n; i++)
    visited[i] = false;

  std::queue<int> q;
  q.push(0);
  visited[0] = true;

  while(!q.empty())
  {
    int element = q.front();

    std::cout << element << " ";

    q.pop();

    for(int j = 0; j < v[element].size();j++)
    {
      int e = v[element][j];
      if(visited[e] == false)
      {
        visited[e] = true;
        q.push(e);
      }
    }
  }
}

int main()
{
  int V = 5;
  std::vector<int> vec[V];

  addEdge(vec,0,1);
  addEdge(vec,0,2);
  addEdge(vec,2,3);
  addEdge(vec,1,4);
  addEdge(vec,3,4);
  bfs(vec,5);

}
