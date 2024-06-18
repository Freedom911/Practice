#include <iostream>
#include <vector>

template<typename T>
std::ostream &operator << (std::ostream &out,const std::vector<T> &v)
{
	out << "[";
	for(int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] ;
		
		if(i+1 != v.size())
		{
			out << ",";
		}
	}
	out << "]";
	return out;
}

void Merge(std::vector<int> &arr, int low, int middle, int high)
{
	std::vector<int> l,r;
	for(int i = low; i <= middle; i++)
	{
		l.push_back(arr[i]);
	}
	for(int j = middle + 1; j <= high; j++)
	{
		r.push_back(arr[j]);
	}
	//std::copy(arr.begin() + low,arr.begin() + middle,l.begin());
	//std::copy(arr.begin() + middle+1,arr.begin() + high,r.begin());
	//return;
	
	int i = 0,j = 0;
	while( i < l.size() && j < r.size())
	{
		if(r[j] > l [i])
		{
			arr[low++] = l[i++];	
		}
		else
		{
			arr[low++] = r[j++];
		}
		
	}
	
	while(i < l.size())
	{
		arr[low++] = l[i++];
	}
	
	while(j < r.size())
	{
		arr[low++] = r[j++];
	}
	
}

//Hypothesis
void MergeSort(std::vector<int> &arr,int low,int high)
{
  //Base condition that is only one element is present
  if(low >= high)
  {
	  return;
  }
  
  //Induction Step reduce arr size
  //The recursion splits into two array
  int middle = low + (high - low)/2;
  MergeSort(arr,low,middle);
  MergeSort(arr,middle+1,high);
  
  //Now Merge the array from low to middle and middle + 1 to high
  Merge(arr,low,middle,high);
}


int main()
{
	std::vector<int> v{10,5,19,20};
	std::cout << "\n Before Sorting Vector is = " << v << "\n";
	
	MergeSort(v,0,v.size() - 1);
	
	std::cout << "\n After Sorting Vector is = " << v << "\n";
}