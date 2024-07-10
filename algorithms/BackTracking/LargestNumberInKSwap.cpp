//Given a string 1,5,7 without commas and K = 2. Find largest
//number we can get by swapping by at most K times. Here 1 with 7 we get 751 which is largest in 1 swap only. The question is similar to Generate all permuations. There we
//swapped unlimited number of times till we reach leaf node.
//Here number of swaps are limited and we can get answer at non leaf node

//Time complexity
//No of nodes * work done by one node
//No of NOdes if n = k we have n! nodes
//but since k is limiting the total nodes so at level 1 we have
//n nodes and level 2 we have n -1 
//we can write n -1 + 1 at 1st node
//or n - k + 1
//so total nodes = n to n-k+1
//we can write n,n-1,n-2,n-k+1,n-k,n-k-1,...1/(n-k)*(n-k-1)...
//we get n!/(n-k)! nodes
//work done by one node O(n2)
//so total complexity = O(n2 * n!/(n-k)!)


#include <iostream>
#include <string>
#include <algorithm>

//IBH
//Hypothesis
void PrintLargestNumber(std::string &inp,int startIndex,int swapsLeft,std::string &largest)
{
	//Base condition
	if(startIndex == inp.size() || swapsLeft <= 0)
	{	
		return;
	}
	
	//choices
	//here we are starting from startIndex + 1 to avoid wasting swap
	//from itself. eg 710 we wont swap 7 with 7 as it will reduce swaps left
	//int maxCharIndex = *std::max_element(inp.begin() + startIndex,inp.end());
	char maxChar = *std::max_element(inp.begin() + startIndex,inp.end()); //O(n)
	bool isExplored = false;
	for(int i = startIndex + 1; i < inp.size(); i++)//O(n)
	{
		//Valid Condition or pruning criteria
		//we will consider if the char is larger than startIndex
		//and also if it is the largest
		//eq 126 then we can 2 with 1 or 6 with 1 as both 2 and 6 are larger than 1
		//but we know that we cant get max if we replace with 2 as it is smaller than 6
		if(inp[i] > inp[startIndex] && inp[i] == maxChar)
		{
			isExplored = true;
			std::swap(inp[i],inp[startIndex]);
			
			if(inp.compare(largest) > 0)//means inp is gterater than largest O(n)
			{
				largest = inp;
			}
			PrintLargestNumber(inp,startIndex+1,swapsLeft-1,largest);
			
			//Backtrack
			std::swap(inp[i],inp[startIndex]);
		}
	}
	//Now in case the number at startIndex was largest then we will 
	//evaluate for startIndex+1
	//means we didn't do any swap
	//eq 712, then we check for startIndex+1 that is at 1 index
	//we will get 721
	if(isExplored == false)
	{
		PrintLargestNumber(inp,startIndex+1,swapsLeft,largest);
	}
}

int main(int argc,char **argv)
{
	std::string inp = argv[1];
	int k = 1;
	std::string largest = inp;
	std::cout << "\n Largest number in " << inp << " with " << k << " swaps = ";
	PrintLargestNumber(inp,0,k,largest);
	std::cout << largest << "\n";
}