//Program To generate Balance Paranethesis given a N

#include <iostream>
#include <string>
#include <vector>

//N is No of parenthesis set
//a is the no of ( parenethesis can use i.e balance Initially equals to N
//b is the no of ) parenethesis can use i.e balance Initially equals to N



void generate(int a,int b,std::string op,std::vector<std::string> &res)
{

  //Base Condition
  if(a == 0 && b == 0)
  {
     res.push_back(op);
     return;
  }

  std::string op1 = op,op2 = op;
  op1.push_back('(');
  op2.push_back(')');


  //will get this choice everytime
  if(a != 0)
  {
    //generate (
    generate(a-1,b,op1,res);
  }

  //means balance of b is more than a.means a is more used 
  if(b > a)
  {
    //generate )
    generate(a,b-1,op2,res);
  }
}

std::vector<std::string> generateStrings(int N)
{
  int a = N,b = N;

  std::vector<std::string> str;
  generate(a,b,"",str);

  std::cout << str.size() << "\n";
  return str;
}


int main()
{

  for(auto &v:generateStrings(3))
  {
    std::cout << v << "\n";
  }
}
