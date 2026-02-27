//By Default array is decayed to pointer
//to prevent this we can pass by reference
#include <iostream>

void foo(int arr[5])
{
    std::cout << sizeof(arr) << "\n";
}


void loo(int (&)arr[5])
{
    std::cout << sizeof(arr) << "\n";
}

int main()
{
   int arr[] = {1,2,3,4,5};
   foo(arr);
   loo(arr);

}
