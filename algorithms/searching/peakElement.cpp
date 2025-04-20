/**
 *
 * https://takeuforward.org/data-structure/peak-element-in-array/
 *
 * Problem Statement: Given an array of length N. Peak element is 
 * defined as the element greater than both of its neighbors. 
 * Formally, if 'arr[i]' is the peak element, 
 * 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
 * Find the index(0-based) of a peak element in the array. 
 * If there are multiple peak numbers, return the index of any peak number.
 *
 * Example 1:
    Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1} 
    Result: 7
    Explanation: In this example, there is only 1 peak that is at index 7.

    Example 2:
    Input Format: arr[] = {1,2,1,3,5,6,4}
    Result: 1
    Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

    Example 3:
    Input Format: arr[] = {1, 2, 3, 4, 5}
    Result: 4
    Explanation: In this example, there is only 1 peak that is at the index 4.

    Example 4:
    Input Format: arr[] = {5, 4, 3, 2, 1}
    Result: 0
    Explanation: In this example, there is only 1 peak that is at the index 0.

 Solution 1 - Using Linear Search

 Solution 2 - We use Binary Search on Answer Ceoncept.
 it states that even if array is not sorted but has some increasing or decreasing property
 like monotonicaly increasing or decreasing then we can apply the ceoncept

 For Answer - We check if the array mid is greater than both of its neighbor
 For 1 and last elemeent there is an edge case
 if the 1st element is greater than 2nd then 1st element is peak
 for last element if last element is greater than second last then it is peak
 so we start with l = 1 and go till r = size-2.

 For Movement
 We check which side is more promising. if the left element is greater than mid then left 
 side seems more promising as it means we are going in the direction of peak if we had moved
 right instead then it means we are going to dip.
*/

#include <iostream>
#include <vector>

//This Function Returns the Peak Element in the provided array
int findPeakElement(std::vector<int> &arr)
{
    int size = arr.size();
   //Check Conditions
   if(size == 0)
   {
       return -1;
   }

   else if(size == 1)
   {
       return arr[0];
   }

   else if(arr[0] > arr[1])
   {
       return arr[0];
   }
   else if(arr[size-1] > arr[size-2])
   {
       return arr[size-1];
   }

   //Main Function
   int low = 1;//Not 0 as we already checked
   int high = size-2;//we already check ed size-1

   while(low <= high)
   {
       int mid = low + (high - low)/2;

       //For Answer
       if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid + 1])
       {
           return arr[mid];
       }
       //For Movement
       else if(arr[mid-1] > arr[mid]) //left side more promising it will lead to heavens i.e the peaks
       {
           high = mid - 1;
       }
       else//for All cases . If we are at dip then we can move to either side. we reach peak
       {
           low = mid + 1;
       }
   }
   return -1;
}

int main()
{
  std::vector<int> v{1,2,1,3,5,6,4};

  std::cout << "\n PEAK ELEMENT = " << findPeakElement(v) << "\n";
}
