//Longest Common Subsequence is an interesting problem where we 
//need to find longest common subsequence in two strings. Subsequence are not
//substrings they can be non continuous for example
//1 - A B C D E F
//2 - A E F
//Longest commong subsequence is 3 i.e AEF
//we could solve normally but it will take O(n * 2 ^ m)
//where m is the length of 1st string. 2 ^ m tells the total subseqeunce .i.e a character can be included or not
// 2 *2 *2 *2 .. m times =  2^m times.
//Using Dynamic Programming we first see there is an optimal substructure i.e if smaller solution forms bigger
//yes it does. we start from one side and if it matches then decrement couunter from both else. we decrement counter
//from any of the one string. without memoization there is no improvement. after using a table it takes O(m*n)
#include <iostream>
#include <string>

int **t;
int LCSMemoization(std::string s1,std::string s2,int n,int m)
{
  //Base Condition
  if(n == 0 || m == 0)
    return 0;

  if(t[n][m] != -1)
    return t[n][m];

  //If both character matches 
  if(s1[n-1] == s2[m-1])
    return t[n][m] = 1 + LCSMemoization(s1,s2,n-1,m-1); // 1 included because we have included the character

  else
    return t[n][m] = std::max(LCSMemoization(s1,s2,n-1,m),LCSMemoization(s1,s2,n,m-1));




}


int LCS(std::string str1,std::string str2)
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
        arr[i][j] = std::max(arr[i-1][j],arr[i][j-1]);
      }
    }
  }

  return arr[str1.length()][str2.length()];

}
int main(int argc,char **argv)
{
  if(argc < 3)
  {
    std::cout << "\n Enter string s1 and s2 \n";
    return 0;
  }

  std::string s1 = argv[1];
  std::string s2 = argv[2];
  std::cout << "Using Tabular method = " << LCS(s1,s2) << "\n";
  t = new int*[s1.length() + 1];
  for(int i = 0; i < s1.length() + 1; i++)
  {
    t[i] = new int[s2.length() + 1];
  }
  for(int i = 0; i < s1.length() + 1; i++)
    for(int j = 0; j < s2.length() + 1; j++)
      t[i][j] = -1;
  std::cout << "\n USING MEMOIZATIOn = " << LCSMemoization(s1,s2,s1.length(),s2.length()) << "\n";
}
