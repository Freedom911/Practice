//Program To topologically print a graph.
//topological sort only works for directed acyclic graph (DAG) as
//in cyclic graph the order wont be proper
//here 1st step is to maintain an array in addition to maintaing the graph data
//the arrya will contain the indegree of each vertex. Will start from vertex which 
//has indegree as 0 and will remove that vertex. on removing the vertex we update the indegree
//of other vertex as it will affect those also. if the indegree reaches 0 of any vertex then we
//will repeat it

#include <iostream>
#include <vector>

void addEdge(std::vector<int> V[],std::vector<int> &indegree,int a,int b)
{
  V[a].push_back(b);
  indegree[b]++;
}


void toplogicalSortUtils(std::vector<int> V[],std::vector<int> &indegree,int index)
{
  //Traverse the neigbhors of all the mentioned index
  int size = V[index].size();

  for(int i = 0; i < size; i++)
  {
    //Go to the index of the indegree and do --
    int ind = V[index][i];
    indegree[ind]--;
    if(indegree[ind] == 0)
    {
      std::cout << ind << " ";
      toplogicalSortUtils(V,indegree,ind);
    }
  }

}

void topologicalSort(std::vector<int> V[],std::vector<int> &indegree)
{
  std::cout << "\n Topological Sort is = ";
  for(int j = 0; j < indegree.size(); j++)
  {
    if(indegree[j] == 0)
    {
      std::cout << j << " ";
      toplogicalSortUtils(V,indegree,j);
    }
  }
}



int main()
{
  int N = 6;
  std::vector<int>V[N],indegree(N,0);
  addEdge(V,indegree,5,0);
  addEdge(V,indegree,5,2);
  addEdge(V,indegree,2,3);
  addEdge(V,indegree,3,1);
  addEdge(V,indegree,4,0);
  addEdge(V,indegree,4,1);

  topologicalSort(V,indegree);

}
