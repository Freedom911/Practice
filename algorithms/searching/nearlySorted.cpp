
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
    int prev = q - 1;
    int next = q + 1;
    if(arr[q] == elementToFind)
      return q;

    if(prev >= 0 && arr[prev] == elementToFind)
      return prev;
    if(next < arr.size() && arr[next] == elementToFind)
      return next;

    if(elementToFind > arr[q])
      p = q+2;
    else
      r = q-2;

  }
  return -1;
}

int main()
{
  std::vector<int> arr {5,10,30,20,40};
  std::cout << findElement(arr,40);
}
