//Find a cycle in an undirected graph using DFS in iterative manner
#include <iostream>
#include <vector>
#include <stack>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

bool isCyclePresent(std::vector<int> v[],std::vector<int> &visited,int index,int parent)
{
  visited[index] = 1;

  int size = v[index].size();

  for(int i = 0; i < size; i++)
  {
    int elem = v[index][i];

    if(visited[elem] == false)
    {
      if(isCyclePresent(v,visited,elem,index))
        return true;
    }
    else if(parent != elem)
      return true;
  }

  return false;

}


int main()
{
  int N = 3;
  std::vector<int> v[N];
  addEdge(v,0,1);
  addEdge(v,1,0);
  addEdge(v,0,2);
  addEdge(v,2,0);
  addEdge(v,2,1);
  addEdge(v,1,2);
  std::vector<int> visited(N,false);
  std::cout << "\n Is Cycle Present = " << isCyclePresent(v,visited,0,0);

}

