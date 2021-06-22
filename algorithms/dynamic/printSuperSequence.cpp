//Print SuperSequence String. This is an extension of lcs only
//We need to print lcs once for both string and then print out the remaining
//letters from both the strng
#include <iostream>
#include <vector>
#include <string>



std::string printSuperSequence(std::string s1,std::string s2)
{
   int m = s1.size();
   int n = s2.size();
   int t[m+1][n+1];

   //LCS
   for(int i = 0; i < m + 1; i++)
   {
     t[i][0] = 0;
   }
   for(int j = 0; j < n + 1; j++)
   {
     t[0][j] = 0;
   }


   for(int i = 1; i < m + 1; i++)
   {
     for(int j = 1; j < n + 1; j++)
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


   std::string op;
   int i = m,j = n;

   while(i > 0 && j > 0)
   {
     if(s1[i-1] == s2[j-1])
     {
       op = s1[i-1] + op;
       i--;
       j--;
     }
     
     //If upper is bigger then move to bigger
     //in which ever direction we move we included that string
     else if(t[i-1][j] > t[i][j-1])
     {
       op = s1[i-1] + op;
       i--;
     }
     else
     {
       op = s2[j-1] + op;
       j--;
     }
   }

   //include the left strings as it can happen with supersequence
   //if one string is emepty then other string has to be included fully in the answer
   while( i > 0)
   {
     op = s1[i-1] + op;
     i--;
   }

   while(j > 0)
   {
     op = s2[j-1] + op;
     j--;
   }

   return op;
}

int main()
{
  std::cout << "\n Super Sequence is = " << printSuperSequence("abac","cab") << "\n";
}
