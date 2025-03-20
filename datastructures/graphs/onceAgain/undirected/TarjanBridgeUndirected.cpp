/**
 *
	https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/

	Bridges in Graph - Using Tarjan's Algorithm of time in and low time: G-55

	Problem Statement: There are n servers numbered from 0 to n - 1 connected by 
	undirected server-to-server connections forming a network where 
	connections[i] = [ai, bi] represents a connection between servers 
	ai and bi. Any server can reach other servers directly or indirectly through the network.

	A critical connection is a connection that, if removed, will make some 
	servers unable to reach some other servers.

	Return all critical connections in the network in any order.

	Note: Here servers mean the nodes of the graph. The problem statement
	is taken from leetcode.

	Pre-requisite: DFS algorithm

	Example 1:

	Input Format: N = 4, connections = [[0,1],[1,2],[2,0],[1,3]]


	Result: [[1, 3]]
	Explanation: The edge [1, 3] is the critical edge because if we remove the edge the graph will be divided into 2 components.
	
	Solution 
	I have explained in Deep in one note
	
	So revising 
	Bridge is a critical component edge such that if we remove it we wont be able to visit the nodes
	or the nunmber of components will increase
	
	So an edge is definitely not a bridge if it is part of cycle
	We use numebr for nodes
	discovery time is basically ordering of nodes in which they were discovered
	low is the lowsest node a particular node can reach
	
	Bridge condition
	and we say if discovery time of a node(parent) < lowest node a neighbor(child) can reach then it 
	is definitely a bridge because this means the neighbor(child) cant reach 
	a node lower to (parent)
	We use DFS to achieve that. We remove one by one edge for each graph
	particular node-neighbor. like we remove node - neihbor edge and we say is 
	neighbor reachable any node which is lower than particular node
	is previous than the 
	three conditions
	1. ignore for parent
	2. if visited already we say that the edge is definitely not a bridge
	   so we update the lowest node of the particular node because it can reach the lowest node as well
	   from neighbor.Remember i have explained in deep in one note
	3. if not visited , then do dfs and check condition of bridge and also update the low of particular
	   node
*/

#include <iostream>
#include <vector>

void DFS(int node,int parent,std::vector<int> adj[],
		std::vector<int> &vis,std::vector<int> &dis,
		std::vector<int> &low, int &disIndex,
		std::vector<std::vector<int>> &res)
{
	vis[node] = 1;
	dis[node] = low[node] = disIndex;

	for(auto it : adj[node])
	{
		int neighbor = it;
		//3 conditinos
		if(neighbor == parent)
		{
			continue; //no need to do anything as we came from parent only
		}
		else if(vis[neighbor] == 1)
		{
			//definitely not a bridge
			//just update the lowest of node as that of neighbor
			//because if neighbor can reach the lowest point so can node as this is an 
			//extra edge and not a bridge
			low[node] = std::min(low[node],low[neighbor]);
		}
		else
		{
			disIndex++;//disconver icrement
			//DFS call
			
			DFS(neighbor,node,adj,vis,dis,low,disIndex,res);
			
			//now on coming back again update the low of node
			//as we want to update the lowest  a node can reach
			low[node] = std::min(low[node],low[neighbor]);
			
			//check bridge condition
			if(dis[node] < low[neighbor]) //means neighbor can reach any node lesser than node 
			{
				//so it is bridge. i.e critical one
				res.push_back({node,neighbor});
			}
		}
		
	}
}

std::vector<std::vector<int>> criticalConnections(int V,std::vector<std::vector<int>> &connections)
{
	if(V == 0 || connections.size() == 0)
	{
		return {};
	}
	
	//we have to convert to adj list
	std::vector<int> adj[V] = {};
	
	{
		for(auto it : connections)
		{
			int u = it[0];
			int v = it[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	std::vector<int> vis(V,0);
	std::vector<int> dis(V,0);
	std::vector<int> low(V,0);
	int S = 0;
	int par = -1;
	int disIndex = 0;
	std::vector<std::vector<int>> res;
	
	DFS(S,par,adj,vis,dis,low,disIndex,res);
	return res;
	
}

int main() 
{

    int n = 4;
    std::vector<std::vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };


    std::vector<std::vector<int>> bridges = criticalConnections(n, connections);
    for (auto it : bridges) {
        std::cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    std::cout << std::endl;
    return 0;
}
//Output: [3, 1] (In example 1, [1, 3] and [3, 1] both are accepted.)	   

