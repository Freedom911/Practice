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

void dfsIter(std::vector<int> v[],int total,int nodeToStartFrom)
{
  std::stack<int> st;
  st.push(nodeToStartFrom);
  int visited[total] = {0};
  visited[nodeToStartFrom] = 1;

  while(!st.empty())
  {
    int top = st.top();
    st.pop();
    std::cout << top << " ";


    for(auto iter: v[top])
    {
        if(visited[iter] == 0)
        {
            st.push(iter);
            visited[iter] = 1;
        }
    }
  }
}

void dfsRecHelper(std::vector<int> adj[],int node,int visited[])
{
    visited[node] = 1;

    std::cout << node << ",";

    for(auto it : adj[node])
    {
        if(visited[it] == 0)
        {
            dfsRecHelper(adj,it,visited);
        }
    }



}

void dfsRec(std::vector<int> adj[],int V,int start)
{
   //for all disconnected components
   int visited[V] = {0};

   dfsRecHelper(adj,start,visited);

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
    std::cout << "\n DFS ITERATIVE FOR UNIDRECTED GRAPH \n";
    dfsIter(undirected,V,0);


    std::cout << "\n DFS Recursive FOR UNIDRECTED GRAPH \n";
    dfsRec(undirected,V,0);


}
