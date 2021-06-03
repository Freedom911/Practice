//Given coins of different value we need to make it to the given sum
//we can take one coin unlimited number of times to make it equal to sum
//we have to calculate the total numbr of ways
//The Problem is similar to unbounded knapsack here 
//Sum is analogous to Capacity of bag 
//coin value is analogous to wight array and not value because
//because we are not maximing the value here 
#include <iostream>
#include <vector>

int getMaxnoOfWays(std::vector<int> coinsValue,int desiredSum)
{
  int n = coinsValue.size();
  int t[n + 1][desiredSum + 1];


  for(int j = 0; j < desiredSum + 1; j++)
    t[0][j] = 0;

  for(int i = 0; i < n + 1; i++)
      t[i][0] = 1;


  for(int i = 1; i < n +1;i++)
  {
    for(int j = 1; j < desiredSum + 1; j++)
    {
      if(coinsValue[i-1] > j)
      {
        t[i][j] = t[i-1][j];
      }
      else
      {
        t[i][j] = t[i-1][j]  + t[i][j-coinsValue[i-1]];
      }
    }
  }

  return t[n][desiredSum];
}

int main()
{
  std::cout << "\n TOTAL = " << getMaxnoOfWays({1,2,3},5) << "\n";
}
