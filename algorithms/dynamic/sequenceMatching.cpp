//Given a string S1 check wether it is a subsequence of string s2
#include <iostream>
#include <string>
#include <vector>

int LCS(std::string s1,std::string s2)
{
  int m = s1.size();
  int n = s2.size();

  int t[m+1][n+1];

  for(int i = 0 ; i < m + 1; i++)
    t[i][0] = 0;

  for(int j = 0; j < n + 1; j++)
    t[0][j] = 0;


  for(int i = 1; i < m + 1; i++)
  {
    for(int j = 1 ; j < n + 1; j++)
    {
      if(s1[i-1] == s2[j-1])
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


//Using two pointers complexity is O(n)
bool isSequenceTwoPointers(std::string str1,std::string str2)
{
 int  j = 0;
 for(int i = 0; i < str1.length(); i++)
 {
	 if(str1[i] == str2[j])
	 {
		 j++;
	 }
 }
 
 return j == str2.length();
}

bool isSequence(std::string str1,std::string str2)
{

  return str2.length() == LCS(str1,str2)? true:false;
}

int main()
{
  std::cout << "\n Is Sequence " << isSequence("ADXCPY","AXY") << "\n";
  std::cout << "\n Is Sequence " << isSequenceTwoPointers("ADXCPY","AXY") << "\n";
}
