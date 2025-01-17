//No of provinces we have to calculate
//Provinces means number of different components
//eg graph contains 0-1-2 then 3-4-5 then 6-7 then 8
//so total 4 provinces
//Simple run DFS/BFS for all nodes and so from 0 1,2, will be visited increment count
//3 will cover 4 and 5 then 6 will cover 

#include <iostream>
#include <vector>

void AddEdge(std::vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node,std::vector<int> adj[],int visited[])
{
    visited[node] = 1;
    for(auto it: adj[node])
    {
        if(visited[it] == 0)
        {
            dfs(it,adj,visited);
        }
    }
}

int GetCountProvinces(std::vector<int> adj[], int V)
{
    int count = 0;
    int visited[V] = {0};

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i,adj,visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int N = 9;
    std::vector<int> adj[N];
    AddEdge(adj,0,1);
    AddEdge(adj,1,2);
    AddEdge(adj,3,4);
    AddEdge(adj,4,5);
    AddEdge(adj,6,7);
    AddEdge(adj,6,7);
    AddEdge(adj,8,8);

    std::cout << "\n Total Provinces = " << GetCountProvinces(adj,N) << "\n";
}

