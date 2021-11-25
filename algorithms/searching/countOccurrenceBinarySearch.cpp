
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
      {
        r = q-1;
        std::cout << p << "\n";
      }
      else 
        return q;
    }

    else
    {
      if(elementToFind > arr[q])
        p = q+1;
      else
        r = q-1;
    }

  }
  return -1;
}


int findLastIndex(std::vector<int> arr,int elementToFind)
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

      if(arr[next] == elementToFind)
        p = q+1;
      else 
        return q;
    }

    else
    {
      if(elementToFind > arr[q])
        p = q+1;
      else
        r = q-1;
    }

  }
  return -1;
}
int findOccurrence1(std::vector<int> arr,int elementToFind)
{
  int st = findIndex(arr,elementToFind);
  int count = 0;
  while(st < arr.size())
  {
    if(arr[st] != elementToFind)
      return count;
    count++;
    st++;
  }
  return count;
}

int findOccurrence(std::vector<int> arr,int elementToFind)
{
  int st = findIndex(arr,elementToFind);
  int rt = findLastIndex(arr,elementToFind);
  std::cout << st << " " << rt << "\n";
  if(st == -1)
    return st;
  else
    return rt - st + 1;
}
int main()
{
  std::vector<int> arr {2,4,10,10,10,10,10,10,18,18,20};
  std::cout << findOccurrence(arr,10);
}
