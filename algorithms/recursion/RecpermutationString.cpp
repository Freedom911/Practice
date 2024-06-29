//Find Permutation of strings using recursion
//here the number of choices will depend on the string sizee
//as for 1st position we will have n choices
//also total nodes would be n!
//on 1st level 3 then on second 3 *2 and on third 3 * 2 * 1
//explanation found in 29062024 copy number

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

template<typename T>
std::ostream & operator <<(std::ostream &out,const std::vector<T> &v)
{
	out << "[";
    size_t sizeOfArray = v.size();
	for (size_t i = 0; i < sizeOfArray; i++)
	{
		out << v[i];
		if( i + 1 != sizeOfArray)
		{
			out << ",";
		}
	}
	
	out << "]";
}


//Hypothesis
void Permute(std::string inp,std::string op,std::vector <std::string> &res)
{
	//Base condition
	//we get answers on leave node
	if(inp.empty())
	{
		res.push_back(op);
		return;
	}
	
	//locally defined as we only want to avoid duplicates on same level only 
	//and not on different level as this will stop exploration which we dont want
	//we only want to avoid duplicate exploration on same level
	std::unordered_set<char> us;
	
	//Induction Step or choice step
	//number of choices would be equal ot input size
	size_t choices = inp.size();
	
	for(size_t i = 0; i < choices; i++)
	{
		//Now we have to limit irrelevelant branches
		//if we have duplicates in input string then we get same branch for same characters
		//so we use set to avoid exploring again
		if(us.find(inp[i]) == us.end())
		{
			//Means Branch not explored
			us.insert(inp[i]);
			
			std::string newop = op + inp[i];
			std::string newinp = inp;
			//erase ith element
			newinp.erase(i,1);
			Permute(newinp,newop,res);
		}
		
	}
	
	return;
	
}

std::vector<std::string> findPermutations(std::string inp)
{
	std::vector<std::string> res;
	Permute(inp,"",res);
	return res;
}

int main()
{
	std::string inp = "abc";
	std::cout << "Permutation of Strings = \"" << inp << "\" are = " << findPermutations(inp) << ",";
	
}
	