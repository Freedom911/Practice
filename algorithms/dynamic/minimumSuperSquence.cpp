//Minimum Supersequnce is we need to output the length of minimum  string 
//merged from str1 and str2 such that both strings are included
//example str1 = geeks str2 eks
//1 merging would be geeks + eks = geekseks - Length - 8
//2 merging could be geeks only it contains both
//If look closly we have to include lcs once from both string and add the missing
//chraacters

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

int getShortestComonSuperSequence(std::string str1,std::string str2)
{
  return str1.length() + str2.length() - LCS(str1,str2);
}

int main()
{
  std::cout << "\n Shortest Super Sequence Length = " << getShortestComonSuperSequence("AGGTAB","GXTXAYB") << "\n";
}

