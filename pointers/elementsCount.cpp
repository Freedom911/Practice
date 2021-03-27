//https://www.geeksforgeeks.org/c-pointers-question-6/
#include <iostream>
int main()
{
  int arr[] = {110, 120, 230, 50, 1560, 640};
  int *ptr1 = arr;
  int *ptr2 = arr + 1;


  std::cout << "Number of elements between two pointer are: " <<  (ptr2 - ptr1)  << "\n";
  std::cout << "Number of bytes between two pointers are: " <<  (int*)ptr2 - (int*)ptr1 << "\n";
  std::cout << "Number of bytes between two pointers are: " <<  (char*)ptr2 - (char*)ptr1;




  int a;
   char *x;
   x = (char *) &a;
   a = 512;
   x[0] = 1;
   x[1] = 2;
   std::cout << "\n == " << a;






  return 0;
}

