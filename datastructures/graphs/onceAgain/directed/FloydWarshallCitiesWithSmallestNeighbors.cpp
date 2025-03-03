/**
  https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/
  
  Problem Statement - Find the City With the Smallest Number of Neighbours at a Threshold Distance: G-43
  
  Problem Statement: There are n cities numbered from 0 to n-1. Given the array edges 
  where edges[i] = [fromi, toi,weighti]  represents a bidirectional and 
  weighted edge between cities fromi and toi, and given the 
  integer distance Threshold. You need to find out a city with the 
  smallest number of cities that are reachable through some path and 
  whose distance is at most Threshold Distance, If there are multiple such 
  cities, our answer will be the city with the greatest number.
  Note: that the distance of a path, connecting cities i and j are equal
  to the sum of the edges' weights along that path.
  
  Example 1:
  Input Format: 
  N=4, M=4, 
  edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], 
  distanceThreshold = 4
  
  Result: 3
  Explanation: 
  The adjacent cities for each city at a distanceThreshold are =
  City 0 →[City 1, City 2]
  City 1 →[City 0, City 2, City 3]
  City 2 →[City 0, City 1, City 3]
  City 3 →[City 1, City 2]
	Here, City 0 and City 3 have a minimum number of cities 
	i.e. 2 within distanceThreshold. So, the result will be the 
	city with the largest number. So, the answer is City 3.
	
 Solution - 
 This is simply solved by Floyd Warshall.
 So basically we calcualte the matrix
 then we iterate the matrix and cacluate cities which are less than threshold
*/

#include <iostream>
#include <vector>


int findCity(int N,int M,std::vector<std::vector<int>> &edges,int &threshold)
{
	//WE have to form adj matrix
	std::vector<std::vector<int>>matrix(N,std::vector<int>(N,1e9));
	for(auto it: edges)
	{
		int u = it[0];
		int v = it[1];
		int w = it[2];
		matrix[u][v] = w;
		matrix[v][u] = w;	
	}
	
	//Initialize Diagnoal elements with 0
	for(int i = 0; i < matrix.size(); i++)
	{
		matrix[i][i] = 0;
	}
	
	//Run Floyd Warshall
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[0].size(); j++)
			{
				matrix[i][j] = std::min(matrix[i][j],matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
	//NOw Iterate for every city
	int maxNeighbors = N; //at max these many values initially
	int cityResult = -1;
	for(int i = 0; i < matrix.size(); i++)
		{
			int cntMaxNeighbors = 0;
			maxNeighbors = N;
			for(int j = 0; j < matrix[0].size(); j++)
			{
				std::cout << matrix[i][j] << ",";
				if(matrix[i][j] <= threshold)
				{
					cntMaxNeighbors++;
				}
			
			}
			std::cout << "\n";
			if(cntMaxNeighbors) //less city found
			{
				maxNeighbors = cntMaxNeighbors;
				cityResult = i; 
			}				
		}
		std::cout << "\n";
		return cityResult;
}

int main() {

	int n = 3;
	int m = 2;
	std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}};//, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 2	;
	
	

	
	int cityNo = findCity(n, m, edges, distanceThreshold);
	std::cout << "The answer is node: " << cityNo << std::endl;

	return 0;
}