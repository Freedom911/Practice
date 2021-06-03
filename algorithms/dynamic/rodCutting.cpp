//Unbounded Knapsack.In this we dont have restriction of choosing same item more than once
//There are more than one occurances for it
//so the item is only processed when we have decided to not include
#include <iostream>
#include <vector>

int getMaxProfit(std::vector<int> length,std::vector<int> val,int totalPieces)
{
  int totalItems = length.size();
  int t[totalItems + 1][totalPieces + 1];

  for(int i = 0; i < totalItems + 1; i++)
  {
    t[i][0] = 0;
  }
  for(int j = 0; j < totalPieces + 1; j++)
  {
    t[0][j] = 0;
  }

  for(int i = 1; i < totalItems + 1; i++)
  {
    for(int j = 1; j < totalPieces + 1; j++)
    {
      if(length[i-1] > j)
      {
        t[i][j] = t[i-1][j];
      }
      else
      {
        t[i][j] = std::max(t[i-1][j],val[i-1] + t[i][j-length[i-1]]);
      }
    }
  }

  return t[totalItems][totalPieces];
}

int main()
{
  std::cout << "\n MAX PROFIT = " << getMaxProfit({1,2,3,4,5,6,7,8},{1,5,8,9,10,17,17,20},8) << "\n";

}
