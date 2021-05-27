//Program To Case change a string
//Example ab
//OUTPUT ab,aB,Ab,AB
//Will use recursion Tree. Here at each step we can either conver tto upper or leave
#include <iostream>
#include <string>

void printStr(std::string in,std::string op)
{
  if(in.size() == 0)
  {
    std::cout << op << "\n";
    return;
  }

  std::string op1 = op;
  std::string op2 = op;

  //op2 will be upper case
  op2 += std::toupper(in[0]);
  op1 += in[0];

  in.erase(in.begin() + 0);

  printStr(in,op1);
  printStr(in,op2);

}

int main()
{
  printStr("ab","");
}
