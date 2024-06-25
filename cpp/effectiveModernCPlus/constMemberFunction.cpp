//Const Object can only call const member functions
//
#include <iostream>

class ABC
{
  public:
    void foo()
    {
      std::cout << "\n FOO \n";
    }
    void ftoo() const
    {
      std::cout << "\n FtOO \n";
    }
};

int main()
{
 const ABC a;
 a.ftoo();
 ABC aa;
 aa.ftoo();
}
