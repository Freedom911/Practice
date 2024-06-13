//Recursion Program to get Mean
//we use IBH method
#include <iostream>
#include <vector>


float GetMean(std::vector<int> arr,const int &totalElem)
{
	//Base condition if there are no elements we return sum as 0
	if(arr.size() == 0)
	{
		return 0;
	}
	
	//Induction Step
	int lastElem = arr.back();
	arr.pop_back();
	//Get Mean gets mean of  n-1 term and we add nth term mean to get ans
	return ((float)(lastElem)/(float)totalElem) + GetMean(arr,totalElem);
}

int main()
{
	std::cout << GetMean({1,2,3,4,5,6,7,8,9,10},10) << "\n";
}