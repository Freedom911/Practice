//Program to move all zeros to end
#include <iostream>
#include <vector>

std::ostream &operator << (std::ostream &os,std::vector<int> &arr)
{
  for(auto &elem:arr)
    std::cout << elem << " ";
  return os;
}
void moveZero(std::vector<int>&arr)
{
  int p = -1;
  int q = 0;
  int r = arr.size() - 1;

  while(q <= r)
  {
    if(arr[q] != 0 && p != -1)
    {
      std::swap(arr[q],arr[p]);
      p++;
    }

    else if(arr[q] == 0 && p == -1)
    {
      p = q;
    }

    q++;
  }

}


int main()
{
  std::vector<int> arr{1,3,0,0,4,2,9,0,0,0,42,5};
  std::cout << "Unsorted Array = " << arr << "\n";
  
  moveZero(arr);
  std::cout << "sorted Array = " << arr << "\n";
}
