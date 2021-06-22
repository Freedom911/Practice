//Program For Partitioning a string to form palindromes. Need tominimize partitions
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

int **t;

bool is_palindrome(std::string s, int low, int high)
{
  if( low >= high)
    return true;

  while(low< high)
  {
    if(s[low]!=s[high])
      return false;

    low++; high--;
  }

  return true;
}

int getMinPartition(std::string s,int i,int j)
{
  //Step 1 Base Condition
  //If string is empty or 1 length then in both case 
  //we dont require partitioning
  if(i >= j)
    return 0;

  //Means This string is Palindrome
  if(is_palindrome(s,i,j))
    return 0;


  if(t[i][j] != -1)
    return t[i][j];


  int min = std::numeric_limits<int>::max();
  for(int k = i; k <= j-1; k++)
  {
    int tempAns = getMinPartition(s,i,k) + getMinPartition(s,k + 1,j) + 1;

    min = std::min(tempAns,min);
  }

  return  t[i][j] = min;

}


int getMinPartitionOptimized(std::string s,int i,int j)
{
  //Step 1 Base Condition
  //If string is empty or 1 length then in both case 
  //we dont require partitioning
  if(i >= j)
    return 0;

  //Means This string is Palindrome
  if(is_palindrome(s,i,j))
  {
    std::cout << s.substr(i,j) << "\n";
    return 0;
  }

  if(t[i][j] != -1)
    return t[i][j];


  int min = std::numeric_limits<int>::max();
  for(int k = i; k < j; k++)
  {
    int left,right;

    if(t[i][k] != -1)
      left = t[i][k];
    else
      t[i][k] = left = getMinPartitionOptimized(s,i,k);

    if(t[k+1][j] != -1)
      right = t[k+1][j];
    else
      t[k+1][j] = right = getMinPartitionOptimized(s,k+1,j);


    int tempAns = 1 + left + right;

    min = std::min(tempAns,min);
  }

  return  t[i][j] = min;

}

int main()
{
  //std::string s = "coder";
  //std::string s = "aab";
 // std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  //std::string s = "ababbbabbababaaababababababbbababababababbbabababababbababababababababababbabbbbbaaaaaaaabababababababababbbbaaaabababababbbbbaaaabababababababa";
  std::string s = "madam";
  int size = s.length();

  t = new int*[size + 1];
  for(int i = 0; i < size + 1; i++)
    t[i] = new int[size + 1];

  for(int i = 0; i < size + 1; i++)
  for(int j = 0; j < size + 1; j++)
    t[i][j] = -1;



  std::cout << "\n MinPartition = " << getMinPartitionOptimized(s,0,size - 1) << "\n";
  std::cout << "\n MinPartition = " << getMinPartition(s,0,size - 1) << "\n";



}
