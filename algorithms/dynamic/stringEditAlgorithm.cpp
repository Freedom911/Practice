//String Edit Algorithm is an algorithm for finding the minimum no of operations
//i.e insert,replace and delete required to convert one string to another
//we construct the 2d matrix of the length of the two string.
//For insert it takes 1 + C[m][n-1] previous column
//For delete it takes 1 + C[m-1][n] previous row
//for replace we add 1 to diagnoal element
//When Last Character of two string is same then we simple remove that ad add 1 to diagnoal element
//When last character of two strings is not same then we find the minimum of insert,delete and replace and add 1

/**
 *
 * I will explain once again
 *
 * There will be three cases
 * s1 = horse
 * s2 = ros
 *
 * we start from the last index .i represents index for s1 and j for s2.
 * we have 3 choices 
 * sp compare e and s since they are not equal we have work to do
 *
 * case 1 : insert
 * we insert s in s1 to make it equal to j index of s2
 * so after working we shrink s2 and since i is already at e we wont shrink because in next
 * we start from e and j points to 0
 * so work done 1 + f(i,j-1)
 *
 * Case 2 : Delete
 * we Delete e
 * we keep j at last index of s2 because in next we want to compare with new i which will be reduced
 * so work done 1 + f(i-1,j)
 *
 * Case 3 : replace
 * We replace e with s to match so now since both matches we can peacefully proceed to shrink both strings
 * work done 1 + f(i-1,j-1)
 *
 * Now Moving to base condition
 *
 * see assume we have exhausted i and it is less than 0 so for that we need j operations to insert and match
 * with string 2
 * similarly if j is exhausted we delete i operations
 */

#include <iostream>
#include <string>

//Hypothesis this functino treturns the min operation to get from str1 to str2 till i and j
//i and j starts from n -1 and m -1

int findMinOperationsRec(std::string str1,std::string str2,int i,int j)
{
    //base conditions
    if(i < 0 && j < 0)
    {
        return 0;//means no one left
    }
    else if(i < 0)
    {
        return j + 1;//we need these many insertions
    }
    else if(j < 0)
    {
        return i + 1; //we need these many delection in str1
    }

    if(str1[i] == str2[j])
    {
        return 0 + findMinOperationsRec(str1,str2,i-1,j-1);//no work done since they are equal
    }
    
    else
    {
        int ins = 1 + findMinOperationsRec(str1,str2,i,j-1);
        int del = 1 + findMinOperationsRec(str1,str2,i-1);
        int rep = 1 + findMinOperationsRec(str1,str2,i-1,j-1);
        return std::min(ins,std::min(del,rep));
    }
}


int findMinOperations(std::string str1,std::string str2)
{
    //one thing is since i < 0 so we just make every operation + 1
  int C[str1.length() + 1][str2.length() + 1];

  //1st row and column would contain value where one string is null
  for(int i = 0; i <= str1.length(); i++)
  {
    for(int j = 0; j <= str2.length(); j++)
    {
      if(i == 0)
      {
        C[i][j] = j; // we need these many insertions
      }
      else if(j == 0)
      {
        C[i][j] = i; //we need these may deletions
      }

      //last character is same
      else if(str1[i - 1] == str2[j -1])
        C[i][j] = 0 + C[i-1][j-1];

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
