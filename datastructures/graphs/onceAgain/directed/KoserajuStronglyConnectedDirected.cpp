/**
	https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

	Problem Statement: Given a Directed Graph with V vertices 
	(Numbered from 0 to V-1) and E edges, Find the number of strongly 
	connected components in the graph.

	Pre-requisite: DFS algorithm

	Example 1:

	Input Format:


	Result: 3
	
   Solution - What is strongly COnnected Component
   So basically a strongly connected component is a component in which each node can be reached to another
   eg 1->2
   2->3
   3->1
   1 can reach 3 ,3 can reach 1 1 can reach 2. 2 can reach 1
   
   So it is a strongly connected component
   
   now to count number of strognly connected component
   eg 0->1
   1->2
   2->0
   1->3
   there are two componens
   0,1,2 and 3.
   I have explained tios in one note
   
   So basically if we have used ony dfs then we start from 0 and travel to all nodes
   then we wont be able to find strongly conectec components
   .If we reverse all the edges then for strongly connected compoentns. it wont matter
   but those which are not strongly connected they will be disconnected means unke lie we have
   to run dfs again.
   So total components will be equal to how many times dfs will run
   
   But we need to ensure that even if we reverse we start from starting node only because
   it ay happen that from last node we start and dfs and we reach every node so in that case
   connected components will be 1
   
   So Koseraju algorithm
   1. DO DFS Topo Sort . why dfs ? because bfs kahn chacha will fail and wont give any anser. this will
      give some answer
   2. Reverse edges
   3. Again do dfs to count number of components
  */
  
#include <iostream>
#include <stack>
#include <vector>

void DFS(int node,std::vector<int> adj[],int vis[],std::stack<int> &st)
{
	vis[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)
		{
			DFS(it,adj,vis,st);
		}
	}
	st.push(node);
}

int koseraju(int n,std::vector<int> adj[])
{
	//Step 1 do topo sort via dfs
	std::stack<int> st;
	int vis[n] = {};
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == 0)
		{
			DFS(i,adj,vis,st);
		}
	}
	
	//Step 2 - Reverse adj list
	std::vector<int> adjRev[n];
	for(int i = 0; i < n; i++)
	{
		vis[i] = 0;
		for(auto it : adj[i])
		{
			int u = i;
			int v = it;
			adjRev[v].push_back(u);
		}
	}
	
	//Step 3 Count components via dfs again
	int count = 0;
	std::stack<int>st1;
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == 0)
		{
			DFS(i,adjRev,vis,st1);
			count++;
		}
	}
	
	return count;
	
}



int main() 
{

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    int ans = koseraju(n, adj);
    std::cout << "The number of strongly connected components is: " << ans << std::endl;
    return 0;
}