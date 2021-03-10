#include<iostream>
#include <limits>

template<std::size_t N,class T>
constexpr std::size_t arraySize(T(&)[N])
{
  return N;
}

void MergeAndSort(int arr[],int p,int q,int r)
{

  int n1  = q - p + 1;
  int n2 = r - q ;//- 1;

  if(n2 < 0)
    n2 = 0;

  int L1[n1 + 1],L2[n2 + 1];

  for(int i = 0; i < n1; i++)
  {
    L1[i] = arr[p + i];
  }
  for(int i = 0; i < n2; i++)
  {
    L2[i] = arr[q + i];
  }
  L1[n1] = std::numeric_limits<int>::max();
  L2[n2] = std::numeric_limits<int>::max();

  int i = 0,j = 0,k = p;
  for(; k < r;k++)
  {
    if(L1[i] <= L2[j])
      {
	arr[k] = L1[i];
	i++;
      }

      else
      {
	arr[k] = L2[j];
	j++;
      }

  }

  while(i < n1)
  {
    arr[k] = L1[i];
    i++;
    k++;
  }
  while(j < n1)
  {
    arr[k] = L2[j];
    j++;
    k++;
  }

}


void MergeSort(int arr[],int p,int r)
{
  if(p >= r)
    return;

    else
    {
      int q = (p + r)/2;
      MergeSort(arr,p,q);
      MergeSort(arr,q+1,r);
     // MergeAndSort(arr,p,q,r);

    }

}


int main()
{
  int arr[] = {5,2,4,7,1,3,2,6};
  std::cout << "\n Before Sorting \n";
  for(int index = 0; index < arraySize(arr); index++)
  {
    std::cout << arr[index] << " ";
  }
  std::cout << "\n After Sorting \n";
  MergeSort(arr,0,arraySize(arr));
  for(int index = 0; index < arraySize(arr); index++)
  {
    std::cout << arr[index] << " ";
  }


}
