//Sorting in descending order
#include <iostream>
#include <vector>

std::ostream &operator << (std::ostream &out,const std::vector<int> &arr)
{
	out << "[";
	
	for(int i = 0; i < arr.size() ; i++)
	{
		out << arr[i];
		
		if(i+1 != arr.size())
		{
			out << ",";
		}
	}
	out << "]";
	return out;
}

//Hypothesis
void InsertInDesc(std::vector<int>& arr,const int &elem)
{
	//Base condition
	if(arr.size() == 0 || arr.back() >= elem)
	{
		arr.push_back(elem);
		return;
	}
	
	//Induction Step
	int lastElem = arr.back();
	arr.pop_back();
	
	InsertInDesc(arr,elem); //this will insert element at right place of array of size n -1
	//duty to insert back last element
	arr.push_back(lastElem);
}

//Hypothesis
void InsertInAsc(std::vector<int>& arr,const int &elem)
{
	//Base condition
	if(arr.size() == 0 || arr.back() <= elem)
	{
		arr.push_back(elem);
		return;
	}
	
	//Induction Step
	int lastElem = arr.back();
	arr.pop_back();
	
	InsertInAsc(arr,elem); //this will insert element at right place of array of size n -1
	//duty to insert back last element
	arr.push_back(lastElem);
}


//Hypothesis
void sortArr(std::vector<int> &arr,const int &desc)
{
	//Base condition
	if(arr.size() <= 0)
	{
		return;
	}
	
	//Induction Step
	int elem = arr.back();
	arr.pop_back();
	
	sortArr(arr,desc);//This will sort n -1 element
	if(desc == 1)
	{
		InsertInDesc(arr,elem);//then insert nth element at right place that it
	}
	else
	{
		InsertInAsc(arr,elem);
	}
}

int main(int argc, char **argv)
{
	std::vector<int> v,v1;

	//std::cout << argc << "\n";
	for(int i = 1 ; i < argc ; i++)
	{
		try
		{
		    v.push_back(std::stoi(argv[i]));
		}catch(std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}
	v1 = v;
	std::cout << "Sorting Array = " << v << " In Descending Order " << "\n";
	sortArr(v,1);
	std::cout << "Sorted Array = " << v << "\n";
	
	std::cout << "Sorting Array = " << v1 << " In Ascending Order " << "\n";
	sortArr(v1,0);
	std::cout << "Sorted Array = " << v1 << "\n";
	
}