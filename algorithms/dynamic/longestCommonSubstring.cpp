//Longest Common Substing is a problem where we try to find the longest substring
//1 - A B C D E F
//2 - A C D
//Longest commong substring is CD of length 2
#include <iostream>
#include <string>

int LongestCommonSubstring(std::string str1,std::string str2)
{
  int arr[str1.length() + 1][str2.length() + 1];

  for(int i = 0; i < str1.length(); i++)
    arr[i][0] = 0;
  
  for(int j = 0; j < str2.length(); j++)
    arr[0][j] = 0;

  for(int i = 1; i <= str1.length();i++)
  {
    for(int j = 1; j <= str2.length();j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        arr[i][j] = arr[i-1][j-1] + 1;
      }
      else
      {
        //we want to make it 0 since we want it continuous
        arr[i][j] = 0;
      }
    }
  }

  return arr[str1.length()][str2.length()];

}
int main()
{
  std::cout << LongestCommonSubstring("ABCDEF","AEF");
}
