//Given an array we need to find subsets whose difference of sum of their elements is 
//DIFF which is given in equation. i.e S1-S2 = DIFF.
//We know S1+S2 = sum of Array we solve this quation
//to get S1 = (Diff + sum)/2 so we jus need to get this count
#include <iostream>
#include <vector>
#include <numeric>

int getCountSubsetSum(std::vector<int> in,int sum)
{
  int n = in.size() ;
  int t[in.size() + 1][sum + 1];

  for(int j = 0; j < sum + 1; j++)
    t[0][j] = 0;

  for(int i = 0; i < n + 1;i++)
  {
    t[i][0] = 1;
  }

  for(int i = 1; i < n + 1;i++)
  {
    for(int j = 1; j < sum + 1; j++)
    {
      //dont include
      if(in[i-1] > j)
      {
        t[i][j] = t[i-1][j];
      }
      else
      {
        t[i][j] = t[i-1][j-in[i-1]] + t[i-1][j];
      }
    }
  }

  return t[n][sum];

}

int getCountOfSubsetWithDiff(std::vector<int> in,int diff)
{
  int sum = std::accumulate(in.begin(),in.end(),0);
  int desiredSum = (sum + diff)/2;

  return getCountSubsetSum(in,desiredSum);
}

int main()
{
  std::cout << "\n TOTAL SUCH SETS = " << getCountOfSubsetWithDiff({1,1,2,3},1) << "\n";
}


