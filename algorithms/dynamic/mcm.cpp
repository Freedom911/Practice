//Matrix Chain Multiplication
#include <iostream>
#include <limits>
#include <vector>

int **t;


int totalMultiplications(std::vector<int> ar,int i ,int j)
{
  //Base condition if 1 or less than one elements present then return
  //since  it means only one matrix in case i == j 
  if( i>= j)
    return 0;

  if(t[i][j] != -1)
    return t[i][j];

  int min = std::numeric_limits<int>::max();
  for(int k = i; k < j; k++)
  {
    int tempAns = totalMultiplications(ar,i,k) + totalMultiplications(ar,k + 1,j) + ar[i-1] * ar[k] * ar[j];

    min = std::min(min,tempAns);
    
  }

  return t[i][j] = min;
}


int main()
{
  //std::vector<int> ar{40,20,30,10,30};
  std::vector<int> ar{10, 20, 30, 40, 30};
  t = new int*[ar.size() + 1];

  for(int i = 0; i < ar.size() + 1; i++)
    t[i] = new int[ar.size() + 1];

  for(int i = 0; i < ar.size() + 1; i++)
  {
    for(int j = 0; j < ar.size() + 1; j++)
    {
      t[i][j] = -1;
    }
  }

  //i starts from 1
  std::cout << "\n TOTAL = " << totalMultiplications(ar,1,ar.size() - 1);


}
