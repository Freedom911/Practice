#include <iostream>

class ABC
{
 public:
   ABC():V(3)
   {
    // V = 3;
   }
    int V = 3;
   //int arr[V][V];
   int arr[V]; //we cannot have variable V since sizeof(class) is compile time and in no way we know size of v
};
int main()
{
  int V = 3;
   int arr[V][V];
}
