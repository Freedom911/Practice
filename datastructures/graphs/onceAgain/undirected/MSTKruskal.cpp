/**
 * https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/
 *
 * Problem Statement: Given a weighted, undirected, and 
 * connected graph of V vertices and E edges. The task is to 
 * find the sum of weights of the edges of the Minimum Spanning Tree.
 *
 * Example 1:
 * Input Format:
 * V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
 *
 * Result: 16
 * Explanation: The minimum spanning tree for the given graph is drawn below:
 * MST = {(0, 1), (0, 3), (1, 2), (1, 4)}
 *
 * Solution 
 * I have explained in One Note please refer to that
 *
 * I will use Disjoint set
 * Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. 
 * O(N+E) for extracting edge information from the adjacency list. 
 * O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the 
 * disjoint set operations inside a loop. The loop will continue to E times. Inside that 
 * loop, there are two disjoint set operations like findUPar() and UnionBySize() 
 * each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.
 *
 * Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes.
 * O(E) space is taken by the array that we are using to store the 
 * edge information. And in the disjoint set data structure, we are 
 * using two N-sized arrays i.e. a parent and a size array 
 * (as we are using unionBySize() function otherwise, a rank array of the 
 * same size if unionByRank() is used) which result in the first two terms O(N).
 */

#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet
{
    public:
    DisjointSet(int n)
    {
        IsPartOf.resize(n+1);
        Rank.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i = 0; i <= n; i++)
        {
          IsPartOf[i] = i;
        }

    }
    int findUltimateParent(int u)
    {
        if(u == IsPartOf[u])
        {
            return u;
        }

        return IsPartOf[u] = findUltimateParent(IsPartOf[u]);
    }

    void UnionByRank(int u,int v)
    {
        int set1 = findUltimateParent(u);
        int set2 = findUltimateParent(v);
        
        //Means both belong to same set
        //so no need to do anything
        if(set1 == set2)
        {
            return;
        }
        
        if(Rank[set1] == Rank[set2])
        {
           Rank[set1]++;
           IsPartOf[v] = set1;//v is part of set 1 now
        }
        else if(Rank[set1] > Rank[set2])
        {
           IsPartOf[v] = set1;//v is part of set 1 now

        }
        else
        {
            IsPartOf[u] = set2;
        }


    }

    void UnionBySize(int u,int v)
    {
        int set1 = findUltimateParent(u);
        int set2 = findUltimateParent(v);
        
        //Means both belong to same set
        //so no need to do anything
        if(set1 == set2)
        {
            return;
        }
        
        //Merge with set 2
        if(Size[set1] < Size[set2])
        {
            IsPartOf[u] = set2;
            Size[set2] += Size[set2];
        }
        else
        {
            IsPartOf[v] = set1;
            Size[set1] += Size[set2];
        }
#if 0
        //merge with set 1
        else if (Size[set2] < Size[set1])
        {
            IsPartOf[v] = set1;
            Size[set1] += Size[set2];
        }
        else//if same we attach to set1
        {
            IsPartOf[v] = set1;
            Size[set1] += Size[set2]
        }
        //we can merge last two
#endif


    }
    private:
    std::vector<int>IsPartOf;
    std::vector<int>Rank;
    std::vector<int>Size;
};

int spanningTree(int V,std::vector<std::vector<int>> adj[])
{
   //we need to sort on the basis of weight so we create vector of weight 
   std::vector<std::pair<int,std::pair<int,int>>> edges;//weight,u,v
   for(int i = 0; i < V; i++)
   {
       for(auto it: adj[i])
       {
           int u = i;
           int v = it[0];
           int w = it[1];
           edges.push_back({w,{u,v}});
       }
   }

   std::sort(edges.begin(),edges.end());
   DisjointSet ds(V);
   int mstCost = 0;
   for(int i = 0; i < edges.size(); i++)
   {
      int u = edges[i].second.first;
      int v = edges[i].second.second;
      int w = edges[i].first;
      if(ds.findUltimateParent(u) != ds.findUltimateParent(v)) //means both in different set we can merge
      {
        mstCost += w;
        ds.UnionBySize(u,v);
      }
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

    int mstWt = spanningTree(V, adj);
    std::cout << "The sum of all the edge weights: " << mstWt << std::endl;
    return 0;
}
