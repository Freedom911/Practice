//Program To check if a string is a scrambled of another
//To check A string is a scrambled of other string we can make a binary treee and swap the nonleave nodes
//Example
//String str - great
//             /   \
//            gr   eat
//           / \   / \
//          g  r  e  at
//                  / \
//                 a   t

//we can swap non leave nodes children i.e gr,eat,at and great
//String str - rgeat
//             /   \
//            rg   eat
//           / \   / \
//          r  g  e  at
//                  / \
//                 a   t
// rgeat is a scrambled string of great

//To Check for each i = 1 to N - 1 we will match both portion of the two strings
// gr|eat and rg|eat we will match not == but recursivly solve for both the regions
// ALso Great and Great are scrambled. means if str1 == str2 it is scrambled
// we want to reach at base level to check for this == 
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string,bool> umap;
//Key = A + " " + B = value

bool solve(std::string a,std::string b)
{
  //Base Conditions
  if(a == b)
    return true;

  //Means the length doesnt match
  //we ma do any never swapping but we cant have scrambled string
  if(a.length() != b.length())
    return false;

  //Check if any of the two strings are empty or not
  //if any one gets then it we return false
  if(a.empty() && !b.empty())
    return false;

  if(b.empty() && !a.empty())
    return false;



  std::string key = a + "_" + b;

  if(umap.find(key) != umap.end())
    return umap[key];


  int n = a.length();


  bool isScrambled = false;

  //Just Like MCM
  for(int i = 1; i <= n-1; i)
  {

     //Case One When we swap and Case 2 is when we dont swap
    if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))
    {
      isScrambled = true;
      break;
    }

    else if(solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))
    {
      isScrambled = true;
      break;
    }

      
  }

  return umap[key] = isScrambled;
}

int main()
{
  std::cout << "\n SOLVE = " << solve("gre","rge") << "\n";
}
 
