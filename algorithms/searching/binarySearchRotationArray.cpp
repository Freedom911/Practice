//finding element in a rotation array
#include <iostream>
#include <vector>

int findElement(std::vector<int>arr,int l,int r,int item)
{

  if(l > r)
    return -1;

  int mid = l + (r -l)/2;

  if(arr[mid] == item)
    return mid + 1;

  else
  {
    if(item >= arr[l] && item < arr[mid])
      return findElement(arr,l,mid-1,item);

    else
      return findElement(arr,mid+1,r,item);
  }

}

int main()
{
  std::vector<int> elem {5,6,7,1,2,3,4};
  
  std::cout << findElement(elem,0,elem.size() - 1,0);
}
