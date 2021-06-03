//Find length of longest commond subsequence
#include <iostream>
#include <vector>
#include <algorithm>


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

int getLongestPalindromeLength(std::string str)
{
  std::string strRev = str;
  std::reverse(strRev.begin(),strRev.end());
  return LCS(str,strRev);
}

int main()
{
  //Longest Palindrome
  std::cout << getLongestPalindromeLength("agbcba") << "\n";
}
