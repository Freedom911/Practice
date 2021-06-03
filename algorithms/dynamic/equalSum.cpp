//Program To find whehther two partition have equal sum or not
//Extension of subset sum. 

#include <iostream>
#include <vector>


bool isSubsetSum(std::vector<int> ar,int desiredSum)
{
  //Initialization
  int n = ar.size();
  int matrix[n + 1][desiredSum + 1];

  for(int j = 0; j <desiredSum + 1;j++)
    matrix[0][j] = 0;

  for(int i = 0; i < n+1;i++)
  {
    matrix[i][0] = 1;
  }


  for(int i = 1; i < n+1;i++)
  {
    for(int j = 1; j < desiredSum + 1;j++)
    {
      //if the sum of array is greater than desired sum then
      //we wont be able to chose this element)
      if(ar[i-1] > j)
      {
        matrix[i][j] = matrix[i-1][j];
      }
      else
      {
        matrix[i][j] = matrix[i-1][j-ar[i-1]] || matrix[i-1][j];
      }
    }
  }

  return matrix[n][desiredSum];
}

bool checkHasEqualSubset(std::vector<int> ar)
{
  int sum = 0;
  for(auto &e:ar)
    sum +=e;

  //if the sum is odd then we in no way can divide the array into 2
  if(sum %2 != 0)
    return 0;
  else 
    return isSubsetSum(ar,sum/2);
}

int main()
{
  std::cout << "\n Check Has Qual Subset = " << checkHasEqualSubset({1,5}) << "\n";
  std::cout << "\n Check Has Qual Subset = " << checkHasEqualSubset({1,5,6}) << "\n";
  std::cout << "\n Check Has Qual Subset = " << checkHasEqualSubset({1,5,3}) << "\n";
}
