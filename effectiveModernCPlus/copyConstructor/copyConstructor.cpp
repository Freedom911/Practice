//Program to Show why const is needed
#include <iostream>
class ABC
{
 public:
   ABC()
   {
     std::cout << "\n Default Constructor is getting called \n";
   }
   ABC(const ABC &rhs) 
   {
     std::cout << "\n Without Const Constructor Called \n";
   }
};

//this is copy epsilon
//compiler will optimize and will call default constructor nonly once
ABC foo()
{
  ABC a;
  return a;
}

int main()
{
  ABC d;
  ABC c = foo();
}
