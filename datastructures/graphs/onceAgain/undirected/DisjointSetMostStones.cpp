/**
 * https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/
 *
 * Most Stones Removed with Same Row or Column - DSU: G-53
 * Problem Statement: There are n stones at some integer coordinate 
 * points on a 2D plane. Each coordinate point may have at most one stone.
 * You need to remove some stones.
 * A stone can be removed if it shares either the same row or the 
 * same column as another stone that has not been removed.
 * Given an array of stones of length n where stones[i] = [xi, yi] 
 * represents the location of the ith stone, return the maximum possible number of stones that you can remove.
 *
 * Pre-requisite: Disjoint Set data structure
 * 
 * Example 1:
 * Input Format: n=6  stones = [[0, 0],[ 0, 1], [1, 0],[1, 2],[2, 1],[2, 2]]
 * Result: 5
 *
 * Explanation: One of the many ways to remove 5 stones is to remove the following stones:
 * 0,0], [1,0], [0,1], [2,1], [1,2]
 *
 * Solution
 *
 * So no of stones that can be removed depends on the size of set
 * So consider set of size 3 then we can have 2 stones removed. How?
 *
 * Stone present at [0,0],[0,1] and [1,0] all belong to same set. How do we decide same set?
 * we discuss this latter. so by size of disjoint set stores size to be 3. so total stones
 * that can be removed is size - 1 = 2 which is correct.
 *
 * How do we decide whehther they belong to same set. so using the knowledge of previous prolem 
 * No of island2 where we ran adj list on 4 neighbors
 * here we consider same row and same col as adjacent. so any node present in the row or col is 
 * considered to be in same set.
 */

#include <iostream>
#include <vector>

class DisjointSet
{
    public:
        std::vector<int>IsPartOf,Size;
        DisjointSet(int n)
        {
            IsPartOf.resize(n+1,0);
            Size.resize(n+1,1);
            for(int i = 0;i <= n; i++)
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
				//std::cout << u << "-" << v << " " << Size[setV] << "\n";
                IsPartOf[setU] = setV;
            }
            else
            {
                Size[setU] += Size[setV];
				//std::cout << u << "-" << v << " " << Size[setU] << "\n";
                IsPartOf[setV] = setU;
            }
            return true;
        }
};

int maxRemove(std::vector<std::vector<int>> &stones,int n)
{
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = std::max(maxRow, it[0]);
        maxCol = std::max(maxCol, it[1]);
    }
	
	int totalCol = maxCol + 1;
	int totalRow = maxRow + 1;
    
    DisjointSet ds( totalRow * totalCol);
	int vis[totalRow][totalCol]={}; //initializes to 0


    for(int i = 0; i < stones.size(); i++)
    {
        int queryRow = stones[i][0];
        int queryCol = stones[i][1];
		vis[queryRow][queryCol] = 1;
		

        int node = (queryRow * totalCol) + queryCol;

        //for same row
        for(int j = 0; j < totalCol ; j++)
        {
			if(j == queryCol || vis[queryRow][j] == 0)
				continue;

            int adj = (queryRow * (totalCol)) + j;
			
			
            ds.UnionBySize(node,adj);
        }

        //for same col
		
        for(int j = 0; j < totalRow ; j++)
        {
			if(j == queryRow || vis[j][queryCol] == 0)
				continue;
            int adj = j * (totalCol) + queryCol;
			
            ds.UnionBySize(node,adj);
        }
    }
    
    int total = 0;
    for(int i = 0; i < ds.Size.size(); i++)
    {
		
        if(i == ds.IsPartOf[i])
        {
	
            total += (ds.Size[i] - 1);
        }
    }
	std::cout << "\n";
    return total;

}

int main() 
{
#if 1
    int n = 6;
    std::vector<std::vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };
	#else
	int n = 3;
    std::vector<std::vector<int>> stones = {
        {0, 0}, {0,1},
        {1, 0}
    };
	#endif

    int ans = maxRemove(stones, n);
    std::cout << "The maximum number of stones we can remove is: " << ans << std::endl;
    return 0;
}


