/**
 * https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/
 *
 * Bellman Ford Algorithm: G-41
 *
 * Problem Statement: Given a weighted, directed and connected 
 * graph of V vertices and E edges, Find the shortest 
 * distance of all the vertices from the source vertex S.
 * Note: If the Graph contains a negative cycle then return an array consisting of only -1.
 * Example 1:
 * Input Format: 
 * V = 6, 
 * E = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], 
 * S = 0
 *
 * Solution - 
 * I have explained in one note
 * So basically Bellman ford algorith does the same job as Dijikstra
 * With Dijkstra it is not possible for negative edge cycle as it gets into infinite Loop
 * So Bellman uncle khete h ki nahi . we restrict the number of times it will expand
 * Bellman uncle says ki we need to relax edges V -1 times where V is the number of vertex
 * Why V -1 ? because in worst case we get the answer i.e min distance at V -1 iteration
 * This is because the ordering of adj list. it can be in any order
 * After V -1 the distance array wont be updated 
 * Bellman ford works for Directed Graph only
 */
#include <iostream>
#include <vector>

std::vector<int> BellmanFord(int V,std::vector<std::vector<int>> &edges,int S)
{
    std::vector<int> dist(V,1e9);
    dist[S] = 0;
    for(int i = 0; i < V -1; i++)
    {
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    //To  check if cycle exits or not we do bellman ford one more time
    for(auto it: edges)
    {

        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            return {-1}; //cycle exits
        }
    }

    return dist;
}

int main() 
{

    int V = 6;
    std::vector<std::vector<int>> edges(7, std::vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};

    int S = 0;
    std::vector<int> dist = BellmanFord(V, edges, S);
    for (auto d : dist) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}
