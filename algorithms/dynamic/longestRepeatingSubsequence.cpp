//Given a string we need to find the longestsubsequences which is repeating
//example AABEBCDD
//Repeating ABC,AB,BC
//This is similar to lcs we calculate lcs of same string but with one restriction that if i == j then we dont include
//in the answer this condition ensures that we have 2 or more same character then only we can
//form repeating subsequence.

#include <iostream>
#include <string>
#include <vector>

int longestRepeatingSubsequence(std::string str1)
{
  std::string str2 = str1;
  int m = str1.size();
  int n = str2.size();
  int t[m+1][n+1];

  for(int i  = 0 ; i < m; i++)
  {
     t[i][0] = 0;
  }

  for(int j = 0; j < n;j++)
  {
    t[0][j] = 0;
  }

  for(int i = 1; i < m + 1; i++)
  {
    for(int j = 1; j < n + 1; j++)
    {
      //to ensure more than one occurance of letter
      if(str1[i-1] == str2[j-1] && i != j)
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

int main()
{
   std::cout << "\n LONGEST REPEATING SUBSEQUENCE " << longestRepeatingSubsequence("AABEBCDD") << "\n";
}

