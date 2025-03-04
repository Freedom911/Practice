
/**
 *
 * https://takeuforward.org/data-structure/number-of-provinces-disjoint-set-g-48/
 *
 * Problem Statement: Given an undirected graph with V vertices. We say two vertices 
 * u and v belong to a single province if there is a path from u to v or v to u.
 * Your task is to find the number of provinces.
 *
 * Solution 
 * I have already solved by running DFS/BFS multiple times and calculating components based on visited array
 *
 * Here we will use dis joint set
 *
 * How ?
 * We calculate PartOf in dis joint set
 * So is part of array will contain some unique value. the number of unique value is basically components
 *
 * eg 0-1-2   3-4   
 * IsPartOf[0,0,0,3,3]
 * Two unique values so 2 components
 *
 * Algo
 * Apply Disjoint Set and Get Part of vector
 * Valculate unique value
 */
#include <iostream>
#include <vector>

class DisjointSet
{
  public:
  std::vector<int> IsPartOf,Size;
  DisjointSet(int n)
  {
      IsPartOf.resize(n+1);
      Size.resize(n+1,1);
      for(int i = 0; i <= n; i++)
      {
          IsPartOf[i] = i;
      }
  } 

  int FindUPar(int node)
  {
      if(node == IsPartOf[node])
      {
          return node;
      }
      return IsPartOf[node] = FindUPar(IsPartOf[node]);
  }

  void UnionBySize(int u, int v)
  {
      int set1 = FindUPar(u);
      int set2 = FindUPar(v);
      if(set1 == set2)
      {
          return;
      }
      if(Size[set2] > Size[set1])
      {
          Size[set2] += Size[set1]; //merging to set 2
          IsPartOf[set1] = set2;
      }
      else
      {
          Size[set1] += Size[set2];
          IsPartOf[set2] = set1; //merging with set 1
      }

  }
};

int numProvinces(int V,std::vector<std::vector<int>>adj)
{
    DisjointSet ds(V);
    for(int i = 0; i < V; i++)
    {

        for(int j = 0; j < V; j++)
        {
            if(adj[i][j] == 1)
            {
                    ds.UnionBySize(i,j);//merge 2 sets
            }
        }
    }
    int count = 0;
    for(int i =0 ; i < V; i++)
    {
        if(i == ds.IsPartOf[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int V = 3;
    //We are given adj matrix
    std::vector<std::vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    int ans = numProvinces(V,adj);
    std::cout << "The number of provinces is: " << ans << std::endl;
    return 0;
}
