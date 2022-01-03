//Program to find a number whose left side is less and right side is more
//in O(n)

#include <iostream>
#include <vector>

int findNo(std::vector<int> arr)
{
  int ans = -1;
  int max = arr[0];

  for(int i = 1; i < arr.size(); i++)
  {

    int element = arr[i];
    if(ans != -1 && arr[i] < max)
    {
      ans = -1;
    }
    else if(ans == -1 && max < element)
    {
      max = element;
      ans = max;
    }

  }

  return ans;
}

int main()
{
  std::vector<int> arr{16,2,5,4,7,21,8,100,300,400};
  std::vector<int> arr1{6,2,5,4,7,9,11,8,10};
  std::vector<int> arr2{4,3};
  std::vector<int> arr3{17 ,19 ,9 ,5 ,3 ,6 ,17 ,7 ,18 ,16 ,18 ,11 ,3 ,15, 2};

 // std::cout << findNo(arr) << "\n";
 // std::cout << findNo(arr1) << "\n";
 // std::cout << findNo(arr2) << "\n";
  std::cout << findNo(arr3) << "\n";

}
