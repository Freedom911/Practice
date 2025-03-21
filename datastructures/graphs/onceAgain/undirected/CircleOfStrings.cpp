/**
 * https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/
 *
 * This problem is very good 
 *
 * Given an array of strings, find if the given strings can be chained to 
 * form a circle. A string X can be put before another string Y in circle 
 * if the last character of X is same as first character of Y.
 *
 * Examples: 
 * Input: arr[] = {"geek", "king"}
 * Output: Yes, the given strings can be chained.
 *
 * Note that the last character of first string is same
 * as first character of second string and vice versa is
 * also true.
 * Input : arr[] = [“ijk”, “kji”, “abc”, “cba”]
 * Output : No
 *
 * Solution - I have already Explained in one note. I will explain again
 *
 * So basically we have to check if we are able to form a cycle with given strings. 
 * We have to visit all nodes once only and the last node should connect to source to form
 * a cycle. The problem is simply Hamiltonian Cycle. The only issue is the complexity is n!
 * to minimize this we do some chalaki
 * We try to change it to euler cycle as we can solve it in linear time compleixty
 * for that we observer that we need only 1st and last character of a word
 * eg ik,ki,ac,ca
 * now we draw an edge between i->k and k->i basically between first and last character
 * so i->k represents ijk and k->i represents kji. so we create a graph with that
 * and we check that last node is connected to source node or not. The problem
 * boils to finding Euler Cycle. If the euler cycle is present then we can say that
 * cycle is present otherwise not.
 * what we did here is we changed our nodes condition to edge condition. so in euler cycle
 * we have to visit every edge. Every edge here means node in hamiltonian Path which is what we requires
 * We require every node to be visited once.
 * Here the graph formed after decomposition is directed. so we require euler path for directed graph
 * in Directed Graph indegree = outdegree. second condition of connected components is same.
 */
 
 #include <iostream>
 #include <vector>
 #include <string>
 
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
 
 bool IsCycleOfString(std::vector<std::string> &v1)
 {
	 //First we have to form adj list
	 //and degree
	 std::vector<int> adj[26]; //26 possible characters
	 std::vector<int> indegree(26,0);
	 std::vector<int> outdegree(26,0);
	 
	 for(int i = 0; i < v1.size(); i++)
	 {
		 int u = v1[i][0] - 'a';
		 int v = v1[i][v1[i].size() - 1] - 'a';
		 adj[u].push_back(v);
		 outdegree[u]++;
		 indegree[v]++;
	 }
	 
	 //now check condition 1 .  both degree shoudkl be same
	 for(int i = 0; i < 26; i++)
	 {
		 if(indegree[i] != outdegree[i])
		 {
			 return false;
		 }
	 }
	 
	 //Check condition 2. non 0 degree components shoudl be connected
	 std::vector<int> vis(26,0);
	 DFS(v1[0][0] - 'a',adj,vis);
	 
	 for(int i = 0; i < 26; i++)
	 {
		 //it means we cant visit but degree is still there
		 if(vis[i] == 0 && (indegree[i] != 0 || outdegree[i] != 0))
		 {
			 return false;
		 }
	 }
	 return true;
 }
 
 std::ostream & operator << ( std::ostream & out,const std::vector<std::string> &v1)
 {
	 out << "[";
	 for(size_t i = 0; i < v1.size(); i++)
	 {
		 out << v1[i];
		 if(i + 1 != v1.size())
		 {
			 out << ",";
		 }

	 }
	 out << "]";
	 return out;
 }
 
 int main()
 {
	 std::vector<std::string> v1{"geek","kinp","pinkg"};
	 std::cout << "\n Can We Form Cycle of string For " << v1 << "= " << IsCycleOfString(v1) << "\n";
	 
	 std::vector<std::string> v2{"ijk","kji","abc","cba"};
	 std::cout << "\n Can We Form Cycle of string For " << v2 << "= " << IsCycleOfString(v2) << "\n";
 }