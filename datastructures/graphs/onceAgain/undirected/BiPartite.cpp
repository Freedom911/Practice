/**
 * https://takeuforward.org/graph/bipartite-graph-dfs-implementation/
 *
 * Problem Statement: Given an adjacencay 
 * list of a graph adj of V no. of vertices having 0 based index. 
 * Check whether the graph is bipartite or not.
 * If we are able to colour a graph with two colours such that no 
 * adjacent nodes have the same colour, it is called a bipartite graph.
 * 
 *
 * I will be solving with both the traversals.
 *
 * so the main idea is instead of visited we keep a color list . which is similar to visited
 * 
 * if color[node] == -1 then explore
 *
 * but if not then we check if color[node] == color[parents node] -> Means both parent and child node same color
 * so not possible booya
 */

#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<int> adj[],const int &u,const int &v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//In this function we pas new color. Initially it is passed as 0.
//on every recursive color we select inverse
bool dfs(int node,int newColor,int color[],std::vector<int> adj[])
{
    color[node] = newColor;

    for(auto it: adj[node])
    {
        if(color[it] == -1)
        {
            if(dfs(it,!newColor,color,adj) == false)
            {
                return false;
            }
        }
        else if (color[it] == newColor)
        {
            return false;
        }
    }

    return true;
}

bool bfs(int node,int color[],std::vector<int>adj[])
{
   color[node] = 0;
   std::queue<int> q;
   q.push(node);

   while(q.empty() == false)
   {
       int qTop = q.front();
       q.pop();

       for(auto it : adj[qTop])
       {
           if(color[it] == -1)
           {
               //assigning color
               color[it] = !color[qTop];
               q.push(it);
           }
           // if color is same as parent. Then samsya is there
           else if(color[it] == color[qTop])
           {
               return false;
           }
       }
   }
   return true;
}

bool isBipartite(int V, std::vector<int>adj[])
{
    //create visited i mean color
    int color[V] = {-1};
    for(int i = 0;i<V;i++) color[i] = -1;
    for(int i = 0; i < V; i++)
    {
        if(color[i] == -1)
        {
            //Start Exploring
            //False means in the bfs traversal we ofund that it is not bi partite
            //if(bfs(i,color,adj) == false)
            if(dfs(i,0,color,adj) == false)
            {
                std::cout << "\nFAIL\n";
                return false;
            }
        }

    }
    return true;
}

int main()
{
    std::vector<int>adj[2];

	addEdge(adj, 0, 1);
   	//addEdge(adj, 0, 2);
    std::cout << "\n Is Bi Partite = " << isBipartite(2,adj) << "\n";
}
