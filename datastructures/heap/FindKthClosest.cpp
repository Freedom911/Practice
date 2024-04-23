//Find K Closest Number to x in an array
//Same logic for K Farthest Number
//arr [] 5,6,7,8,9 K = 3 and X = 7
// so 3 closest element to X is 6,7,8
//We can create a new array with difference.
//the array contains pair with first value as difference
//second as actual element. we sort in o(nlogn) and pick k element
//Or we use Heap to insert differece and we create max heap to eliminate
//largest difference number and finally printf
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//O(nlogn)
void FindKthClosestUnOptimized(const std::vector<int> &arr, const int &K,const int &X)
{
	std::vector<std::pair<int,int>>ans;
	for(auto &elem:arr)
	{
		ans.push_back(std::make_pair(std::abs(X-elem),elem));
	}
	
	std::sort(ans.begin(),ans.end());
	std::cout << "\n " << K << "th closest number to " << X << " are ";
	for(int i = 0; i < K; i++)
	{
		if(i >= arr.size())
		{
			break;
		}
		std::cout << ans[i].second << ",";
	}
}
//O(nlogk)
void FindKthClosestOptimized(const std::vector<int> &arr, const int &K,const int &X)
{
	std::priority_queue<std::pair<int,int>>pr;
	for(auto &elem:arr)
	{
		pr.push(std::make_pair(std::abs(X-elem),elem));
		
		if(pr.size() > K)
		{
			pr.pop();
		}
	}
	std::cout << "\n " << K << "th closest number to " << X << " are ";
	while(pr.empty() == false)
	{
		std::cout << pr.top().second << ",";
		pr.pop();
	}
}


void FindKthFarthestOptimized(const std::vector<int> &arr, const int &K,const int &X)
{
	//We create min heap
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pr;
	for(auto &elem:arr)
	{
		pr.push(std::make_pair(std::abs(X-elem),elem));
		
		if(pr.size() > K)
		{
			pr.pop();
		}
	}
	std::cout << "\n " << K << "th Farthest number to " << X << " are ";
	while(pr.empty() == false)
	{
		std::cout << pr.top().second << ",";
		pr.pop();
	}
}

int main()
{
	std::vector<int> arr {5,6,7,8,9};
	FindKthClosestUnOptimized(arr,3,7);
	FindKthClosestOptimized(arr,3,7);
	FindKthFarthestOptimized(arr,3,7);
}