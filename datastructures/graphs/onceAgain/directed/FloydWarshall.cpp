/**
 *
 *  https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/
 *
 * Problem Statement: The problem is to find the shortest distances between every 
   pair of vertices in a given edge-weighted directed graph. The graph is represented 
   as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.  
 *
 *
 * So Both Dijikstra and Bellman Ford algorithm are Single Source Destination algorithm
 * Floyd Warshall is multi source destination algorithm
 * Meaning it will find path from all nodes to each other
 * 
 * We can apply Dijkstra Algorithm as well as Bellan ford algorithm for each nodes
 * For that case Time complexity O(V * Dijikstra/Bellman Ford Complexity)
 * Space COmpleixty O(V2)
 *
 * Warshall is O(V3)
 * In dense Graph Time COmpleixty of Dijkstra is O(v2). in sparse O(ElogV). IN sparse
 * it is better than Warshall uncle ki algorithm
 
 * Algo
 * Warshall uses adj matrix. So 0->1->2 where 0->1 takes 100,1->2 takes 200
 * so to find path from 0->2 warshall uses intermediate nodes
 * matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j])
 * k is the intermediate node and the matrix stores the minimum cost to reach a node
 * 
 *   0    1    2
 * 0 0   100  200
 * 1 inf  0   100
 * 2 inf  inf  0
 * so 0,2 entry represens the  min cost to reach node 2 from 0 via some intermediate node
 * 
 * CYCLE DETECTION ----
 * It can also detect  Cycle basically if we get a path where we can reach source to source in 
 * negative then there is negative cycle eg 1->2->3->1. 1->2 takes 3,2->3 takes 2,3->1 takes -7
 * total edge weight 3 + 2 - 7 = -2
 * Now 1->1 will not be 0. it will negative if negtaive. if greater than 0 then positive
 *  
 * As you can see it uses previous compluted result for eg to find 0->2 it will use 1->2 and 0->1
 * this is a problem of DP tabular method
 */
 #include <iostream>
 #include <vector>
 void shortest_distance(std::vector<std::vector<int>> &matrix)
 {
	 int V = matrix.size();
	 for(int i = 0; i < V; i++)
	 {
		 for(int j = 0; j < V; j++)
		 {
			 //Changing minus to infinity 
			 if(matrix[i][j] == -1)
			 {
				 matrix[i][j] = 1e9;
			 }
			 if(i == j)
				 matrix[i][j] = 0;
		 }
	 }
	 
	 for(int k = 0 ; k < V; k++) //intermediate node
	 {
		 for(int i = 0; i < V; i++)
		 {
			 for(int j = 0; j < V; j++)
			 {
				 matrix[i][j] = std::min(matrix[i][j],matrix[i][k] + matrix[k][j]); //just like DP
				 if(i == j)
				 {
					 if(matrix[i][j] > 0)
					 {
						std::cout << "\n POsitive Edge Cycle Found \n";
						
					 }
					 else if(matrix[i][j] < 0)
					 {
						 std::cout << "\n Negative Edge Cycle Found Returning \n";
						 return;
					 }
					 
				 }
			 }
		 }
	 }
	 for(int i = 0; i < V; i++)
	 {
		 for(int j = 0; j < V; j++)
		 {
			 //Changing minus to infinity 
			 if(matrix[i][j] == 1e9)
			 {
				 matrix[i][j] = -1;
			 }
		 }
	 }
 }
 int main() {

	int V = 4;
	std::vector<std::vector<int>> matrix(V, std::vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			std::cout << cell << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}