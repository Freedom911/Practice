/**
 * R Value Reference
 */

#include <iostream>


void fun(const int& lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const: " << lref << '\n';
}


void fun(int&& rref) // r-value arguments will select this function
{
	std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
    int a {3};
    int &b{a};
    //Rref cannot be initialized with lvalue? Y u ask?
    //saftey feature and this may cause lvalue to be destoryed
    //int &&rRef{a};//not compilable

    //Rvalue reference variables are lvalues
    int &&ref{3};
 
    std::cout << ref << "\n";

    fun(ref);//this calls const one because it behaves as lvalue now as it is named
}