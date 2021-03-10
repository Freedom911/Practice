#include <iostream>
#include <vector>

int findElement(std::vector<int> arr,int elementToFind)
{
  int p = 0;
  int r = arr.size() - 1;

  int q = -1;
  while(p <= r)
  {
    q = p + (r-p)/2;
    if(arr[q] == elementToFind)
      return q;

    if(elementToFind > arr[q])
      p = q+1;
    else
      r = q-1;

  }
  return -1;
}

int main()
{
  std::vector<int> arr {1,2,3,4,5,6};
  std::cout << findElement(arr,6);
}
