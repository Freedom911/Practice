//Depth First Traversal of graph. It will expand from one node first
//and go on until no other node is left. It stores result in stack
//we pick elelent from stack and check unvisited node and push in stack
#include <iostream>
#include <stack>
#include <vector>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

void dfs(std::vector<int> v[],int total,int nodeToStartFrom)
{
  std::stack<int> st;
  st.push(nodeToStartFrom);
  std::vector<bool> b(total,false);

  while(!st.empty())
  {
    int top = st.top();
    st.pop();

    if(b[top] == false)
    {
      std::cout << top << " ";
      b[top] = true;
    }

    for(int i = 0; i < v[top].size(); i++)
    {
      int elem = v[top][i];
      if(b[elem] == false)
      {
        st.push(elem);
      }
    }
  }
}

void findCycle(std::vector<int> v[],int total,int nodeToStartFrom)
{
  std::stack<std::pair<int,int>> st;
  st.push(std::make_pair(nodeToStartFrom,nodeToStartFrom));
  std::vector<bool> b(total,false);

  while(!st.empty())
  {
    int top = st.top().first;
    int parent = st.top().second;
    std::cout << " CALLED " << top << "\n";;
    st.pop();

    if(b[top] == false)
    {
     // std::cout << top << " ";
      b[top] = true;
    }

    for(int i = 0; i < v[top].size(); i++)
    {
      int elem = v[top][i];
      if(b[elem] == false)
      {
        std::cout << "\n PUSHING = " << elem << " PARENT = " << parent << "\n";
        st.push(std::make_pair(elem,top));
      }
      else
      {
        if(elem != parent)
        {
          std::cout << "\n Cycle Detected for node -> " << elem << " " << parent << "\n";
          return;
        }
      }

    }
  }
}

int main()
{
  int V = 4;
  std::vector<int> undirected[V];
  addEdge(undirected,0,1);
  addEdge(undirected,1,0);

  addEdge(undirected,0,2);
  addEdge(undirected,2,0);

  addEdge(undirected,1,3);
  addEdge(undirected,3,1);

 addEdge(undirected,2,3);
 addEdge(undirected,3,2);
  std::cout << "\n DFS FOR UNIDRECTED GRAPH \n";
  //dfs(undirected,V,0);
  findCycle(undirected,V,0);






}
