//Given Two string we need to find minimum no of steps required to convert
//str1 to str2 using insertion and deletion only. This is based on Heap
//example heap -> pea. Requires 2 deletion h and last p and then one insertion of p
//Observation to find deletion we have to subtract len(heap) - LCS
//for deletion len(pea) -LCS

#include <iostream>
#include <vector>


int LCS(std::string str1,std::string str2)
{
  int m = str1.length();
  int n = str2.length();
  int t[m+1][n+1];

  for(int i = 0; i < m + 1; i++)
    t[i][0] = 0;

  for(int j = 0; j < n + 1; j++)
    t[0][j] = 0;

  for(int i = 1; i < m + 1; i++)
  {
    for(int j = 1; j < n + 1; j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        t[i][j] = 1 + t[i-1][j-1];
      }
      else
      {
        t[i][j] = std::max(t[i-1][j],t[i][j-1]);
      }

    }

  }

  return t[m][n];

}

int getMinimumStepsForConversion(std::string s1,std::string s2)
{
  int lcs = LCS(s1,s2);
  int deletionSteps = s1.length() - lcs;
  int insertionSteps = s2.length() - lcs;

  return deletionSteps + insertionSteps;
}

int main()
{
  std::cout << "\n Minimum Steps For Conversion" << getMinimumStepsForConversion("heap","pea") << "\n";
}
