#include <iostream>
#include <queue>
#include <vector>

//Given an array in which an element can be  at i+k or i-k position of sorted
//array. Here we can sort the whole array in o(nlogn) using merge sort
//But we will use heap to sort. We use min heap so that we can find the minimum 
//element in k buckets

template<typename T>
std::ostream & operator <<(std::ostream &ofs,const std::vector<T> &v)
{
	ofs << "[";
	for (int i = 0; i < v.size(); i++)
	{
		ofs << v[i];
		
		if( i + 1 != v.size())
		{
			ofs << ",";
		}
	}
	ofs << "]";
	
	return ofs;
}

void SortNearlySorted(std::vector<int> &arr,const int &k)
{
	std::priority_queue<int,std::vector<int>,std::greater<int>>pr;
	int j = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		pr.push(arr[i]);
		
		if(pr.size() > k)
		{
			arr[j] = pr.top();
			j++;
			pr.pop();
		}
	}
	
	while(pr.size() > 0)
	{	
		arr[j] = pr.top();
		j++;
		pr.pop();
	}

	
}

int main()
{
	int k = 3;
	std::vector<int> arr{6,5,3,2,8,10,7};
	std::cout << "\n Before Sorting = ";
	std::cout << arr;
	SortNearlySorted(arr,k);
	
	std::cout << "\n After Sorting = ";
	std::cout << arr << std::endl;
}