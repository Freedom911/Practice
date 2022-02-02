#include <iostream>

void print(int arr[]) //when we pass array this will be converted to pointer
{
  std::cout << sizeof (arr) << "\n";//so this will print size of pointer i.e 8
}
void printRef(int (&arr)[10]) //we will use reference to array
{
  std::cout << sizeof (arr) << "\n";//so this will print size of array
}

//to make it genric
template<class T,size_t n>
void printGenRef(T(&arr)[n])
{
 std::cout << sizeof(arr) << "\n";
}

int main()
{
  int i;
  std::cout << sizeof(i) << "\n";
  int arr[10];
  print(arr);
  printRef(arr);
  printGenRef(arr);
}
