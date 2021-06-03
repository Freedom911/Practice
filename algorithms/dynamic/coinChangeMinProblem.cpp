//Given coins of different value we need to make it to the given sum
//we can take one coin unlimited number of times to make it equal to sum
//we have to calculate the minimum coints which can form the sum
//The Problem is similar to unbounded knapsack here 
//Sum is analogous to Capacity of bag 
//coin value is analogous to wight array and not value because
//because we are not maximing the value here 
#include <iostream>
#include <vector>
#include <limits>


//There is a twist in this problem we are filling the 1st row also 
//if the value is divisible i.e if desiredSum/coinsValue then it is total no of coiings
//else it will infiinite.For example we want sum to be 3 and we have 2 value coin
//3 is not divisble by 2 so it inifinte
int getMinCoints(std::vector<int> coinsValue,int desiredSum)
{
  //max -1 because we will add +1
  //so it can overflow

  int n = coinsValue.size();
  int t[n + 1][desiredSum + 1];


  for(int j = 0; j < desiredSum + 1; j++)
    t[0][j] = std::numeric_limits<int>::max() - 1; // this means given a sum and 0 coins how much coint we need to make it equal to the sum which will be inifinte
  for(int i = 0; i < n + 1; i++)
      t[i][0] = 0;


  //for second row i.e i = 1
  for(int j = 1; j < desiredSum + 1; j++)
  {
    if(j % coinsValue[0]  == 0)
      t[1][j] = j  / coinsValue[0];
    else
      t[1][j] = std::numeric_limits<int>::max() - 1;;

  }



  for(int i = 2; i < n +1;i++)
  {
    for(int j = 1; j < desiredSum + 1; j++)
    {
      if(coinsValue[i-1] > j)
      {
        t[i][j] = t[i-1][j];
      }
      else
      {
        t[i][j] = std::min(t[i-1][j], 1 + t[i][j-coinsValue[i-1]]);
      }
    }
  }

  return t[n][desiredSum];
}

int main()
{
  std::cout << "\n TOTAL = " << getMinCoints({1,2,3},5) << "\n";
}
