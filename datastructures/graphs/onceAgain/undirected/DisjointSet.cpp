/**
 * https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/
 *
 * I have explained in one please refer. Kruskal and Disjoint set
 *
 * Disjoint set as the name suggests uses Set for connecting components
 *
 * It is used in Kruskal Algo
 *
 * Disjoin set Uses Some useful concept for optimization
 *
 * 1. Union By Size or Union By Rank - Both of these concepts are used to help in merging two sets
 *    Out Main Goal is to minimize the number of changes Required while merging.like merge set 1 with 3
 *    we need to change all 3s to 1. So Union by size or rank ensures that the changes that needs to be done
 *    is low
 * 2. Path Compression - This is done while finding Ultimate parent. this technique helps to find ultimate parent
 *    quickly by directly connecitng the node to its ultimate parent
 *
 *    Union By rank uses concept of max height while union by size uses size to merge
 */

#include <iostream>
#include <vector>

class DisjointSet
{
    public:
    DisjointSet(int n)
    {
        IsPartOf.resize(n+1);
        Rank.resize(n+1,0);
        Size.resize(n+1,1);

        //Since starting from one
        for(int i = 0; i <=n; i++)
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
int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        std::cout << "Same\n";
    }
    else 
    {
        std::cout << "Not same\n";
    }

    ds.UnionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) 
    {
        std::cout << "Same\n";
    }
    else 
    {
        std::cout << "Not same\n";
    }


    DisjointSet ds1(7);
    ds1.UnionBySize(1, 2);
    ds1.UnionBySize(2, 3);
    ds1.UnionBySize(4, 5);
    ds1.UnionBySize(6, 7);
    ds1.UnionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds1.findUltimateParent(3) == ds1.findUltimateParent(7)) {
        std::cout << "Same\n";
    }
    else std::cout << "Not same\n";

    ds1.UnionBySize(3, 7);

    if (ds1.findUltimateParent(3) == ds1.findUltimateParent(7)) {
        std::cout << "Same\n";
    }
    else std::cout << "Not same\n";
    return 0;
}

