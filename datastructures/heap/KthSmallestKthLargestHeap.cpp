#include <iostream>
#include <queue>
#include <vector>

//Given an array in which an element we want to find kth largest/kth smallest
//in case of smallest we use max heap as we will discard the top max elements
//because they wont be part of answer
//similary in case of finding largest we will use min heap as min elements would be
// on top and they wont be part of the answer

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

//Min Heap
int MinHeap(std::vector<int> &arr,const int &k)
{
	std::priority_queue<int,std::vector<int>,std::greater<int>>pr;
	for(int i = 0; i < arr.size(); i++)
	{
		pr.push(arr[i]);
		
		if(pr.size() > k)
		{
			pr.pop();
		}
	}
	
	return pr.top();
	
}

int MaxHeap(std::vector<int> &arr,const int &k)
{
	std::priority_queue<int>pr;
	for(int i = 0; i < arr.size(); i++)
	{
		pr.push(arr[i]);
		
		if(pr.size() > k)
		{
			pr.pop();
		}
	}
	
	return pr.top();
	
}

int main()
{
	int k = 3;
	std::vector<int> arr{6,5,3,2,8,10,7};
	std::cout << "\n Array \n";
	std::cout << arr;
	std::cout << "\n Smallest " << k << " th element is = " << MaxHeap(arr,k);
	std::cout << "\n Largest " << k << " th element is = " << MinHeap(arr,k);
	
}