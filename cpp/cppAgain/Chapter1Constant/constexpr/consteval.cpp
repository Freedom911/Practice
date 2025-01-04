//compile with -std=c++20
#include <iostream>


consteval int fib(int n)
{
    return n <= 1 ? 1: fib(n-1) + fib(n-2);
}

int main()
{
    int x = 3;
    //will giver error
    //int j = fib(x);
    int j = fib(3);
}
