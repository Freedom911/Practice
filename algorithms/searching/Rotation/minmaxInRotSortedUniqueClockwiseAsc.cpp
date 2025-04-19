/**
 *
 * Given A sorted reverse array in clockwise  contsaining unique Elements
 *
 * arr - 1 2 3 4 5
 * rot - 4 5 1 2 3
 *
 * Find Min Element.
 *
 * Solution - 
 * 1) Do Linear Search  Time Comlpexity O(n),Space O(1)
 * 2) Min Heap - Time Complexity O(logn) for Build Heap,Space O(n)
 * 3) Using BInary Search
 * For Binary Search we require two things
 * a) Answer Selection
 * b) Movement
 *
 * a) Answer Selection - The Minimum Element will be having both sides greater
 *
 * So arr[mid] < arr[prev] and arr[mid] < arr[next]
 *
 * prev = mid - 1 and next = mid + 1. To Avoid Going out of Bound we 
 *
 * set next = (mid + 1) % N and for prev we do ((mid + N) - 1) % N plus N to avoid 
 * becoming negative we just add N itself. for normal index it will end at the same place
 *
 * b) Movement Related - For Movement we say  the array always gets divided into two halves
 * 1st half will always unosrted and other will be sorted. If we observe the answer lies alays in the
 * half which is unsorted
 * 
 * So to check if left side is sorted we do
 * arr[0] <= arr[mid] equal to because when having next and previous element same we have two elements 
 * only in that case mid and 0 will be same so we consider 1 element as sorted
 *
 * Similarly For Max Element.The max element will have both side greater
 *
 * for anti clockwise or reverse sorting the movement signs are reverrsed
 *
 *
 *
 */
#include <iostream>
#include <vector>

//the Function Retrusn the Minimum Element
int MinValue(std::vector<int> &arr)
{
    //Check Conditinos
   if(arr.size() == 0)
   {
       return -1;
   }

   else if(arr.size() == 1)
   {
       return arr[0];
   }
   
   int size = arr.size();
    
   //Check if aray already sorted
   if(arr[0] <= arr[size-1])
   {
       return arr[0];
   }

   int low = 0;
   int mid = 0;
   int high = size - 1;

   while(low <= high)
   {
     mid = low + (high - low)/2;
     
     //Check for Answer
     int prev = (mid + size - 1) % size;
     int next = (mid + 1) % size;

     //we Found the Answer
     if(arr[prev] >= arr[mid] && arr[next] >= arr[mid])
     {
        return arr[mid];
     }
     //adding Additional Condition to Check if both side are already sorted
     else if(arr[0] <= arr[mid] && arr[mid] <= arr[size-1])//left part is sorted so move right
     {
        return arr[0];
     }

     //Movement
     else if(arr[0] <= arr[mid])//left part is sorted so move right
     {
         low = mid + 1;
     }
     else//right part is sorted
     {
         high = mid - 1;
     }
   }

   return -1;
}


//the Function Retrusn the Minimum Element
int MaxValue(std::vector<int> &arr)
{
    //Check Conditinos
   if(arr.size() == 0)
   {
       return -1;
   }

   else if(arr.size() == 1)
   {
       return arr[0];
   }
   
   int size = arr.size();
    
   //Check if aray already sorted
   if(arr[0] <= arr[size-1])
   {
       return arr[size-1];
   }

   int low = 0;
   int mid = 0;
   int high = size - 1;

   while(low <= high)
   {
     mid = low + (high - low)/2;
     
     //Check for Answer
     int prev = (mid + size - 1) % size;
     int next = (mid + 1) % size;

     //we Found the Answer
     if(arr[prev] <= arr[mid] && arr[next] <= arr[mid])
     {
        return arr[mid];
     }
     //adding Additional Condition to Check if both side are already sorted
     else if(arr[0] <= arr[mid] && arr[mid] <= arr[size-1])//left part is sorted so move right
     {
        return arr[0];
     }

     //Movement
     else if(arr[0] <= arr[mid])//left part is sorted so move right
     {
         low = mid + 1;
     }
     else//right part is sorted
     {
         high = mid - 1;
     }
   }

   return -1;
}

int main()
{
    std::vector<int> v{3,4,5,1,2};
    std::cout << "\n Min Element = " << MinValue(v) << "\n";
    std::cout << "\n Max Element = " << MaxValue(v) << "\n";
    return 0;
}
