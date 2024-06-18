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


int Partition(std::vector<int> &v,int l,int h)
{
	int partition = v[h];
	int i = l - 1;
	for(int j = l ; j <= h-1; j++)
	{
		if(v[j] < partition)
		{
			i++;
			std::swap(v[i],v[j]);
		}
	}
	i++;
	std::swap(v[i],v[h]);
	
	return i;
}

//Solving Quick Sort using IBH.
//Here we reduce input by fitting partition element at right place
//and removing from further operation
//Hypothesis
void QuickSort(std::vector<int> &v,int l,int h)
{
	//Base condition that is only one element is there
	if(l>=h)
	{
		return;
	}
	
	//Induction step
	int pi = Partition(v,l,h);
	
	QuickSort(v,l,pi-1);
	QuickSort(v,pi+1,h);
}

int main()
{
	std::vector<int> v{10,7,8,9,1,5};
	std::cout << "\n Before Sorting Vector is = " << v << "\n";
	
	QuickSort(v,0,v.size() - 1);
	
	std::cout << "\n After Sorting Vector is = " << v << "\n";
}