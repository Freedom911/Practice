//Program For Subset Sum That is given a sum S can we find subsets of array which has sum S
//Variation of knapsack
#include <iostream>
#include <vector>

bool hasSubsetSum(std::vector<int>arr,int desiredSum)
{
  int n = arr.size() ;
  int mt[n+1][desiredSum+1];

  //Initializations. 
  //If we have sum S can we make with 0 elements noope
  for(int j = 0; j < desiredSum + 1; j++)
  {
    mt[0][j] = false;
  }

  //if we have sum 0 can we make with 0 or more elmenets . yes it is null set
  for(int i = 0; i < n + 1;i++)
    mt[i][0] = true;


  for(int i = 1; i < n+1;i++)
  {
    for(int j = 1; j < desiredSum + 1; j++)
    {
      //check if the sum of the array at ith element is gereater then there 
      //is no way we can include the element
      if(arr[i-1] > j)
      {
        mt[i][j] = mt[i-1][j];
      }
      else
      {
                   //include the leement  dont include
        mt[i][j] = mt[i-1][j-arr[i-1]] || mt[i-1][j];
      }
    }
  }


  return mt[n][desiredSum];

}

int main()
{
  std::cout << "\n IS SUBSET SUM POSSIBLE ? = " << hasSubsetSum({2,3,5,10},2) << "\n";
}
