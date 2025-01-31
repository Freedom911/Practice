#include <iostream>

//reference to an array of size n
//the coompliler will try to deduce and will pass size
template<typename T,std::size_t n>
constexpr std::size_t ArraySize(T(&)[n])
{
    return n;
}

int main()
{
   int arr[] = {1,2,3,4,5};

   std::cout << "\n Array Size = " << ArraySize(arr) << "\n";
}
