/**
*
https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/

Problem Statement: Given a Directed Graph with V vertices and E edges, 
check whether it contains any cycle or not.
 
We use Kahn Algorithm for detecting there is a cycle in directed Graph.
1->2->3->1
then indegree of 1= 1
then indegree of 2= 1
then indegree of 3= 1

kisi ka 0 nahi h. so last m  res ka size will not be equal to all elements as q m insert hi nahi hue
lets say we have 4 also which is having indegree to 0
so 
indegree of 1= 1
indegree of 2= 2 
indegree of 3= 1
indegree of 4= 0

NO we push 4 and then subtract indegree of 2 to 1. but queue m ab insert koi hoga hi nahi
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}



bool isCycleTopoSortKahn(std::vector < int > adj[],int V)
{
	
	std::vector<int> indegree(V,0);
	std::vector<int> res;
	std::queue<int> q;
	
	//1.Initilization
	//this will also handle multiple components
	for(int i = 0; i < V; i++)
	{
		for(auto it : adj[i])
		{
			indegree[it]++;//0->1. then increase indgree of 1	
		}

		
	}
	
	for(int i = 0; i < V; i++)
	{
		if(indegree[i] == 0)
		{
			res.push_back(i);
			q.push(i);
		}
	}
	
	while(q.empty() == false)
	{
		int elem = q.front();
		q.pop();
		
		for(auto it : adj[elem])
		{
			//we remove elem. we reduce indegree of elem neighbor
			indegree[it]--;
			if(indegree[it] == 0)
			{
				res.push_back(it);
				q.push(it);
			}
		}
	}
	
	
	return !(res.size() == V);
	
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
  addEdge(adj, 4, 1); //if we uncomment this we will get cycle

  
  std::cout << "\n IS Cycle = " << isCycleTopoSortKahn(adj,V) << "\n";
 
  return 0;
}



