/**
*
https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/

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
  Here we will use Kahn algorithm which is modified BFS.
  So bsically we keep an indegree vector that stores the indegree of a node
  0->1
  indegree[0] = 0
  indegree[1] = 1;
  also usage of visited will not be required
  so basically jin jin ka indegree 0 hota aaye we print that. that will represent topo sort
  
  
  so we take the full grpah a we insert in queue whose indree is 0.So next we pick element from queue
  and remove from the graph like we remove 0 when we remove 0 then all the elements whose indegree was 
  depending on 0 will get subtracted. we keep doing this until our queue is empty
  
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
#include <queue>
#include <algorithm>

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}



std::vector<int> TopoSort(std::vector < int > adj[],int V)
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
	
	
	return res;
	
}

int main() {

  int V = 6;



  std::vector < int > adj[V]={};
  addEdge(adj, 5, 2);
  addEdge(adj, 5, 0);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 1);
  
  
  std::vector<int>res = TopoSort(adj,V);
  
  auto lambda = []<typename T>(const T &elem){
	  std::cout << elem << ",";
  };
  std::for_each(res.begin(),res.end(),lambda);
 
  return 0;
}



