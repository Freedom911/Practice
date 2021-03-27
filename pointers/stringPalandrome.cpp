#include <iostream>
int main()
{

  char ch[] = "TENETS";
  char *ptr = &ch[0];
  int len = sizeof(ch)/sizeof(ch[0]);


  char *rev = &ch[len - 2]; // last is null
  len--;

  int n = len/2;
  while (len >= n)
  {
    if(*rev != *ptr)
    {
      std::cout << "\n NOt A PALINDROME \n";
      return 1;
    }


    rev--;
    len --;
    ptr++;
  }


  std::cout << "\n IT's a palindrome \n";



}
