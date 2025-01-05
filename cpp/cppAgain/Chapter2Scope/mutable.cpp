//mutable allows editing in case the function is const
#include <iostream>

class ABC
{
    public:
    ABC():m_val(3){}
    void Foo() const
    {
        m_val = 100;

        //uncommenting this will give erro
        //m_nonMutable = 2;
    }

    mutable int m_val;
    int m_nonMutable;
};

int main()
{
    ABC c;
    c.Foo();
    std::cout << c.m_val << "\n";

    const ABC constOBJ;
    constOBJ.m_val = 10000;

    std::cout << constOBJ.m_val << "\n";
}
