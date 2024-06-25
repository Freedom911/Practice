// ConstExpr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Complex
{
public:
    constexpr Complex(float R,float I):Real(R),Imaginary(I){}
    //destructor cannot be Constexpr
     ~Complex() {}

    Complex operator + (Complex const& obj)
    {
        Complex res(0,0);
        res.Imaginary = Imaginary + obj.Imaginary;
        res.Real = Real + obj.Real;
        return res;
    }

    void Display()
    {
        std::cout << Real << "," << Imaginary << "\n";
    }

private:
    float Real;
    float Imaginary;
};

int main()
{
    Complex c1(3, 4);
    Complex c2(4, 3);

    Complex c3 = c1 + c2;

    c3.Display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
