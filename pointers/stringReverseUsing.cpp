#include <iostream>
int main()
{
  char ch[] = "Hello Srajan";

  char *ptr = &ch[0];
  int length = 0;
  while(*ptr != '\0')
  {
    ptr++;
    length++;
  }
 

  while(length >= 0)
  {
    std::cout << *ptr;
    ptr--;
    length--;
  }


}
