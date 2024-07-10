//Print Nth Digit Numbers given N such that the numbers are monotonically increasing
//eq N = 2 ->12,13,14,15,16,17,18,19,23,24,25,26,27,28,29,34,35,36,37,38,39,45
//46,47,48,49...
//for N = 1 -> 1,2,3,4,5,6,7,8,9
//we have 1-9 choices
//we store intermediate result in a vector eq vector<int> inter;
//inter->[1,2] now to get the result we will
//Time complexity = No of nodes * work done by one nodes
//O(9^n) nodes
//work done O(N)
//O(N*9^N)
#include <iostream>
#include <vector>

void PrintIntermediateVector(const std::vector<int> &v)
{
	int place = 1;
	int sum = 0;
	for(int i = v.size() - 1; i >= 0; --i)
	{
		sum += v[i] * place;
		place = place * 10;
	}
	std::cout << sum << ",";
}

void GenerateNDigit(int N,std::vector<int> &intermediate)
{
	//Base condition
	if(N == 0)
	{
		PrintIntermediateVector(intermediate);
		return;
	}
	
	//choices
	for(int i = 1; i <= 9; i++)
	{
		//Valid conditions
		if(intermediate.size() == 0 || i > intermediate.back())
		{
			intermediate.push_back(i);
			GenerateNDigit(N-1,intermediate);
			//Backtrack
			intermediate.pop_back();
		}
	}
}

int main(int argc, char **argv)
{
	std::string str = argv[1];
	std::cout << "\n Generatng = " << str << " Digit Number in monotonically increasing manner = ";
	std::vector<int>intermediate;
	int N = std::stoi(str);
	GenerateNDigit(N,intermediate);
	
}