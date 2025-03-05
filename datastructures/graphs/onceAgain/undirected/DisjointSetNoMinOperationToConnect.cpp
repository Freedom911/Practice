/**
 *
 https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/
 
 Problem Statement: You are given a graph with n vertices and m edges. You can remove 
 one edge from anywhere and add that edge between any two vertices in one operation. 
 Find the minimum number of operations that will be required to make the graph 
 connected. If it is not possible to make the graph connected, return -1.

Pre-requisite: Disjoint Set data structure

Example 1:

Input Format: N = 4, M = 3, Edge[] =[ [0,  1], [ 0, 2], [1, 2]]


Result: 1
Explanation: We need a minimum of 1 operation to make the two components 
connected. We can remove the edge (1,2) and add the edge between node 2 
and node 3 like the following:

Solution -
So we know if there are n components we need n -1 edges to connect them
So we need atleast n -1 extra edges.
Q1 How to calculate number of components ?
We can use prior knowledge of calcuating no of components via dfs/bfs or disjoint set
We will use disjoint set here.
Q2 How to calculate extra edge?
Basically if visit already visited node other than its parent then we consider that edge as extra
in terms of disjoint set. If we find that 2 nodes belong to same set then we dont need that edge and
consider that extra
*/
#include <iostream>
#include <vector>

class DisjointSet
{
	public:
	std::vector<int>IsPartOf,Size;
	DisjointSet(int n)
	{
		IsPartOf.resize(n,0);
		Size.resize(n,1);
		for(int i = 0;i < n; i++)
		{
			IsPartOf[i] = i;
		}
	}
	
	int findUPar(int u)
	{
		if(u == IsPartOf[u])
		{
			return u;
		}
		
		return IsPartOf[u] = findUPar(IsPartOf[u]);//Path compression
	}
	
	bool UnionBySize(int u,int v)
	{
		int setV = findUPar(v);
		int setU = findUPar(u);
		if(setU == setV)
		{
			return false;//no need to merge
		}
		
		if(Size[setV] > Size[setU])
		{
			//merge set u with set v
			Size[setV] += Size[setU];
			IsPartOf[setU] = setV;
		}
		else
		{
			Size[setU] += Size[setV];
			IsPartOf[setV] = IsPartOf[setU];
		}
		return true;
	}
};

int Solve(int V,std::vector<std::vector<int>> &edge)
{
	DisjointSet ds(V);
	int extraEdges = 0;
	for(auto it :edge)
	{
		int u = it[0];
		int v = it[1];
		if(ds.UnionBySize(u,v) == false)//means same parent
		{
			extraEdges++;
		}
	}
	int noOfComponents = 0;
	for(int i = 0; i < ds.IsPartOf.size(); i++)
	{
		if(i == ds.IsPartOf[i])
		{
			noOfComponents++;
		}
	}
	if(extraEdges < noOfComponents - 1)
		return - 1;
	return noOfComponents - 1;
}

int main() {

    int V = 9;
    std::vector<std::vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    
    int ans = Solve(V, edge);
    std::cout << "The number of operations needed: " << ans << std::endl;
    return 0;
}
//Output: The number of operations needed: 2 (for example 2)


