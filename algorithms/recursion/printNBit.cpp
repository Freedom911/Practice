//Recursive Program To Generate all prefix of N bit binary number where no of 1 is greater than
//0

#include <iostream>
#include <string>
#include <vector>



//N = Total N bit binary Number
//a = No of 1 added
//b = no of 0 added

void generateStr(int N,int a,int b,std::string op,std::vector<std::string> &out)
{
  //Base Condition
  if(N == 0)
  {
    out.push_back(op);
    return;
  }

  std::string op1 = op + "1",op2 =  op + "0";
  //Now if No of a <= b then generate 1 only. we have one choice
  if(a <= b)
  {
    generateStr(N-1,a+1,b,op1,out);
  }
  //else we have two choices
  else
  {

    generateStr(N-1,a+1,b,op1,out);
    generateStr(N-1,a,b+1,op2,out);
  }
}

std::vector<std::string> getStr(int N)
{
  int a = 0,b = 0;
  std::vector<std::string> o;
  generateStr(N,a,b,"",o);

  return o;
}
int main()
{
  for(auto &v:getStr(5))
  {
    std::cout << v << " ";
  }
}
