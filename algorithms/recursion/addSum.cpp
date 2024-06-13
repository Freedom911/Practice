//Recursion Program to get sum
//we use IBH method
#include <iostream>
#include <vector>


int GetSum(std::vector<int> arr)
{
	//Base condition if there are no elements we return sum as 0
	if(arr.size() == 0)
	{
		return 0;
	}
	
	//Induction Step
	int lastElem = arr.back();
	arr.pop_back();
	//Get sum adds sum of n-1 term and we add nth term to get ans
	return lastElem + GetSum(arr);
}

int main()
{
	std::cout << GetSum({1,2,3,4,5,6,7,8,9,10}) << "\n";
}