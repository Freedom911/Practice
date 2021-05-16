//finding maximum in a first increasing then decreasing or vice versa 
//pattern using binary search in o(logn)
//There are three cases
//case 1 left is less right is more
//case 2 left is more right is less
//case 3 both side less. This is the max number which we want
#include <iostream>
#include <vector>

int maxNumber(std::vector<int> arr,int start,int end)
{
  if(start == end)
    return arr[start];

  if(start + 1 == end)
  {
    if(arr[start] > arr[end])
      return arr[start];
    else
      return arr[end];
  }

  int mid = start + (end - start)/2;

  //both side less
  if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    return arr[mid];

  else
  {
    //left side less right side more
    if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
      return maxNumber(arr,mid + 1,end);

    return maxNumber(arr,start,mid - 1);

  }

}

int main()
{
  std::vector<int> arr{6,9,15,25,35,50,41,29,23,8};

  std::cout << "\n Max Number is = " << maxNumber(arr,0,arr.size() - 1) << "\n";
}
