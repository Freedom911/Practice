//explicit keyword is used to prevent unwanted implicit conversion
#include <iostream>

class A
{
  public:
    A(int j)
    {
      std::cout << "\n This is A constructor = " << j << "\n";
    }
};



class B
{
  public:
    explicit B(int j)
    {
      std::cout << "\n This is B constructor = " << j << "\n";
    }
};

int main()
{
 A c = 1; //this will be converted to A c = A(1) i.e implicit conversion
// B b = 1; // this will give error
 B b = B(1);//this works
}
