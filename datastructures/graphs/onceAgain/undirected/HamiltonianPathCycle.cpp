/**
 * https://www.geeksforgeeks.org/hamiltonian-cycle/
 *
 * I have explained this in one note
 *
 * So Basically Hamiltonian Path is a path in which every node is visited once. In Euler path
 * we visited edge here we visit node
 *
 * Similarly Hamiltonian Cycle is a path in which every node is visited once and we end up at same
 * node
 *
 * Both These problems are NP Complete and we do brute force by checking Running DFS from every node until we visit
 * all nodes once only
 *
 * Use Case
 * Assume every edge weight is 1 and we want to visit all cities to give parcels. So we want to avoid visiting
 * nodes again and again.
 * This is the core concept of Travelling Salesman Person which also is an NP Complete Problem
 *
 * For Hamiltonian Path we do Brute force with every node and check if all nodes possible by comaring the visited
 * array size were it is 1 with total vertex. if equal then we have visited all and hence hamiltonian path
 *
 * For Hamiltonian Cycle we basically do the same thing. but here we do brute force ill we get a path where we 
 * end at same source. if not then we back track. We keep the last node that was discovered and check if
 * its neighbor contains source if yes then cycle is there else backrack
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

bool DFS(int node,std::vector<int>adj[],std::vector<int> &vis,int &count,int totalVertex)
{
    vis[node] = 1;
    count++;

    if(count == totalVertex)
    {
        return true;
    }

    for(auto it : adj[node])
    {
        if(vis[it] == 0 && DFS(it,adj,vis,count,totalVertex))
        {
            return true;
        }
    }

    //Back travk
    vis[node] = 0;
    count--;
    return false;
}

void CheckHamiltonianPath(std::vector<int>adj[],int V)
{
    if(V == 0)
    {
        std::cout << "\n 0 Vertex Provided \n";
        return;
    }
    
    int totalVertex = V;
    int count = 0;
    std::vector<int> vis(V,0);
    //we have to do DFS traversal
    for(int i = 0; i < V; i++)
    {
        if(DFS(i,adj,vis,count,totalVertex))
        {

            std::cout << "\n Hamiltonian Path Exists \n";
            return;
        }
    }

    std::cout << "\n Hamiltonian Path Doesnt Exist \n";
}

bool DFSHamiltonianCycle(int initialSource,int node,std::vector<int>adj[],
                         std::vector<int> &vis,int &count,int totalVertex,int &lastNode,
                         std::vector<int> &exactPath)
{
    vis[node] = 1;
    exactPath.push_back(node);
    count++;

    if(count == totalVertex)
    {
        //Check if last node neight bor is source
        for(auto it : adj[lastNode])
        {
            if(it == initialSource)
            {
                return true;
            }
        }
    }

    for(auto it : adj[node])
    {
        lastNode = it;
        if(vis[it] == 0 && DFSHamiltonianCycle(initialSource,it,adj,vis,count,totalVertex,lastNode,exactPath))
        {
            return true;
        }
    }

    //Back travk
    vis[node] = 0;
    exactPath.pop_back();
    count--;
    return false;
}


void CheckHamiltonianCycle(std::vector<int>adj[],int V)
{
    if(V == 0)
    {
        std::cout << "\n 0 Vertex Provided \n";
        return;
    }
    
    int totalVertex = V;
    int count = 0;
    std::vector<int> vis(V,0);
    std::vector<int> exactPath;
    //we have to do DFS traversal
    for(int i = 0; i < V; i++)
    {
        int lastNode = i;
        if(DFSHamiltonianCycle(i,i,adj,vis,count,totalVertex,lastNode,exactPath))
        {

            std::cout << "\n Hamiltonian Cycle Exists \n";
            std::for_each(exactPath.begin(),exactPath.end(),[](const int &elem){
                std::cout << elem << "->";
            });
            std::cout << i << "\n";
            return;
        }
    }

    std::cout << "\n Hamiltonian Cycle Doesnt Exist \n";
}

int main()
{
    std::vector<int> adj[5];
    adj[0] = {1,3};
    adj[1] = {0,3,2,4};
    adj[2] = {1,4};
    adj[3] = {0,1,4};
    adj[4] = {1,2,3};

    CheckHamiltonianPath(adj,5);
    CheckHamiltonianCycle(adj,5);




    std::vector<int> adj1[5];
    adj[0] = {1,3};
    adj[1] = {0,3,2,4};
    adj[2] = {1,4};
    adj[3] = {0,1};
    adj[4] = {1,2};

    CheckHamiltonianPath(adj1,5);

    //Graph with Hamiltonian Path but not cycle
    //0-1-2
    std::vector<int> adj2[3];
    adj2[0] = {1};
    adj2[1] = {0,2};
    adj2[2] = {1};

    CheckHamiltonianPath(adj2,3);
    CheckHamiltonianCycle(adj2,3);
}
