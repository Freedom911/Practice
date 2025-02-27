/**
G-35 : Print Shortest Path - Dijkstra’s Algorithm
https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/


Problem Statement: 

You are given a weighted undirected graph having n+1 vertices numbered from 0 to n 
and m edges describing there are edges between a to b with some weight,
 find the shortest path between the vertex 1 and the vertex n,
 and if the path does not exist then return a list consisting of only -1.
 
 We use Dijkstra PQ. Here to print the path we maintain the parent in Dist vector
 so dist vector will have dist,parent
 We start from last and keep printing till we reach src


*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using intPair = std::pair<int,int>;

std::vector<int> shortestPath(int n, int m, std::vector<std::vector<int>> &edges)
{
	
	//Creatoing Adj List
	std::vector<std::vector<intPair>>adj (n + 1);
	
	for(int i =0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		
	}
	
	
	int S = 1;
	//declare Priority Queue min heap
	std::priority_queue<intPair,std::vector<intPair>,std::greater<intPair>> pq;
	
	//insert source node
	pq.push({0	,S});
	//dist,parent
	std::vector<intPair> distRes(n+1,{std::numeric_limits<int>::max(),-1});
	distRes[S] = {S,S};
	while(pq.empty() == false)
	{
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		
		//we will relax the edges
		for(auto it : adj[node])
		{
			int neigh = it.first;
			int wt = it.second;
			if(distRes[neigh].first > distRes[node].first + wt)
			{
				distRes[neigh].first = distRes[node].first + wt;
				distRes[neigh].second = node; //update parent
				pq.push({distRes[neigh].first,neigh});
			}
		}
	}

	int lastNode = n;
	std::vector<int> res;
	while(distRes[lastNode].second != lastNode) //means it has not reached src
	{
		res.push_back(lastNode);
		lastNode = distRes[lastNode].second;
	}
	res.push_back(S);
	std::reverse(res.begin(),res.end());
	
	return res;
}

int main()
{
    int V = 5, E = 6;
    std::vector<std::vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    
    std::vector<int> path = shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {

        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}


