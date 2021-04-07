#include <iostream>
#include <functional>

template<std::size_t N,class T>
constexpr std::size_t arraySize(T(&)[N])
{
  return N;
}

int partition(int arr[],int p,int r,const std::function<bool(int,int)> &sortOrder)
{
  int pivot = arr[r];
  int i = p - 1;

  int j;
  for(j = p; j <= r -1; j++)
  {
    //if(arr[j] < pivot)
    if(sortOrder(arr[j],pivot))
    {
      i++;
      std::swap(arr[j],arr[i]);
    }
  }

  i++;
  std::swap(arr[i],arr[r]);
  return i;

}

void quicksort(int arr[],int p,int r,const std::function<bool(int,int)> &sortOrder)
{
  if(p < r)
  {
   int q = partition(arr,p,r,sortOrder);
   quicksort(arr,p,q-1,sortOrder);
   quicksort(arr,q+1,r,sortOrder);
  }
}

int main()
{
  int arr[] = {3,2,5,10,14,4};

  std::cout << "\n BEFORE SORTING \n";
  for(int i = 0 ; i < arraySize(arr); i++)
  {
    std::cout << arr[i] << ",";
  }

  auto sorterDesc = [](int a,int b) -> bool {return a < b ? true:false;};
  auto sorterAsc = [](int a,int b) -> bool {return a > b ? true:false;};

  quicksort(arr,0,arraySize(arr) - 1,sorterDesc);
  std::cout << "\n AFTER SORTING IN DESC \n";
  for(int i = 0 ; i < arraySize(arr); i++)
  {
    std::cout << arr[i] << ",";
  }
  quicksort(arr,0,arraySize(arr) - 1,sorterAsc);
  std::cout << "\n AFTER SORTING IN ASC \n";
  for(int i = 0 ; i < arraySize(arr); i++)
  {
    std::cout << arr[i] << ",";
  }
}
