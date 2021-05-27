//Program To efficiently Trap Rain Water based on the array given

#include <iostream>
#include <vector>

//O(n2) event
int totalUnitsTrapped(std::vector<int> ar)
{
  int totalUnits = 0;
  for(int i = 0; i < ar.size() - 1;)
  {
    int ind = -1;
    int j ;
    for(j = i + 1; j < ar.size(); j++)
    {
      if(ar[j] >= ar[i])
      {
        ind = j;
        break;
      }
    }

    if(ind == -1)
    {
      i++;
      continue;
    }

    for(ind = i + 1; ind < j; ind++)
    {
      totalUnits += ar[i] - ar[ind];
    }

    i = j;
  }

  return totalUnits;

}

//Solution in O(n) time and space complexity
//we will maintain the max height of left and right of a bar
//which ever is less needs to be subtracted from that bar
int totalUnitsTrappedOptimized(std::vector<int> ar)
{
  std::vector<int> leftSide(ar.size(),0),rightSide(ar.size(),0);
  int max = -1;
  for(int i = 0; i < ar.size(); i++)
  {
    if(ar[i] > max)
    {
      max = ar[i];
    }
    leftSide[i] = (max);

  }

  max = -1;
  for(int i = ar.size() - 1; i >= 0; i--)
  {
     if(ar[i] > max)
     {
       max = ar[i];
     }
 
     rightSide[i] = max;

  }

  int totalUnits = 0;

  for(int i = 1; i < ar.size() - 1; i++)
  {
    int min = leftSide[i] < rightSide[i] ? leftSide[i]:rightSide[i];

    totalUnits += min - ar[i];
  }

  return totalUnits;

}


int main()
{
  //std::vector<int> elev{0,1,0,2,1,0,1,3,2,1,2,1};
  std::vector<int> elev{5,3,4,6,3,6};

  std::cout << "\n Total Units Trapped = " << totalUnitsTrapped(elev) << " Units\n";
  std::cout << "\n Total Units Trapped = " << totalUnitsTrappedOptimized(elev) << " Units\n";
}
