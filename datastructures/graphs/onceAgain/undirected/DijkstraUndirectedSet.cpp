/**
Dijkstra’s Algorithm - Using Priority Queue : G-32
https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33/

Problem Description - 
 Given a weighted, undirected, and connected graph of V vertices and an adjacency list adj
 where adj[i] is a list of lists containing two integers where the first integer of 
 each list j denotes there is an edge between i and j, 
 second integers corresponds to the weight of that edge.
 You are given the source vertex S and You have to Find the shortest distance 
 of all the vertex from the source vertex S. You have to return a list of 
 integers denoting the shortest distance between each node and the Source vertex S.

Note: The Graph doesn’t contain any negative weight cycle.

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

Using Set-------------------------------------------------------
Using Set we can remove the element from the set if it has been explored already.eg 

eg 
1-2 takes 5
2-3 takes 8
1-3 takes 6 

so queue will have 
{5,2} 
{6,3}
{14,3}

we pick the top then we take 6,3 we update the distance vector. Now it means no sense
to again check node 3 that too with greater distance. so we remove node 3 from queue/set

Works With directed as well


*/

#include <iostream>
#include <vector>

#include <limits>
#include <set>
using intPair = std::pair<int,int>;

std::vector<int> DijkstraSet(int V,std::vector<std::vector<int>> adj[],int S)
{
	//declare set which stores in asc order by default
	std::set<intPair> s;
	
	//insert source node
	s.insert({0,S});
	std::vector<int> distRes(V,std::numeric_limits<int>::max());
	distRes[S] = 0;
	while(s.empty() == false)
	{
		auto it = s.begin();
		int node = it->second;
		int dist = it->first;
		s.erase(it); //remove current element
		
		//we will relax the edges
		for(auto it : adj[node])
		{
			int neigh = it[0];
			int w = it[1];
			if(distRes[neigh] > distRes[node] + w)
			{
				//remove all entries with more distance
				if(distRes[neigh] != std::numeric_limits<int>::max())
				{
					s.erase({distRes[neigh],neigh});
				}
				
				distRes[neigh] = distRes[node] + w;
				
				
				
				s.insert({w,neigh});

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

    std::vector<int> res = DijkstraSet(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
//Output: 

//4 3 0

