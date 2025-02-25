/**
https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/

Problem Statement - 
Given a DAG, find the shortest path from the source to all other 
nodes in this DAG. In this problem statement, we have assumed the 
source vertex to be ‘0’. You will be given the weighted edges of the graph.

Solution - 
So We have multiple ways to solve.
Dijikstra (not the witcher one) is famously used for this.It isgreedy and also works for cycle
Here we will use Topo Sort. this only works in DAG. ALso check for cycle

Example
0->1->2->3

So using Toposort we process everything in order
like for 3 to get evaluated 2 has to be evaluated for 2 ,1 has to be evaluated and for 1 0 has to be evaluited

So after topo sort we start from the 1st element and relax the edge.

So what does relaxation means. Relaxation means if there is a better way(less weight) to reach a target
we take that for eg 0->1 takes 10 . but 0->2->1 takes 5 so we update with 5.

Algo
Now how do we keep this
We basically maintain a dist vector which is storing infinity initially. The vector stores shortest distnace
to reach a node from src.
we take the 1st elemnt and write 0 in dist vector.
We Relax the edge in the topologically order.
Relaxing an edge means to update the shortest path

relaxation is making a change that reduces constraints. 
When the algorithm examines an edge, 
it removes an edge from the pool, thereby reducing the number of constraints.

like 1 : 0,2,3,4

if we relax 1 then we update the path of all the nodes adjancet to it with shortest distance


eg
0 : 1,2
1 : 3
2 : 3

a)  dist = [0,inf,inf,inf]
	after topo sort
	st = [0,1,2,3]

b) 	Pick st top i.e 0 and check neighbors 1,2
	update the dist vector
	0->1 takes 7
	0->2 takes 5
	dist = [0,7,5,inf]

c)	next pick 1 from stack
	1->3 takes 3
	so we relax 1
	since dist[3] > dist[0->1] + wt from 1->3
	we update dist[3] with min 
	dist[3] = 10
	finally we have 
	dist = [0,5,7,10]

d)	Next Pick 2
	2->3 takes 3

	relaxing 2
	dist[3] = 10
	dist[3] > dist[0->2] + wt from 2->3
	10> 5 + 3 
	so we update
	dist[3] = 8

	finally dist = [0,5,7,8]
	

Input - N,M,{{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
N denotes nodes
M Denotes edges

0->1 takes 2
0->4 takes 1 and so on
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

//we are also checking for cycle if presnet or not
bool DFS(int node,std::vector<int> &path,std::vector<std::pair<int,int>> adj[],std::vector<int> &vis,
		 std::stack<int> &st)
{
	path[node] = vis[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it.first] == 0)
		{
			if(DFS(it.first,path,adj,vis,st) == true) // cycle so not possible
			{		
				return true;
			}
		}
		else if(path[it.first] == 1) //in same path and visited so cycle
		{
				return true;
		}
	}
	
	st.push(node);
	path[node] = 0;
	return false;
	
}

std::vector<int> shortestPathDFS(int N,int M,std::vector<std::vector<int>> &edges)
{
	//Algo Broader Overview
	//1. Do Topo Sort via DFS 
	//2. Take one by one and start relaxing
	
	//1. TOPO SORT
	//a)Now For Topo Sort we require adjcent list with weight as well so we crete adj list like this
	//0 : {1,2},{4,1}
	//1 : {2,3}
	//and so on
	std::vector<std::pair<int,int>> adj[N];
	std::vector<int> res;
	
	for(int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		adj[u].push_back({v,w});
	}
	//Using DFS

	std::vector<int> path(N,0);
	std::stack<int> st;
	std::vector<int> vis(N,0);
	
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 0)
		{
			if(DFS(i,path,adj,vis,st) == true) // cycle so not possible
			{
				std::cout << "\n CYCLE DETECTED \n";
				return res;
			}
		}
	}
	
	//--------------------------------------------------------------------
	
	//2. Relaxation of edge
	//we take one by one elemnt from stack. we require dist vector
	std::vector<int> dist(N,std::numeric_limits<int>::max());
	dist[0] = 0;
	
	while(st.empty() == false)
	{
		int node = st.top();
		st.pop();
		
		for(auto it : adj[node])
		{   //this includes dist from src->node + it.second means dist from node to it(neighbor)
			if(dist[it.first] > dist[node] + it.second)
			{
				dist[it.first] = dist[node] + it.second;
			}
		}
	}
	std::replace(dist.begin(),dist.end(),std::numeric_limits<int>::max(),-1);
	return dist;

	
	
	
}


std::vector<int> shortestPathBFS(int N,int M,std::vector<std::vector<int>> &edges)
{
	//Algo Broader Overview
	//1. Do Topo Sort via  kahn chacha
	//2. Take one by one and start relaxing
	
	//1. TOPO SORT
	//a)Now For Topo Sort we require adjcent list with weight as well so we crete adj list like this
	//0 : {1,2},{4,1}
	//1 : {2,3}
	//and so on
	std::vector<std::pair<int,int>> adj[N];
	std::vector<int> res;
	
	for(int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		adj[u].push_back({v,w});
	}

std::vector<int> Indegree(N,0);
std::queue<int> q;

for(int i = 0; i < N; i++)
{
	for(auto it : adj[i])
	{
		Indegree[it.first]++;
		
	}
}

//Initialization in queue
for(int i = 0; i < N; i++)
{
	if(Indegree[i] == 0)
	{
		res.push_back(i);
		q.push(i);
	}
}

while(q.empty() == false)
{
	int node = q.front();
	q.pop();
	
	for(auto it : adj[node])
	{
		Indegree[it.first]--;
		if(Indegree[it.first] == 0) //means no incoming edge present
		{
			res.push_back(it.first);
			q.push(it.first);
		}
	}
}

//we take one by one elemnt from stack. we require dist vector
	std::vector<int> dist(N,std::numeric_limits<int>::max());
	dist[0] = 0;
	
	for(int i = 0; i <res.size(); i++)
	{
		int node = res[i];
		
		
		for(auto it : adj[node])
		{   //this includes dist from src->node + it.second means dist from node to it(neighbor)
			if(dist[it.first] > dist[node] + it.second)
			{
				dist[it.first] = dist[node] + it.second;
			}
		}
	}
	std::replace(dist.begin(),dist.end(),std::numeric_limits<int>::max(),-1);
	return dist;
	
	
}
int main() 
{
  int N = 6, M = 7;
  
  std::vector<std::vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  
  std::vector < int > ans = shortestPathDFS(N, M, edges);
  std::cout << "\n VIA DFS \n";
  auto lambda = []<typename T>(const T&elem){
	  std::cout << elem << ",";
  };
  
  std::for_each(ans.begin(),ans.end(),lambda);
  
  
  ans = shortestPathBFS(N, M, edges);
  std::cout << "\n VIA BFS(Kahn Chacha) \n";
  
  std::for_each(ans.begin(),ans.end(),lambda);

  return 0;

}

