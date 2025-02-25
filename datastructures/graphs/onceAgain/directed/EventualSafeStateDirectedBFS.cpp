/**
*
https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/

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
 We apply Kahn chacha algo. So basically to start we try to convert all outdegree to indegree for example
 1->2 h agar
 indegree of 1 = 0
 indegree of 2 = 1
 
 2 is safe state by the way
 
 we do ulta
 indegree of 1 = 1
 indegree of 2 = 0
 
 so we pick 2 and remove and reduce indegreeof1 which changes to 0. so we have output as 2,1
 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

std::vector<int> GetSafeStates(int V,std::vector<int> adj[])
{
	
	std::vector<int> adjRev[V];
	
	//1->2,3,4
	//2->1
	//3->1
	for(int i = 0; i < V; i++)
	{
		for(auto it : adj[i])
		{
			int u = i;
			int v = it;
			adjRev[v].push_back(u);
		}
	}
	
	std::vector<int> indegree(V,0);
	
	for(int i = 0; i < V; i++)
	{
		for(auto it : adjRev[i])
		{
			indegree[it]++;
		}
	}
	
	//Iniitliazation to queue
	std::queue<int>q;
	std::vector<int> safeStates;//needs to be sorted
	for(int i = 0; i < V; i++)
	{
		if(indegree[i] == 0)
		{
			safeStates.push_back(i);
			q.push(i);
		}
	}
	
	while(q.empty() == false)
	{
		int node = q.front();
		q.pop();
		
		for(auto it: adjRev[node])
		{
			indegree[it]--;
			if(indegree[it] == 0)
			{
				q.push(it);
				safeStates.push_back(it);
			}
		}
	}
	
	std::sort(safeStates.begin(),safeStates.end());
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

