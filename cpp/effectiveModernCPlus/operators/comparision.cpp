#include <iostream>

class Complex
{
    public:

    Complex(int real,double img):m_real{real},m_img{img}
    {
    }
    
    //same for > < >= <= !=
    friend bool operator == (const Complex &c1, const Complex &c2)
    {
        if(c1.m_real == c2.m_real && std::abs(c1.m_img-c2.m_img) <= 1e-9)
        {
            return true;
        }
        return false;
    }


    private:
    int m_real {0};
    double m_img {0.0};
};


int main()
{

    Complex c1{1,2.0};
    Complex c2{1,2.0};
    
    if(c1 == c2)
    std::cout << "Equal \n";
}



