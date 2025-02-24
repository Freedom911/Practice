/**
*
https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/

Problem Description - 
Given is a 2D adjacency list representation of a directed graph. 
Check whether the graph has cycles are not.

Solution - Here unliked undirected graph where we simply checked if a node has 2 mai baap
we declared it cyclic . It is not as straightforward
eg
 0  -----> 1
 |		   |	
 |         |
 |         |
 \/        \/
 2-------> 3--->4
 if we had applied logic that 3 has 2 mai baaps 1 and 2 then it is cycle . then here it will be wrong
 here it is not a cycle as 0 se 1 and 0 se 2 ja skte h if 3 se2 and2 se 0 hota toh cycle hoti
 
 So what logic?
 We basically say it is a cycle if a node is already visited in the same path
 eg
 1->2
 2->3
 3->1
 when we go from 3 to 1. we see 1 is already visited and also in the same path. so it is cyclic
 other eg
 1->2
 1->3
 3->2
 
 here we go from 1 se 2 then we back track to 1 and go 3 . 3 se we go to 2
 we see 2 is already visited but not in the current path i,e not from 1->3->2 wale path 
 2 was visited by 1->2 path. so we say it is not a cycle
 So here we keep a pathVisited array. which is set to 1 when we visit a node and set to 0 when we backtrack
 we check if a node is visiteed and also if pathVisited is 1 then we say it iss cycle other wisenot
*/

#include <iostream>
#include <vector>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool DFS(int node,std::vector<int> &vis,std::vector<int> &path,std::vector<int> adj[])
{
	vis[node] = path[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)
		{
			if(DFS(it,vis,path,adj) == true)
			{
				return true;
			}
		}
		else 
		{
			if(path[it] == 1)//on same path
			{
				return true;
			}
		}
	}
	path[node] = 0;
	return false;
}

bool isCyclic(int V,std::vector<int> adj[])
{
	std::vector<int> vis(V,0);
	std::vector<int> path(V,0);
	
	for(int i = 0; i < V; i++)
	{
		if(vis[i] == 0)
		{
			if(DFS(i,vis,path,adj) == true)
			{
				return true;
			}
		}
	}
	return false;
}

int main() {

  int V = 6;

  std::vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 0, 4);
  //addEdge(adj, 4, 1); //if we uncomment this we will get cycle
  

  if (isCyclic(V, adj))
    std::cout << "Cycle Detected" << "\n";
  else
    std::cout << "No Cycle Detected";

  return 0;
}