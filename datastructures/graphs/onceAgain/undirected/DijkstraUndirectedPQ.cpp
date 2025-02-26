/**
Dijkstra’s Algorithm - Using Priority Queue : G-32
https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/


Problem Description - 
 Given a weighted, undirected, and connected graph of V vertices and an adjacency list adj
 where adj[i] is a list of lists containing two integers where the first integer of 
 each list j denotes there is an edge between i and j, 
 second integers corresponds to the weight of that edge.
 You are given the source vertex S and You have to Find the shortest distance 
 of all the vertex from the source vertex S. You have to return a list of 
 integers denoting the shortest distance between each node and the Source vertex S.

Note: The Graph doesn’t contain any negative weight cycle.
Works With directed as well

Examples: 


Input:

V = 2 = Vertex

adj [] = {{{1, 9}}, {{0, 9}}}

S = 0 = Source

Output:

0 9

Explanation: 

The source vertex is 0. Hence, the shortest distance of node 0 from the source is 0 and the shortest distance of node 1 from source will be 9.

Example 2:


Input:

V = 3, E = 3

adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}

S = 2

Output:

4 3 0

Explanation: 

For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.

The shortest distance from 0 to 1 is 1.

Solution - 
Basically Dijkstra Algorithm has 3 ways to solve
1. Using Queue
2. Using Priority Queue
3. Using Set

Using Priority Queue-------------------------------------------------------
Dijkstra’s algo is a greedy approach where it starts picking the nodes with least weights.
we can sort on the basis of weights or we can use min heap. which automatically picks the least weight
Dijikstra algo using priority queue gives quicker result than queue. because in queue nodes are relaxed
based on the order so if there is a better approach it will be relaxed later but priority queue se
least weight will be explored first as our goal is to find shortest paths.

The prioirty queue stores pair where 1st element is dist and second is node
We store distance in distance vector and we relax edges like we did in shortest path using topo

So the priorit queue stores 
{total distance to reach the node,node}

eg 
1-2-3
where 1-2 takes 5
2-3 takes 7
so the pqueue will have after src node
 (5,2)
 (12,3)


*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using intPair = std::pair<int,int>;

std::vector<int> DijkstraPQ(int V,std::vector<std::vector<int>> adj[],int S)
{
	//declare Priority Queue min heap
	std::priority_queue<intPair,std::vector<intPair>,std::greater<intPair>> pq;
	
	//insert source node
	pq.push({0,S});
	std::vector<int> distRes(V,std::numeric_limits<int>::max());
	distRes[S] = 0;
	while(pq.empty() == false)
	{
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		
		//we will relax the edges
		for(auto it : adj[node])
		{
			int neigh = it[0];
			int w = it[1];
			if(distRes[neigh] > distRes[node] + w)
			{
				distRes[neigh] = distRes[node] + w;
				pq.push({distRes[neigh],neigh});
			}
		}
	}
	return distRes;
}

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    std::vector<std::vector<int>> adj[V];
    std::vector<std::vector<int>> edges;
    std::vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    std::vector<int> res = DijkstraPQ(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
//Output: 

//4 3 0

