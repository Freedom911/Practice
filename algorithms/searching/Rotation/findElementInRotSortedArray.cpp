/**
 * Task is to find the element in reverese sorted non unique array
 * So we use preivous knowledge. Find the min index and then we apply binary 
 * search in two halves
 *
 */
#include <iostream>
#include <vector>

//the Function Retrusn the Minimum Index
int MinIndex(std::vector<int> &arr)
{
    //Check Conditinos
   if(arr.size() == 0)
   {
       return -1;
   }

   else if(arr.size() == 1)
   {
       return 0;
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
        return mid;
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

//Do a simple Binary search to find the element
int BS(std::vector<int> &v,int low,int high,int elem)
{
    if(v[low] == elem)
    {
        return low;
    }
    if (v[high] == elem)
    {
        return high;
    }
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(v[mid] == elem)
        {
           return mid;
        }

        else if(v[mid] > elem)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int findElement(std::vector<int> &v,int elem)
{
    int minIndex = MinIndex(v);
    std::cout << "\n Min Index at = " << minIndex << "\n";
    if(minIndex == -1)
    {
        return -1;
    }
    else if (minIndex == 0)
    {
        return BS(v,0,v.size() - 1,elem);
    }
    //else we have two halves
    if(elem >= v[0] && elem <= v[minIndex-1]) //lies in this half
    {
        std::cout << "\n HERE \n";
       return BS(v,0,minIndex-1,elem);
    }
    else 
        return BS(v,minIndex,v.size()-1,elem);

}


int main()
{
    std::vector<int> v{1,5};
    std::cout << "\n Element 9 Found at = " << findElement(v,9) << "\n";
    return 0;
}
