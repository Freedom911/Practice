#include <iostream>

template<typename T>
void MySwap(T &a, T &b)
{
    T temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
    int a = 3,b = 4;
    MySwap<int>(a,b);
    std::cout << a << " " << b << "\n";
}