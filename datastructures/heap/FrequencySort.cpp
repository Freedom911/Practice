//Given anarray 1,3,3,2,2,2,4,4,4,4,4
//Output 4,4,4,4,4,2,2,2,3,3,1
//Let us see if we create unordered map of number to frequency
//push to max heap based on frequency.
//then number with max frequency will be present at top
//we then pop 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

template<typename T>
std::ostream & operator << (std::ostream &os, const std::vector<T> &v)
{
	os << "[";
	for(int i = 0; i < v.size(); i++)
	{
		os << v[i];
		
		if(i + 1 != v.size())
		{
			os << ",";
		}
	}
	os << "]";
	return os;
}

void FrequencySort(std::vector<int> &input)
{
	std::priority_queue<std::pair<int,int>> pr;
	std::unordered_map<int,int>umap;
	
	for (auto &elem: input)
	{
		umap[elem]++;
		
	}
	
	for(auto it = umap.begin(); it != umap.end(); it++)
	{
		//std::cout << "\n HEREE = " << it->first << "," << it->second << "\n";
		pr.push(std::make_pair(it->second,it->first));
		
	}
	int j = 0;
	while(pr.empty() == false)
	{
		int times = pr.top().first;
		
		for(int i = 0; i < times; i++)
		{
			
			input[j++] = pr.top().second;
		}
		pr.pop();
	}
}

int main()
{
	std::vector<int>v{1,3,3,2,2,2,4,4,4,4,4};
	
	std::cout << "\n Before Sorting = " << v << "\n";
	
	FrequencySort(v);
	
	std::cout << "\n After Sorting = " << v << "\n";
	
	
}
