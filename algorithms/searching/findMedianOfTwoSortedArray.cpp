//Finding Median Of two odd length same sized array 
//without using o(n) space complexity
//Three Solutions 
//SOlution 1 - Using Array additionally and return the element n/2
//Solution 2 - Using Pseudo Array. Just Maintain The COunters
//Solution 3 - It is a very good solution and is based on Binary Search and it is like Binary Search on answer
//So Inituion
//Basically we have two sorted array and we know the median position. We Try to find a partition for array 1 
//such that valid array elements of 1 will be there on left
//eg arr1 = [1,3,5] and arr2 = [2,4,6]
// now we know the median position will be at n/2 -1 and n/2 . such that
//the element on left side will have 3 and on right will have 3
// Let X = 0 which means we take 0 elements from array 1. so for left part we need 3 more elements
//we pick from arr2 so we get
//[2,4,6] | [1,3,5]
// This is not a valid array as it is not sorted.
//To Check Validity it is simple we compare the max on left with min on right. max on left shall be greater than min on right
//moving on we then Take X = 1
//we get [1][2,4] | [3,5][6] Again this is not a valid array
//Then Take X = 2
//[1,3][2] | [5],[4,6]
//Rearranging - [1,2,3] | [4,5,6] this is valid
// so we stop as there will be only one valid partition
//This is much like binary search on answer . we define the range we take. we pick the smaller array
//to reduce number of operations. range will be 0 to all elements of shorter array
//NOw BInary Search needs two things
//1.For Answer 
//we Say we got the answer if  max on left side is less than min on right side
//we maintain 4 pointers l1 = arr1 ka max,l2 = arr2 ka max,r1 = arr1 ka right side ka min,
//r2 arr2 ka right side ka min
//X will be mid1  = (l + r)/2 and elements left from array 2 = total elements in left side partioion - mid1
//l1 = arr1[mid1-1],r1 = arr1[mid1],l2 = arr2[mid2-1],r2 = arr2[mid2]
//2. For MOvement
//if l1 > r2 means hamne arr1 ke jyda elements utha lie so hame kam karna padega there fore we reduce X by reducing 
//high to mid -1 else
// matlab l2 >r1 means arr2 se jyda utha so hame arr2 ka reduce karna padedga
//For Odd case we cant have symmetery of equal parts
//arr1 = [1,3,4],arr2 = [2,6]
//we have two options greater left portion or greater right
// so left portion size (n1 + n2)/2 = 2 then add 1 we get 3
//to generalize for odd and even we add 1
//(n1 + n2 + 1)/2 
//(2 + 2 + 1)/2 we get 2
//for odd
//3 + 2 + 1/2 = 3 which is right
//thats it we solved in logn



#include <iostream>
#include <vector>
#include <limits>

//Solution 2 -  Using Pseudo Array
float getMedian(std::vector<int> a,std::vector<int> b)
{
  int p = 0,q = 0,total = 0;
  float median = 0.f;

  int medianPosition  = (a.size() + b.size())/2;

  while(p < a.size() && q < b.size())
  {
    total++;
    int element;

    if(a[p] < b[q])
    {
      element = a[p];
      p++;
    }
    else
    {
      element = b[q];
      q++;
    }


    if(total == medianPosition)
    {
      median += element;
    }
    else if (total == medianPosition + 1)
    {
      median += element;
      break;
    }

  }
  
  
  while(p < a.size())
  {
    total++;
    int element;

  
    {
      element = a[p];
      p++;
    }
 

    if(total == medianPosition)
    {
      median += element;
    }
    else if (total == medianPosition + 1)
    {
      median += element;
      break;
    }

  }
  
  while( q < b.size())
  {
    total++;
    int element;


    {
      element = b[q];
      q++;
    }


    if(total == medianPosition)
    {
      median += element;
    }
    else if (total == medianPosition + 1)
    {
      median += element;
      break;
    }

  }
  

  if(total != medianPosition + 1)
  {
    if(q < b.size())
      median += b[q];

    else if(p < a.size())
      median += a[p];
  }

  return median/2;


}

//Solution 3 - Using Binary Search
//This Function Finds Median of 2 sorted array  using Binary Search
float getMedianBS(std::vector<int> &arr1,std::vector<int> &arr2)
{
	//CHeck Conditions
	if(arr1.size() == 0 && arr2.size() == 0)
	{
		return -1;
	}
	
	int n1 = arr1.size(), n2 = arr2.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return getMedianBS(arr2, arr1);
	
	int totalLength = n1 + n2;
	int leftPortionSize = (totalLength + 1) /2; //for generalizing for odd and even
	int low = 0;
	int high = n1;
	
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
			//in Case of even return middle 
			if(totalLength % 2 == 1)
			{
				//return the middle element that is the maxumn of both
				//eg [1,2,3] and [4,5] - we have [1,2,3,4,5] - so for left part we pick the max when that is 3
				return std::max(l1,l2);
			}
			else
			{
				//eg [1,2,3][4,5,6] we pick max from left and min from right i.e 3 and 4
				 return ((float)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
			}
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
  std::vector<int> a{1,6,8,10,12};
  std::vector<int> b{2,3,4,9,11};


  std::cout << "\n Median Of two array = " << getMedian(a,b) << "\n";
  std::cout << "\n Median Of two array USing BS = " << getMedianBS(a,b) << "\n";
  
  std::vector<int> a1{1};
  std::vector<int> b1{3};
  
  std::cout << "\n Median Of two array = " << getMedian(a1,b1) << "\n";
  std::cout << "\n Median Of two array USing BS = " << getMedianBS(a1,b1) << "\n";
  
  std::vector<int> a2{1,2};
  std::vector<int> b2{3,4,5,6,7,8};
  
  std::cout << "\n Median Of two array = " << getMedian(a2,b2) << "\n";
  std::cout << "\n Median Of two array USing BS = " << getMedianBS(a2,b2) << "\n";

}
