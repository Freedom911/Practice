/**

https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/

Prim's Algorithm - Minimum Spanning Tree - C++ and Java: G-45



Problem Statement: Given a weighted, undirected, and connected graph of V 
vertices and E edges. The task is to find the sum of weights of the edges of
 the Minimum Spanning Tree.
(Sometimes it may be asked to find the MST as well, where in the MST 
the edge-informations will be stored in the form {u, v}(u = starting node, v = ending node).)

Example 1:

Input Format: 
V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}


Result: 16
Explanation: 
The minimum spanning tree for the given graph is drawn below:
MST = {(0, 1), (0, 3), (1, 2), (1, 4)}

Solution - I have explained in ONe note.
The algo is very similar to Dijkstra with a one major difference_type
IN dijikstra we try to minimize the distance from source 
while in prim we want to minimize the overall cost
Prim algo works with Undrieced graph only

IN real world let say we are given some budge and need to connect all major cities with rail way station
if we try to apply Dijkstra here then we might overshoot the budge as Dijikstra only tries to minimize
cost from source. We need to apply Prims here
eg A-{B,5},{D,9}
   B - {C,5}
   C - {D,2}
   
 Dijsktra output will contain edge between A-B,B-C and A-D. total cost = 5 + 5 + 9 = 19
 Prims algo output will have A-B,B-C,C-D total cost = 5 + 5 + 2 = 12
 So prim is thee winner here
 
 Algo is similiar to DIjsktra we have priority queue where the entry contains
 {distance from previous node,node}. Note that in Dijsktra we have {Distance from source,node}
 In Dijsktra source is fixed,in Prim it is not.
 We have iSMst which is an array which is set to true when we pop from pq. as it guarantees it is having
 shorter distance/cost
 
 Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
The maximum size of the priority queue can be E so after at most E iterations the
 priority queue will be empty and the loop will end. Inside the loop, there is a pop 
 operation that will take logE time. This will result in the first O(E*logE) time 
 complexity. Now, inside that loop, for every node, we need to traverse all its 
 adjacent nodes where the number of nodes can be at most E. If we find any node 
 unvisited, we will perform a push operation and for that, we need a logE time 
 complexity. So this will result in the second O(E*logE). 
 */
 #include <iostream>
 #include <queue>
 #include <vector>
 
 int spanningTree(int V,std::vector<std::vector<int>> adj[])
 {
	 //Check conditions
	 if(V == 0)
	 {
		 return -1;
	 }
	 
	 std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pq;
	 
	 std::vector<int> IsMST(V,0);
	 
	 int mstCost = 0;
	 
	 //Initialization
	 pq.push({0,0});//distance from rpeevious node,node
	 
	 while(pq.empty() == false)
	 {
		 int node = pq.top().second;
		 int dist = pq.top().first;
		 
		 pq.pop();
		 if(IsMST[node] == 1)//already part of mst. then ignore
		 {
			 continue;
		 }
		 for(auto it: adj[node])
		 {
			 int v = it[0];
			 int wt = it[1];
			 if(IsMST[v] == 0)
			 {
				 pq.push({wt,v});
			 }
		 }
		 mstCost += dist;
		 IsMST[node] = 1;
		 
	 }
	 return mstCost;
 }
 
 int main() 
 {

	int V = 5;
	std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	std::vector<std::vector<int>> adj[V];
	for (auto it : edges) {
		std::vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	
	int sum = spanningTree(V, adj);
	std::cout << "The sum of all the edge weights: " << sum << std::endl;

	return 0;
}
 
