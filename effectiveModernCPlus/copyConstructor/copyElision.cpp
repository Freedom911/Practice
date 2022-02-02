//Program to Show copy elision
//-fno-elide-constructors
#include <iostream>
class ABC
{
 public:
   ABC()
   {
     std::cout << "\n Default Constructor is getting called \n";
   }
   ABC(ABC &rhs) 
   {
     std::cout << "\n Without Const Constructor Called \n";
   }
};

//this is copy epsilon
//compiler will optimize and will call default constructor nonly once
ABC foo()
{
  return ABC();
}

int main()
{
  ABC c = foo();
}
