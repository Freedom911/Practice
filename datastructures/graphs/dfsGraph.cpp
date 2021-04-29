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
int main()
{
  int V = 5;
  std::vector<int> v[V];
  addEdge(v,0,1);
  addEdge(v,0,2);
  addEdge(v,1,4);
  addEdge(v,2,1);
  addEdge(v,2,3);
  addEdge(v,3,4);
  dfs(v,V,0);
}
