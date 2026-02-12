#include <iostream>

class Complex
{
    public:

    Complex(int real,double img):m_real{real},m_img{img}
    {
    }

    friend Complex operator + (const Complex &c1, const Complex &c2);

    private:
    int m_real {0};
    double m_img {0.0};
};

Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex{c1.m_real + c2.m_real,c1.m_img+c2.m_img};
}

int main()
{

    Complex c1{1,2.0};
    Complex c2{2,3.0};
    Complex c3 {c1 + c2};
}



