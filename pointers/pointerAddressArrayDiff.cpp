//https://www.geeksforgeeks.org/whats-difference-between-array-and-array-for-int-array5/
//Difference between array and &array

#include <iostream>
int main()
{
  int arr[5] = {1,2,3,4,5};

  std::cout << "\n Array and &Array " << arr << " " << &arr << "\n";
  std::cout << "\n After Incrementing Array and &Array " << arr+1 << " " << &arr+1 << "\n";
}
