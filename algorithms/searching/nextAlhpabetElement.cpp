#include <iostream>
#include <vector>
#include <string>

char findNextChar(std::string str,char ch)
{
  int p = 0;
  int q = str.length() - 1;
  int mid = -1;
  int minDiff = 26;
  int minIndex = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;

    if(str[mid] == ch)
    {
      if(mid + 1 < str.length())
        return str[mid + 1];
      else
         return ' ';
    }


    if(ch < str[mid])
    {
      q = mid - 1;

    }
    else
    {
      p = mid + 1;
      if(minDiff > (ch - str[mid]))
      {
        minDiff = ch - str[mid];
        minIndex = mid + 1;
        //means element not present
        if(minIndex >= str.size())
        {
            return ' ';
        }
          
      }
    }
  }

  if(minIndex >= 0)
    return str[minIndex];
  return ' ';


}

int main()
{
  std::cout << findNextChar("abeg",'f') << "\n";
  std::cout << findNextChar("abeg",'a') << "\n";
  std::cout << findNextChar("abeg",'g') << "\n";
}
