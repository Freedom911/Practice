/**
 * 
 *  https://www.geeksforgeeks.org/eulerian-path-and-circuit/
 
 *
 * Euler Path is a path in which each edge is visited once only
 * and Euler Circuit is a path which ends at same node from where we started
 * Solution
 *
 * I have already explained in One Note.
 * So basically we check via short cut method and not brute force as brute force will be expensive
 * We say a path is euler cycle if every node is having even degree and there is no non zero degree
 * node in separate component
 * we say a path is euler path if every node is having even degree except 0 or two. second condition is same
 * Again I have explained in one note please refer 
 */ 
 
 
 #include <iostream>
 #include <vector>
 
 void addEdge(std::vector<int> adj[],int u,int v)
 {
	 adj[u].push_back(v);
	 adj[v].push_back(u);
 }
 
 void DFS(int node,std::vector<int> adj[],std::vector<int> &vis)
 {
	 vis[node] = 1;
	 
	 for(auto it : adj[node])
	 {
		 if(vis[it] == 0)
		 {
			 DFS(it,adj,vis);
		 }
	 }
 }
 
 void test(std::vector<int> adj[],int V)
 {
	 //check degree
	 std::vector<int> Degree(V,0);
	 for(int i = 0; i < V; i++)
	 {
		 for(auto it : adj[i])
		 {
			 int u = i;
			 int v = it;
			 Degree[u]++;
			 
		 }
	 }
	 
	 int Odd = 0;
	 for(int i = 0; i < V; i++)
	 {
		 std::cout << "\n Degree of " << i << " " << Degree[i] << "\n";
		 if(Degree[i] % 2 != 0)
		 {
			 Odd++;
		 }
	 }
	 
	 
	 //Euler Path can have 0 or two nodes with odd degree
	 //Euler Cycle will have 0 nodes with Odd degree
	 //Check condition 1
	 if(Odd == 0 || Odd == 2)
	 {
		 std::vector<int> vis(V,0);
		 DFS(0,adj,vis);
		 
		 //Check Condition 2
		 for(int i = 0; i < V; i++)
		 {
			  if(vis[i] == 0 && Degree[i] != 0)
			  {
				  std::cout << "\n Graph is neither having Euler Cycle not Euler Path \n";
				  return ;
			  }
		 }
		 
		 if(Odd == 0)
		 {
			 std::cout << "\n Graph Having Euler Cycle \n";
		 }
		 else
		 {
			 std::cout << "\n Graph Having Euler Path Only and not Cycle \n";
		 }
		 return;
	 }

		 std::cout << "\n Graph is neither having Euler Cycle not Euler Path \n";
 }

 int main()
 {
    std::vector<int> adj[5];
    addEdge(adj,1, 0);
    addEdge(adj,0, 2);
    addEdge(adj,2, 1);
    addEdge(adj,0, 3);
    addEdge(adj,3, 4);
    addEdge(adj,1, 3);
    test(adj,5);

	

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
	std::vector<int> adj1[3];
    addEdge(adj1,0, 1);
    addEdge(adj1,1, 2);
    addEdge(adj1,2, 0);//ON commenting we get euler path only
    test(adj1,3);
 }