#include <iostream>

// Here's a function template with a static local variable that is modified
template <typename T>
void printIDAndValue(T value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12); //op 1 12
    printIDAndValue(13);//op 2 13

    printIDAndValue(14.5);//op 1 14.5 
    //this is because we will have 2 functions with its own static int

    return 0;
}