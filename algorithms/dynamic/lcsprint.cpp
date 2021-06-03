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

//Need to Print

#include <iostream>
#include <string>



void printLCS(std::string str1,std::string str2)
{
  int arr[str1.length() + 1][str2.length() + 1];

  for(int i = 0; i < str1.length(); i++)
    arr[i][0] = 0;
  
  for(int j = 0; j < str2.length(); j++)
    arr[0][j] = 0;

  std::string op1;

  for(int i = 1; i <= str1.length();i++)
  {
    for(int j = 1; j <= str2.length();j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        arr[i][j] = arr[i-1][j-1] + 1;
        op1 += str1[i-1];
      }
      else
      {
        arr[i][j] = std::max(arr[i-1][j],arr[i][j-1]);
      }
    }
  }

  std::cout << "\n 1 = " << op1 << "\n";

  int i = str1.length(),j = str2.length();

  std::string op;
  while(i > 0 && j > 0)
  {
    if(str1[i-1] == str2[j-1])
    {
      op = str1[i-1] + op;
      i--;
      j--;
    }
    else
    {
      //move to bigger
      if(arr[i][j-1] > arr[i-1][j])
      {
        j--;
      }
      else 
        i--;
    }
  }

  std::cout << "\n LCS = " << op << "\n";


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
  printLCS(s1,s2);
}
