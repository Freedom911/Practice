
#include <iostream>

/**
 * 
 * y this specific syntax?T (&):
 *  We are passing the array by reference. If we passed it by value (e.g., T[]), 
 * it would "decay" into a pointer (T*), and pointers do not carry size information.
 * [N]: This tells the compiler to look at the size of the array being passed.
 * std::size_t N: This is the "magic" part. The compiler automatically deduces the value of N 
 * based on the array you provide.constexpr: This ensures that 
 * the size can be used at compile-time (like for another array's size).
 */
template<typename T,std::size_t N>
constexpr std::size_t GetSize(T (&)[N])
{
    return N;
}


int main()
{
     int array[10];
     std::cout << GetSize(array);
}