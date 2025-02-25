/**
 *
 https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/
 
 Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.

Note: Many orders may be possible for a particular test case, thus you may return any valid order.

Eg
Example 1:
Input: N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output: b d a c
Explanation: 
We will analyze every consecutive pair to find out the order of the characters.
The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

Solution ----
So The problem is using ordering concept thus topo sort lagega. for topo sort we need adj list having DAG
So we will analyze 0 and 1 in dict. and compare one by one character like baa and abcd m dono ke first letter
compare since b comes before than a so b->a aisa banega. we keep copmarting string oair wise to form the whole
graph then we simply apply topo
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::string findOrder(std::string dict[],int N,int K)
{
	std::string res;
	std::vector<int> adj[K];
	//1st step is to form adj list
	for(int i = 0; i < N - 1; i++)
	{
		//pick the min one for next loop
		int loopTimes = std::min(dict[i].size(),dict[i+1].size());
		
		for(int j = 0; j < loopTimes; j++)
		{
			//b
			//c
			// we say b->c. so adj[b] = c
			if(dict[i][j] != dict[i+1][j])
			{
				adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
				break;
				
			}
		}
		
	}
	
	//Now apply topop sort . we use kahnchacha
	std::vector<int> Indegree(K);
	std::queue<int> q; 
	
	for(int i = 0; i < K; i++)
	{
		for(auto it : adj[i])
		{
			Indegree[it]++;
		}
	}
	
	for(int i = 0; i < K; i++)
	{
		if(Indegree[i] == 0)
		{
			q.push(i);
			res.push_back(char(i + 'a'));
		}
	}
	
	while(q.empty() == false)
	{
		int node = q.front();
		q.pop();
		
		for(auto it : adj[node])
		{
			Indegree[it]--;
			if(Indegree[it] == 0)
			{
				q.push(it);
				res.push_back(char(it + 'a'));
			}
		}
		
		
	}
	return res;
}

int main() {

	int N = 5, K = 4;
	std::string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

	std::string ans = findOrder(dict, N, K);

	for (auto ch : ans)
		std::cout << ch << ' ';
	std::cout << std::endl;

	return 0;
}

