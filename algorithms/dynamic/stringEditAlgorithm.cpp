//String Edit Algorithm is an algorithm for finding the minimum no of operations
//i.e insert,replace and delete required to convert one string to another
//we construct the 2d matrix of the length of the two string.
//For insert it takes 1 + C[m][n-1] previous column
//For delete it takes 1 + C[m-1][n] previous row
//for replace we add 1 to diagnoal element
//When Last Character of two string is same then we simple remove that ad add 1 to diagnoal element
//When last character of two strings is not same then we find the minimum of insert,delete and replace and add 1
#include <iostream>
#include <string>

int findMinOperations(std::string str1,std::string str2)
{
  int C[str1.length() + 1][str2.length() + 1];

  //1st row and column would contain value where one string is null
  for(int i = 0; i <= str1.length(); i++)
  {
    for(int j = 0; j <= str2.length(); j++)
    {
      if(i == 0)
      {
        C[i][j] = j;
      }
      else if(j == 0)
      {
        C[i][j] = i;
      }

      //last character is same
      else if(str1[i - 1] == str2[j -1 ])
        C[i][j] = 1 + C[i-1][j-1];

      else
      {
                               //delete  //insert  //replace
        C[i][j] = 1 + std::min(std::min(C[i-1][j],C[i][j-1]),C[i-1][j-1]);
      }

    }
  }

  return C[str1.length()][str2.length()];

}
int main()
{
  std::cout << "\n MIN OPERATION = " << findMinOperations("s","S") << "\n";
}
