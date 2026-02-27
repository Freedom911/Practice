#include <iostream>

class Complex
{
    public:

    Complex(int real,double img):m_real{real},m_img{img}
    {
    }

    friend std::ostream& operator << (std::ostream &out,const Complex &rhs)
    {
        out << rhs.m_real << " " << rhs.m_img << "\n";
        return out;
    }
    friend std::istream& operator >> (std::istream &in, Complex &rhs)
    {
        in >> rhs.m_real ;
        in >> rhs.m_img ;
        return in;
    }


    private:
    int m_real {0};
    double m_img {0.0};
};


int main()
{

    Complex c1{1,2.0};
    Complex c2{2,3.0};
    Complex c3{0,0};
    std::cin >> c3;
    std::cout << c1;
    std::cout << c2;
    std::cout << c3;
}



