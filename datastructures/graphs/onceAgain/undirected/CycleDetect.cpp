//Given a graph we need to detect if cycle is present or not and return true 
//We say a graph 0-1-2-0 is having cycle if it is having more than one mia baap
//for eg  initialluy we say 0 is visited by -1(parent)
//then we expand 0-1 then from one we can go to 2 and 0. 0 we avoid as it is already
//visited. Now for 2 we can go to 1 which is the parent of 2 itself so we ignore
//but 0 is already visited by -1 but we are saying 0 ka mai baap is 2 so matlb 2 parents
//extra maritial affair h. So ye karm ke bandhan m hai . jo apne life bhugnten aayega cylic 

#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<int>adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

//0-1
bool DFS(int node,std::vector<int>adj[],std::vector<int>vis,int parent)
{
	vis[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)//not yet visited
		{
			return DFS(it,adj,vis,node);
		}
		else if(vis[it] == 1 && parent != it)//iska mai baap koi aur h :(
		{
			return true;
		}
	}
	return false;
}

//BFS will also work
bool BFS(int start,int V,std::vector<int>adj[],std::vector<int> vis)
{
	
	vis[start] = 1;
	std::queue<std::pair<int,int>>q;//stores parent info as well
	q.push({start,-1});
	
	while(q.empty() == false)
	{
		int node = q.front().first;
		int parent = q.front().second;
		vis[node] = 1;
		q.pop();
		
		for(auto it: adj[node])
		{
			if(vis[it] == 0)
			{
				q.push({it,node}); //iska mai baap abhi node h jaha se expand hua
			}
			//we have to take care for valid case
			//like 0 - 1 . 1 is visited form 0. when expanding 1 we have 1 as node
			//parent as 0. and it i.e of 1 is 0. so if parent was different than it
			//we ignore
			else if(vis[it] == 1 && it != parent)//means iska parent is do do : (
			{
				return true;
			}
		}
		
	}
	return false;
}

bool IsHavingCycle(int V,std::vector<int> adj[])
{
	std::vector<int> vis(V,0);
	for(int i = 0; i < V; i++)
	{
		//always start from parent node as -1 . Initially
		//if(DFS(i,adj,vis,-1) == true)
		if(BFS(i,V,adj,vis) == true)
		{
			return true;
		}
	}
	
	return false;
}





int main()
{
 int V = 6;

  std::vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  
  std::cout << "\n IS HAVING CYCLE = " << IsHavingCycle(V,adj);
  }