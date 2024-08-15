//Generate Permuation of strings using backtracking
//Time COmplexity Total No of nodes * Work done in one node.
//n! is total nodes and work done in one node O(n)
//total complexity O(n*n!)
#include <iostream>
#include <string>
#include <unordered_set>


void PermuteBackTrack(std::string &inp,int startIndex)
{
	if(startIndex == inp.size()) // base condition
	{
		std::cout << inp << ",";
		return;
	}
	
	//Choices
	std::unordered_set<char>us;
	for(int i = startIndex; i < inp.size(); i++)
	{
		if(us.find(inp[i]) == us.end()) //means not explored
		{
			us.insert(inp[i]);
			
			//do alti palti
			std::swap(inp[i],inp[startIndex]);
			PermuteBackTrack(inp,startIndex+1);
			//Backtrack
			std::swap(inp[i],inp[startIndex]);
		}
		
	}
}

int main(int argc,char **argv)
{
	std::string str = argv[1];
	std::cout << "\n Permutation of " << str << " = " ;
	PermuteBackTrack(str,0);
}
