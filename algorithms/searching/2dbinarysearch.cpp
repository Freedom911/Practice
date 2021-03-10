#include <iostream>
#include <vector>

int findElement(std::vector<int> arr,int elementToFind,int findExact)
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
  if(findExact)
    return -1;
  else
    if(q < arr.size() && arr[q] < elementToFind && q+1 < arr.size())
      return q+1;
  return q;
}

int main()
{
  std::vector<std::vector<int>> arr =  {{ 3, 30, 38},{36, 43, 60}, {40, 51, 69}};
  std::vector<int>r,c;

  for(int i = 0; i < arr.size(); i++)
  {
    c.push_back(arr[i][0]);
  }
   
  const int rowNo = findElement(c,40,0);
  for(int i = 0; i < arr[0].size(); i++)
  {
    r.push_back(arr[rowNo][i]);
  }

  int k = findElement(r,40,1);
  std::cout << "\n Element at=[" << rowNo << "," << k << "]\n";

}
