/**
 *
 * Extension To min max unique
 *
 * here the Algo will fail when we have duplicate numbers. Specifucally when we will not be
 * able to decide where to move
 *
 * eg 3 3 3 3 1 3 3
 *
 * mid = 3rd index now to know where to move we compare 0 and mid and mid and last
 * if we compare mid and last 3,1,3,3 we see this part is sorted but it is not.
 * so we try to move to left but we wont find there
 *
 * So our algo fails
 * we do a slight modification . when we see arr[mid] == arr[prev] == arr[next] and mid 
 * is not in the answer so prev and next would also be not. so we reduce the range
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

     if (arr[low] == arr[mid] && arr[mid] == arr[high])
     {
         low+=1;
         high-=1;
         continue;
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

//the Function Retrusn the Max Element
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

     if (arr[low] == arr[mid] && arr[mid] == arr[high])
     {
         low+=1;
         high-=1;
         continue;
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
    std::vector<int> v{3,3,3,3,1,3,3};
    std::cout << "\n Min Element = " << MinValue(v) << "\n";
    std::cout << "\n Max Element = " << MaxValue(v) << "\n";
    return 0;
}
