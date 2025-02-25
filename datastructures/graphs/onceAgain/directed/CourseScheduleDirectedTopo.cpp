/**
 *
 * https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/
 *
  Problem Statement I (Course Schedule): There are a total of n tasks you have to pick,
  labeled from 0 to n-1. Some tasks may have prerequisites tasks, 
  for example, to pick task 0 you have to first finish tasks 1, 
  which is expressed as a pair: [0, 1]

  Given the total number of n tasks and a list of prerequisite pairs of size m.
  Find the order of tasks you should pick to finish all tasks.

  Note: There may be multiple correct orders, you need to return one of 
  them. If it is impossible to finish all tasks, return an empty array.
  
  Solution - This is totally Topo Sort.  Basially first we create directed graph and apply topo sort
  then for topo sort to be successful there should ne no cycle. which topo sort detects
 */ 

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

//on same path pe h to cycle h
bool DFS(int node,std::vector<int> adj[],std::vector<int> &path,std::vector<int> &vis,std::stack<int> &st)
{
	vis[node] = 1;
	path[node] = 1;
	
	for(auto it : adj[node])
	{
		if(vis[it] == 0)
		{
			if(DFS(it,adj,path,vis,st) == true)
			{
				return true;
			}
		}
		else if(path[it] == 1)
		{
			return true;
		}
	}
	path[node] = 0;//Back track
	st.push(node);
	return false;
}

bool isPossible(int N,std::vector<std::pair<int,int>> pre)
{
	//1st step create adj list
	std::vector<int> adj[N];
	for(int i = 0; i < pre.size(); i++)
	{
		int u = pre[i].second;   //[0,1] then to pick 0 1 has to be finished so. 1->0
		int v = pre[i].first;
		adj[u].push_back(v);
	}
	
#if 0
	std::stack<int>st;
	std::vector<int> vis(N,0);
	std::vector<int> path(N,0);
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 0)
		{
			if(DFS(i,adj,path,vis,st) == true)
			{
				return false;//return not possible
			}
		}
	}
	while(st.empty() == false)
	{
		std::cout << st.top() << "->";
		st.pop();
	}
	std::cout << "END\n";
	return true;
	#else
		
	//Using Kahn algorithm
	std::vector<int> Indegree(N,0);
	std::queue<int> q;
	
	for(int i = 0; i < N; i++)
	{
		for(auto it : adj[i])
		{
			Indegree[it]++;
		}
	}
	
	//Initialization condition for queue
	std::vector<int> res;
	for(int i = 0; i < N; i++)
	{
		if(Indegree[i] == 0)
		{
			res.push_back(i);
			q.push(i);
		}
	}
	
	while(q.empty() == false)
	{
		int node = q.front();
		q.pop();
		
		for(auto it : adj[node])
		{
			//after removing node. reduce indegree of its neighbor
			Indegree[it]--;
			if(Indegree[it] == 0)
			{
				res.push_back(it);
				q.push(it);
			}
		}
	}
	if (res.size() != N) //return false. not possible cycle present
	{
		return false;
	}
	
	auto lambda = []<typename T>(const T &elem){
		std::cout << elem << "->";
	};
	std::for_each(res.begin(),res.end(),lambda);
	std::cout << "\n END\n";
	
	
		
	#endif
}




int main()
{
    std::vector<std::pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});
	//prerequisites.push_back({0, 3}); //on uncommenting this it should say no as it introcudes cycle

	
	bool ans = isPossible(N, prerequisites);

	if (ans) std::cout << "YES";
	else std::cout << "NO";
	std::cout << "\n" ;

	return 0;
}

