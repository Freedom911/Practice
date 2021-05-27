//Given a string ABC generate strings which have space in between
//Example A_BC,AB_C,ABC,A_B_C. Will Use Recursion Tree
//Notice For Starting Element there is no space also for last
//We will take decision at each input whether to include space at left side or not

//         IN = ABC OP = ''
// 1st IN = BC OP = A
// then INCLUDE SPACE FOR B or not
//2nd a IN = C,OP = A_B or IN=C,OP=AB

#include <iostream>
#include <string>

void printString(std::string in,std::string op)
{
  //BASE CONDITION
  if(in.length() == 0)
  {
    std::cout << op << "\n";
    return;
  }
  
  std::string op1 = op;
  std::string op2 = op;

  op1 +=  (std::string)"_" + (char)in[0];
  op2 += in[0];


  in.erase(in.begin() + 0);
  printString(in,op1);
  printString(in,op2);

}

int main()
{
  std::string in = "ABCD";

  //for A we have fixed result that wont have space on left. so we are preprocessing it

   printString("BCD","A");
}
