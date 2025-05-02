/**
 *
 * FindingKth Number in Sorted Array.
 * Sol1 - 
 * Using MErge OPeration 
 * Time COmplexity O(n1 + n2)
 * Space Complexity O(n1+n2)
 *
 *  Solution 2 - Using BInary Search
 * We will use the concept of finding Mean in 2 sorted array.
 * there the left portion was n1 + n2 + 1/2 here it is k thats it
 * the low and high limit will change
 * assume if K > arr2.size() then we need atleast K-arr2.size() from array 1 to complete the left half
 * low = max(0,K - arr2.size()) from array 1
 * high = min(K,arr1.size()) as We need to have K elements only. Means All K elements are from arr1
 * the answer will be found at max of l1,l2
 */



#include <iostream>
#include <vector>
#include <limits>


//Solution 3 - Using Binary Search
//This Function Finds Kth element using  Median concept of 2 sorted array  using Binary Search
float findKth(std::vector<int> &arr1,std::vector<int> &arr2,int K)
{
	//CHeck Conditions
	if(arr1.size() == 0 && arr2.size() == 0)
	{
		return -1;
	}
	
	int n1 = arr1.size(), n2 = arr2.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return findKth(arr2, arr1,K);
	
	int totalLength = n1 + n2;
	int leftPortionSize = K; //for generalizing for odd and even
	int low = std::max(0,K-n2);
	int high = std::min(K,n1);
	//int low = 0;
	//int high = n1;
	
	while(low <= high) //0 to all elements of arr 1
	{
		int mid1 = low + (high - low)/2; // elements in array 1 in left part
		int mid2 = leftPortionSize - mid1;
		
		//Check Valid
		//4 points
		//to handle edge cases
		int l1 = std::numeric_limits<int>::min();
		int l2 = std::numeric_limits<int>::min();
		int r1 = std::numeric_limits<int>::max();
		int r2 = std::numeric_limits<int>::max();
		
		if(mid1-1 >= 0)
		{
			l1 = arr1[mid1-1];
		}
	    if(mid1 <  n1)
		{
			r1 = arr1[mid1];
		}
		if(mid2-1 >= 0)
		{
			l2 = arr2[mid2-1];
		}
		if(mid2 <  n2)
		{
			r2 = arr2[mid2];
		}
		
		if (l1 <= r2 && l2 <= r1)
		{
			//answer Found
			return std::max(l1,l2);
		}
		
		else if (l1 > r2) //means array 1 ka jyda include karlie thats why max element is bigger
		{
			//reduce the elements taken from array 1 so we decrease the high 
			high = mid1 - 1;
		}
		else
		{
			low = mid1 + 1;//means that l2 is greater than r1 so we decrease the element from arr2 and increase from array1
		}
		
		
	}
	
	return 0;
}

int main()
{
  std::vector<int> a{11,12,13,14,15,16,17};
  std::vector<int> b{8,9,10};


  int K = 7;
  std::cout << "\n FInding  K = " << K << " IN 2 sorted array At position = " << findKth(a,b,K) << "\n";
  
  K = 2;
  std::cout << "\n FInding  K = " << K << " IN 2 sorted array At position = " << findKth(a,b,K) << "\n";
  
  
}
