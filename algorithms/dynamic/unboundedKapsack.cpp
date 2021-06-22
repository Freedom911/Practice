//Unbounded Knapsack.In this we dont have restriction of choosing same item more than once
//There are more than one occurances for it
//so the item is only processed when we have decided to not include
#include <iostream>
#include <vector>

int getMaxProfit(std::vector<int> wt,std::vector<int> val,int capacity)
{
  int totalItems = wt.size();
  int t[totalItems + 1][capacity + 1];

  for(int i = 0; i < totalItems + 1; i++)
  {
    t[i][0] = 0;
  }
  for(int j = 0; j < capacity + 1; j++)
  {
    t[0][j] = 0;
  }

  for(int i = 1; i < totalItems + 1; i++)
  {
    for(int j = 1; j < capacity + 1; j++)
    {
      if(wt[i-1] > j)
      {
        t[i][j] = t[i-1][j];
      }
      else
      {
        t[i][j] = std::max(t[i-1][j],val[i-1] + t[i][j-wt[i-1]]);
      }
    }
  }

  return t[totalItems][capacity];
}

int main()
{
  std::cout << "\n MAX PROFIT = " << getMaxProfit({1,3,4,5},{10, 40, 50, 70},8) << "\n";

}
