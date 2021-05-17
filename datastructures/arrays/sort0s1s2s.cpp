//Program To Sort Array with 0,1,2
//We could do a counting sort where in 1st traversal we count
//the no of 0s 1s and 2s and then in second traversal right that many times
//Another Approach is to do in 1 traversal only
//Here if 0 is encountered move to left,2 is encountered then move to right
//for 1 do nothing
#include <iostream>
#include <vector>

void sortArray(std::vector<int> &arr)
{
  std::cout << "Sorting ARray\n";
  int low = 0;
  int mid = 0;
  int high = arr.size() - 1;
  while(mid <= high)
  {
    if(arr[mid] == 0)
    {
      std::swap(arr[low],arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 2)
    {
      std::swap(arr[mid],arr[high]);
      high--;
    }
    else
      mid++;
  }

}

std::ostream &operator<<(std::ostream &os,const std::vector<int> &arr)
{
  for(auto &elem:arr)
    os << elem << " ";

  return os;
}

int main()
{
  std::vector<int> arr{2,2,2,2,2,0,2,2,1,1,1,1,0,2,2,2,0,0,0,0,1};
  std::cout << arr << "\n";
  sortArray(arr);
  std::cout << arr << "\n";
}
