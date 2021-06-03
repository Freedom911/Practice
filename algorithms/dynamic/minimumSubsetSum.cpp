//Program for finding the sum of two partitions such that it is minimum
//uses subset sum
#include <iostream>
#include <vector>
#include <limits>


std::vector<int> findSubsetSum(std::vector<int> ar,int desiredSum)
{
  //initialization
  int n = ar.size();
  int mt[n+1][desiredSum+1];

  for(int j = 0; j < desiredSum + 1;j++)
  {
    mt[0][j] = 0;
  }

  for(int i = 0; i < n + 1; i++)
  {
    mt[i][0] = 1;
  }

  for(int i = 1; i < n + 1; i++)
  {
    for(int j = 1; j < desiredSum + 1; j++)
    {
      //dont include
      if(ar[i-1] > j)
      {
        mt[i][j] = mt[i-1][j];
      }
      else
      {
        mt[i][j] = mt[i-1][j-ar[i-1]] || mt[i-1][j];
      }
    }
  }

  std::vector<int> output;
  for(int j = 0; j < desiredSum/2;j++)
  {
    //if it is true then push the desired sum posoible
    if(mt[n][j] == 1)
    output.push_back(j);
  }

  return output;
}

int findMinimumSum(std::vector<int> ar)
{
  int range = 0;
  for(auto &e:ar)
    range += e;
  std::vector<int> vec = findSubsetSum(ar,range);//this will return all the possible sum we can uptop half of range
                                                 //other half would sumple be range - this
  //after findin
  int min = std::numeric_limits<int>::max();

  //Minmize Range - 2 *vec[i]
  for(auto &e:vec)
  {
    min = std::min(min,range - 2 * e);
  }

  return min;

}

int main()
{
  std::cout << "MINIMUM SUM PARITION = " << findMinimumSum({1,2,7}) << "\n";
}
