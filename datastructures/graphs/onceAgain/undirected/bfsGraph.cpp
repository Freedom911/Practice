//Breath First Search is a level order traversal 
//Similar to the tree one
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
//Here we mark result to avoid visiting same node
#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

void bfs(std::vector<int> adj[],int n)
{
    //data structure we use is queue
    int visited[n]={0};

    std::queue<int>q;
    q.push(0);

    visited[0] = 1;

    while(q.empty() == false)
    {
        int node = q.front();
        std::cout << node << ",";
        q.pop();

        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

int main()
{
  int V = 5;
  std::vector<int> vec[V];

  addEdge(vec,0,1);
  addEdge(vec,0,2);
  addEdge(vec,2,3);
  addEdge(vec,1,4);
  addEdge(vec,3,4);
  bfs(vec,5);

}
