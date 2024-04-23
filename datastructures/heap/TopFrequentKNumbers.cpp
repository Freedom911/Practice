//Find Top K Frequent Number
//arr [] 1,1,1,2,2,3,3,3,3,3
//1 is appearing 3 times ,2 2 times and 3 5 times
//Given K is 2
//So 1 and 3 are appearing most times
//We can use map to store the number of times the element are appearning
//key will be number and value would be how many times they are coming
// then we push in vector of pair with first element as frequency and second
//as element. We sort based on that and pick the top K elements. Time compleixty O(nlogn)
//or we can use and store map key value in heap of pair with first element as frequency
//second as value
//We create min heap to eliminiate minimum values

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using IntPair = std::pair<int,int>;

template<typename T>
std::ostream & operator << (std::ostream &os ,const std::vector<T> &arr)
{
	os << "[";
	
	for(int i = 0; i < arr.size(); i++)
	{
		os << arr[i];
		
		if(i+1 != arr.size())
		{
			os << ",";
		}
	}
	os << "]";
	return os;
}

void FindTopKFrequentUnOptimized(const std::vector<int> &arr,const int &K)
{
	std::unordered_map<int,int> mapper;
	for (auto &elem:arr)
	{
		mapper[elem]++;
	}
	
	std::vector<std::pair<int,int>> ans;
	for(std::unordered_map<int,int>::iterator iter = mapper.begin(); iter != mapper.end(); iter++)
	{
		ans.push_back(std::make_pair(iter->second,iter->first));
	}
	
	std::sort(ans.begin(),ans.end(),std::greater<std::pair<int,int>>());
	
	std::cout << "\n Top = " << K << " Frequent Numbers are \n ";
	for(int i = 0; i < K; i++)
	{
		if (i >= K)
		{
			break;
		}
		std::cout << ans[i].second << " with Frequency of " << ans[i].first << "\n";
	}
}

void FindTopKFrequentOptimized(const std::vector<int> &arr,const int &K)
{
	std::unordered_map<int,int> mapper;
	for (auto &elem:arr)
	{
		mapper[elem]++;
	}
	
	std::priority_queue<IntPair,std::vector<IntPair>,std::greater<IntPair>> pr;
	
	for(std::unordered_map<int,int>::iterator iter = mapper.begin(); iter != mapper.end(); iter++)
	{
		pr.push(std::make_pair(iter->second,iter->first));
		
		if(pr.size() > K)
		{
			pr.pop();
		}
	}
	
	std::cout << "\n Top = " << K << " Frequent Numbers are \n";
	while(pr.empty() == false)
	{
		std::cout << pr.top().second << " with Frequency of " << pr.top().first << "\n";
		pr.pop();
	}
}

//Just use max heap to element elements with most frequency
void FindBottomKFrequentOptimized(const std::vector<int> &arr,const int &K)
{
	std::unordered_map<int,int> mapper;
	for (auto &elem:arr)
	{
		mapper[elem]++;
	}
	
	std::priority_queue<IntPair> pr;
	
	for(std::unordered_map<int,int>::iterator iter = mapper.begin(); iter != mapper.end(); iter++)
	{
		pr.push(std::make_pair(iter->second,iter->first));
		
		if(pr.size() > K)
		{
			pr.pop();
		}
	}
	
	std::cout << "\n Least = " << K << " Frequent Numbers are \n";
	while(pr.empty() == false)
	{
		std::cout << pr.top().second << " with Frequency of " << pr.top().first << "\n";
		pr.pop();
	}
}

int main()
{
	std::vector<int> arr {1,1,1,2,2,3,3,3,3,3};
	std::cout << "\n Array = " << arr << "\n";
	FindTopKFrequentUnOptimized(arr,2);
	FindTopKFrequentOptimized(arr,2);
	FindBottomKFrequentOptimized(arr,2);

}