/**
 * https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/
 *
 *
 * Problem Statement: You are given an n, m which means the row and 
 * column of the 2D matrix, and an array of size k denoting the number of operations. 
 * Matrix elements are 0 if there is water or 1 if there is land. Originally, 
 * the 2D matrix is all 0 which means there is no land in the matrix. 
 * The array has k operator(s) and each operator has two integers A[i][0], 
 * A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island.
 * Return how many islands are there in the matrix after each operation. 
 * You need to return an array of size k.
 *
 * Note: An island means a group of 1s such that they share a common side.
 * Pre-requisite: Disjoint Set data structure
 * Example 1:
 * Input Format: n = 4 m = 5 k = 4 A = {{1,1},{0,1},{3,3},{3,4}}
 * Output: 1 1 2 2 
 *
 * Solution 
 * So there are two solution
 * Basically We know how to calculate islands by DFS. So after every query we can run DFS but it will be expensive
 *
 * Other Solution Would be to Use disjoint set why? Because the graphs is dynamic
 *
 * So what we will do we create a disjoint set of total n * m nodes. whenver a island comes which is not part of 
 * any island of its 4 surrounding(we check by using findUPar). If it is not a part of island we dont increment
 * else we do
 *
 * We keep a visited array to responb back to query
 *
 * Now for disjoint set we pass single number and not row column. so we change row column to same number
 *
 * eg 2,2 means 2 * total col + row number
 *
 * We increment the count generally. now if we find a node which in surrounding and currenly not in same set
 * then we include in the same island and decrement the count so basically net isalnd remains same
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
                IsPartOf[setU] = setV;
            }
            else
            {
                Size[setU] += Size[setV];
                IsPartOf[setV] = setU;
            }
            return true;
        }
};

std::vector<int> numOfIslands(int n, int m, std::vector<std::vector<int>> &operators)
{
    DisjointSet ds(n * m);
    //std::vector<std::vector<int>>vis(n,std::vector<int>(m,0));
    int vis[n][m] = {0};
    std::vector<int> op;

    int cnt = 0;
    for(int i = 0; i < operators.size(); i++)
    {
        int queryRow = operators[i][0];
        int queryCol = operators[i][1];

        if(vis[queryRow][queryCol] == 1)
        {
            op.push_back(cnt);
            continue;
        }

        vis[queryRow][queryCol] = 1;
        cnt++;

        //go to 4 neighbors
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int j = 0; j < 4; j++)
        {
            int nr = dr[j] + queryRow;
            int nc = dc[j] + queryCol;

            //Check Validity
            if(nr >= 0 && nc >=0 && nr < n && nc < m && vis[nr][nc] == 1)//vis 1 means it isisland then only we include
            {
                int node = queryRow * m + queryCol;
                int adjnode = nr * m + nc;

                if(ds.findUPar(node) != ds.findUPar(adjnode))//means not in same set. but we will include.
                {
                    //so we dont want to increase the cnt. so we subtract
                    cnt--;
                    ds.UnionBySize(node,adjnode);
                }
            }
        }

        op.push_back(cnt);
    }
    return op;
}

int main() 
{

    int n = 4, m = 5;
    std::vector<std::vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    std::vector<int> ans = numOfIslands(n, m, operators);
    for (auto res : ans) {
        std::cout << res << " ";
    }
    std::cout << std::endl;
    return 0;
}
