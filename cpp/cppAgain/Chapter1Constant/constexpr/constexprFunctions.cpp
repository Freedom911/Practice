#include <iostream>

//ConstExpr must accept and take only literal types whose storage is
//already known. Following will give no trival destructor

//constexpr std::string accepter(std::string str)
//{
//  return "avd";
//}


//ConstExpr can only call constexpr functions 
//i.e even cout will give error since it is not constexpr
constexpr int what()
{
  //std::cout << "\n Hello";
  return 3;
}

//Body Cant have goto or try catch
// with c++ 20 we can have try -std=gnu++2a
constexpr void exec()
{
  const int i = 0;

//  try
  {
     i/i;
  }
 // catch(...)
  {

  }
}

//No static Variables in constexpr
//will give error error: ‘j’ declared ‘static’ in ‘constexpr’ function
constexpr int nostaticer()
{
  const int i = 4;

  //static int j = 6;
  return i;
}


int main()
{
  what();
  std::string str;
  //accepter(str);
  exec();
  nostaticer();

}

