/**
*
https://takeuforward.org/data-structure/topological-sort-using-dfs/

Problem Description - 
Problem Statement: Given a DAG( Directed Acyclic Graph ), 
print all the vertex of the graph in a topologically sorted order.
 If there are multiple solutions, print any.
 
 Topological sorting for Directed Acyclic Graph (DAG) is a 
 linear ordering of vertices such that for every directed 
 edge u-v, vertex u comes before v in the ordering.
 
 eg  
  1->2->3 
  then topological order is 1,2,3 where 1 appearing before 2
  topolocial sort is only for DAG
  if graphcontains cycle
  1->2->3->1 then if we try to write order we 1,2,3,1 but 1 can come in2 places
  
  if graph is undirected
  1-2. then we have to say 1 should appear before 2 and also 1 should appear after 2  which cant be valid
  
  SOlution
  We simply do dfs and will keep storing the result in stack then we print
  eg dfs(1)->dfs(2)->dfs(3)
  then back track from dfs(3)->dfs(2). Push 3 on stack
  then back track from dfs(2)->dfs(1). Push 2 on stack
  then finally back track to initial val. Push 1 on stack.
  we simply print 
  
  Real World Example
  Project Management (Task Scheduling)
  Imagine I am managing a software development project with 
  multiple tasks that need to be completed in a specific order. 
  Some tasks can't begin until others are finished due to dependencies.So we need to know the order in which they have to be finished.
  
  Next Level Game
  Player can not go to next level until he has completed all tasks
 
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool DFS(int node,std::vector<int> &vis,std::vector < int > adj[],std::stack<int> &st)
{
	vis[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)
		{
			DFS(it,vis,adj,st);
		}
	}
	
	st.push(node);//all its children processed so we can add this into stack
}

std::vector<int> TopoSortDFS(std::vector < int > adj[],int V)
{
	std::vector<int> vis(V,0);
	std::stack<int> st;
	std::vector<int> res(V);
	
	for(int i = 0; i < V; i++)
	{
		if(vis[i] == 0)
		{
			DFS(i,vis,adj,st);
		}
	}
	int idx = 0;
	while(st.empty() == false)
	{
		res[idx] = st.top();
		st.pop();
		idx++;
	}
	
	return res;
}

int main() {

  int V = 6;



  std::vector < int > adj[V];
  addEdge(adj, 5, 2);
  addEdge(adj, 5, 0);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 1);
  
  
  std::vector<int>res = TopoSortDFS(adj,V);
  
  auto lambda = []<typename T>(const T &elem){
	  std::cout << elem << ",";
  };
  std::for_each(res.begin(),res.end(),lambda);
 
  return 0;
}
