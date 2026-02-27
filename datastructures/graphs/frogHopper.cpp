/**
 * https://leetcode.com/problems/frog-position-after-t-seconds/solutions/
 * TO CHECK After running
 */ 

#include <iostream>
#include <vector>
#include <queue>



class Solution {
public:
    //we return the probability
    //
    double frogPosition(int n, std::vector<std::vector<int>>& edges, int t, int target) 
    {
        std::vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        std::vector<int> vis(n,0);
        

        
        std::queue<std::pair<int,double>>q;
        q.push({0,1});
        vis[0] = 1;
        int level = 0;
        target--;

        while(q.empty() == false)
        {
            int qsize = q.size();

            for(int i = 0; i < qsize; i++)
            {
                int node = q.front().first;
                double prob = q.front().second;
                q.pop();

                int childs = 0;
                for(auto it : adj[node])
                {
                    if(vis[it] == 0)
                    childs++;
                }

                if(node == target)
                {
                    //Means we reach the target at t time or if nothing to explore and we found the target
                    if(level == t || (level < t && childs == 0)) //if we found the target exactly at t or early with no children
                    return prob;
                    else
                    return 0;
                }
      
        
                
                for(auto it : adj[node])
                {
                    //int childs = adj[node].size();


                    double newProb = prob;
                    if(childs > 0)
                    newProb = prob/childs;

                    if(vis[it] == 0)
                    {
                    
                        vis[it] = 1;
                        q.push({it,newProb});
                    }
                }
            }
                      level++;
        }

        return 0;
    }
};

int main()
{

    int n, time, target_node;
    n = 7;
    time = 1;
    target_node = 7;
    std::vector<std::vector<int>> edges = { { 1, 2 }, { 1, 3 }, { 1, 7 }, { 2, 4 }, { 2, 6 }, { 3, 5 } };
    std::vector<std::vector<int>> efges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    
    // Function Call
    Solution s;
    std::cout << s.frogPosition(n, edges, time, target_node) << std::endl; // Output the result
    return 0;

}