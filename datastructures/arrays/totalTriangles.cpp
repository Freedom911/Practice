//Find TOtal Trigangles that can be formed
//with 3 sides. Triagnle property is 
//sum of any two sides is greater than 3rd
//we will first sort array

#include <iostream>
#include <vector>
#include <algorithm>

int totalTriangles(std::vector<int> arr)
{
  std::sort(arr.begin(),arr.end());
 
  int n = arr.size();
  int count = 0;
  for(int i = 0; i < n -2; i++)
  {
    int k = i+ 2;
    for(int j = i+ 1; j < n; j++)
    {
      
      while(k < n && arr[i] + arr[j] > arr[k])
        k++;

      if(k > j)
        count += k -j - 1;
    }
  }

  return count;
}

int main()
{
  std::vector<int> arr { 10, 21, 22, 100, 101, 200, 300 };

  std::cout << totalTriangles(arr) << "\n";
}
