#include <iostream>

class Complex
{
    public:

    Complex(int real,double img):m_real{real},m_img{img}
    {
    }

    //prefix increment
    Complex & operator ++()
    {
        ++m_real;
        return *this;
    }

    //postfix
    Complex operator ++(int)
    {
        Complex C2{*this};
        ++m_real;
        return C2;
    }

    friend std::ostream &operator << (std::ostream &out,const Complex &rhs)
    {
        out << rhs.m_real << " " << rhs.m_img << "\n";
        return out;
    }
    


    private:
    int m_real {0};
    double m_img {0.0};
};


int main()
{

    Complex c1{1,2.0};
    c1++;
    ++c1;
    
    std::cout << c1 << "\n";
}



