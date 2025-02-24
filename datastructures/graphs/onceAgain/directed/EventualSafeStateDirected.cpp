/**
*
https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20/

Problem Description - 
Problem Statement: A directed graph of V vertices and E edges is given 
in the form of an adjacency list adj. Each node of the 
graph is labeled with a distinct integer in the range 0 to V - 1.
 A node is a terminal node if there are no outgoing edges. 
 A node is a safe node if every possible path starting from that 
 node leads to a terminal node. You have to return an array 
 containing all the safe nodes of the graph. The answer should be sorted in ascending order.
 
 eg  
  1->2
 1->3
 3->2
 here 2 has out going edge so 1,2,3 are safe nodes
 
 other eg
  1->2
 2->3
 3->1
 here there is cycle and there is no terminal node. so node is safe node
 
 Real World Example. Think of terminal node as router. all pc connected to router are good
 but if there are pc connectedwith each other in a cycle then the message will not go to router
 
 other example
 Deadlock. A waiting for B B waiting for C and C waiting for A. will never go to safe state
 
 So Solution
 It is just like Detecting cycle in directed graph.if anywhere a node detects a cycle then it is not in safe
 state
 so we keep answerin check
 Total Time Complexity O(E+V)(DFS ka) + O(V) //for pushing in resiult
 
*/

#include <iostream>
#include <vector>
#include <algorithm>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool DFS(int node,std::vector<int> &vis,std::vector<int> &path,std::vector<int> adj[],
		 std::vector<int> &checkSafe)
{
	vis[node] = path[node] = 1;
	checkSafe[node] = 0;//mark as not safe initially
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)
		{
			if(DFS(it,vis,path,adj,checkSafe) == true)
			{
				checkSafe[it] = 0;
				return true;
			}
		}
		else 
		{
			if(path[it] == 1)//on same path
			{
				checkSafe[it] = 0;
				return true;
			}
		}
	}
	path[node] = 0;
	checkSafe[node] = 1;//yup safe now
	return false;
}

std::vector<int> GetSafeStates(int V,std::vector<int> adj[])
{
	std::vector<int> vis(V,0);
	std::vector<int> path(V,0);
	std::vector<int> checkSafe(V,0);
	
	for(int i = 0; i < V; i++)
	{
		if(vis[i] == 0)
		{
			DFS(i,vis,path,adj,checkSafe);
		}
	}
	
	std::vector<int> safeStates;
	
	for(int i = 0; i < V; i++)
	{
		if(checkSafe[i] == 1)
		{
			safeStates.push_back(i);
		}
	}
	return safeStates;
}

int main() {

  int V = 12;

  std::vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 6);
  addEdge(adj, 5, 6);
  addEdge(adj, 6, 7);
  addEdge(adj, 8, 1);
  addEdge(adj, 8, 9);
  addEdge(adj, 9, 10);
  addEdge(adj, 10, 8);
  addEdge(adj, 11, 9);

  
  std::vector<int>res = GetSafeStates(V,adj);
  
  auto lambda = []<typename T>(const T &elem){
	  std::cout << elem << ",";
  };
  std::for_each(res.begin(),res.end(),lambda);
 
  return 0;
}

