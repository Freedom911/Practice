//Program For Binary Search Algorithm Recursively
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr,int start,int end,int item)
{
  if(start <= end)
  {
    //to avoid overflow
    int mid = start + (end - start)/2;

    if(arr[mid] == item)
      return mid + 1;

    else if(arr[mid] > item)
      return binarySearch(arr,start,mid - 1,item);

    else
      return binarySearch(arr,mid + 1,end,item);

  }

  return -1;
}

int main()
{
  std::vector<int> arr{2,3,4,7,9,13,20,29,30,31};


  int elem = 7;
  
  int pos = binarySearch(arr,0,arr.size() - 1,elem);

  if(pos != -1)
  std::cout << "\n Element = " << elem << " at position = " << pos << "\n";
  else
    std::cout << "\n ELEMENT = " << elem << " not found ";

}
