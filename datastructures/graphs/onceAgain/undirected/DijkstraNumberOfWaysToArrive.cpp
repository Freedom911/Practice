/**
 *
 * https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/
 *
 * G-40: Number of Ways to Arrive at Destination
 *
 * Problem Statement - 
 * You are in a city that consists of n intersections numbered from 0 to n - 1 with 
 * bi-directional roads between some intersections. The inputs are 
 * generated such that you can reach any intersection from any other 
 * intersection and that there is at most one road between any two intersections.
 * You are given an integer n and a 2D integer array ‘roads’ where 
 * roads[i] = [ui, vi, timei] means that there is a road between 
 * intersections ui and vi that takes timei minutes to travel. 
 * You want to know in how many ways you can travel from 
 * intersection 0 to intersection n - 1 in the shortest amount of time.
 * Return the number of ways you can arrive at your destination in the shortest amount of time.
 * Since the answer may be large, return it modulo 109 + 7.
 *
 * Explained in One note
 *
 * So basically we have to count path to target while minimizing the cost
 *
 * eg 1 : 2,4
 *    2 : 3,4
 *    3 : 2,4
 *    4 : 2,3
 *
 *    In coming Edges to 3 is only 2. i.e indegre of 3 is only 2. We cant say that there are only 2 paths
 *    if we see we have 1-2-3,1-4-3,1-2-4-3,1-4-2-3. 
 *    We check Recursively
 *    3 comes from 2,4
 *    2 comes from 1,4 = 2 Path
 *    4 comes from 1,2 = 2 Path
 *
 *    So total path to 3 = rec path from (2) + rec path from (4)
 *
 *    Here like dijkstra we keep dist array,queue will store dist,node. where less distance will be explored first
 *    
 *    along with that we keep ways array
 *    
 *    ways store the number of ways one can reach a node
 *
 *    first time we reach a node with less distance we update with nodes neighbor
 *    
 *    eg 1-3
 *    
 *    ways[] = [3,inf]. number of ways to reach 1 = 3, number of ways to reach 3 curently is inf
 *    so we say we can reach node 3 with 3 ways. we basically copy the value of 1
 *
 *    Next time we have 2-3
 *    ways[] = [4,3]. Number of ways to reach 2 = 4, number of ways to reach 3 = 3
 *    so total ways to reach 3 is 4 + 3 = 7
 *
 *    we do this when we get less cost. we update to previous value
 *    if value is same we increment
 *     
 *    we use priority queue as we do ordering based on distance
 *    We will return after every path is explored for destination and not early exit
 *    as we want to calucalte sum of all paths
 */

#include <iostream>
#include <vector>
#include <queue>

int countPaths(int n,std::vector<std::vector<int>> &edges)
{
    if(edges.size() == 0)
    {
        return -1;
    }

    int dest = n - 1; //nth -1 node
    //we require adj list
    std::vector<std::pair<int,int>> adj[n];
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});//undirected
    }

    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pq; //dist,tonode
    std::vector<int> dist(n,1e9);
    std::vector<int> noOfWaysVector(n,-1);

    //Intiialization
    int S = 0;
    pq.push({S,S});
    dist[S] = 0;
    noOfWaysVector[S] = 1;
    int mod = (int)(1e9 + 7);
    while(pq.empty() == false)
    {
        int node = pq.top().second;
        int distVal = pq.top().first;
        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int adjW = it.second;
            int calDist = dist[node] + adjW;

            //there will two cases Now
            //if  distance is bstter
            //case 1 distance is better
            if(dist[adjNode] > calDist)
            {
                dist[adjNode] = calDist;
                noOfWaysVector[adjNode] = noOfWaysVector[node]; //just copy
                pq.push({calDist,adjNode});

            }
            //case 2 distance is same. we just increent the ways
            else if(dist[adjNode] == calDist)
            {
              noOfWaysVector[adjNode] += noOfWaysVector[node] % mod;
            }
        }
    }

    if(noOfWaysVector[dest] == -1)
    {
        return -1;
    }
    else
    {
        return noOfWaysVector[dest] % mod;
    }
}

int main()
{
    // Driver Code.
    int n = 7;

    std::vector<std::vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};


    int ans = countPaths(n, edges);

    std::cout << ans;
    std::cout << std::endl;

    return 0;
}



