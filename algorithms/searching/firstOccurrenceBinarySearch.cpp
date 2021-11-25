#include <iostream>
#include <vector>

int findIndex(std::vector<int> arr,int elementToFind)
{
  int p = 0;
  int r = arr.size() - 1;

  int q = -1;
  while(p <= r)
  {
    q = p + (r-p)/2;
    if(arr[q] == elementToFind)
    {
      int prev = q - 1;
      int next = q + 1;

      if(prev < 0 || next > arr.size())
        return q;

      if(arr[prev] == elementToFind)
        p = q-1;
      else 
        return q;
    }

    if(elementToFind > arr[q])
      p = q+1;
    else
      r = q-1;

  }
  return -1;
}

int main()
{
  std::vector<int> arr {2,4,10,10,18,18,20};
  std::cout << findIndex(arr,18);
}
