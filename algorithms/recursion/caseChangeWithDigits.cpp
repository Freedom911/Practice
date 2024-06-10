//Program To Case change a string with mixed case as input. Also has digits
//Example a1B
//OUTPUT a1b,a1B,A1b,A1B
//Will use recursion Tree. Here at each step we can either conver tto upper or leave

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

void solve(std::string inp,std::string out)
{
  if(inp.size() == 0)
  {
	  
	  std::cout << out << "\n";
	  return;
  }
  
  char ch = inp[0];
  if(std::isalpha(ch))
  {
	  //Two choices are there
	  std::string op1 = out + (char)tolower(ch);
	  std::string op2 = out + (char)toupper(ch);
	  
	  inp.erase(inp.begin());
	  
	  solve(inp,op1);
	  solve(inp,op2);
  }
  else
  {
	  //No Choice
	  std::string op1 = out + ch;
	  inp.erase(inp.begin());
	  solve(inp,op1);
  }
}

int main()
{
	std::string str = "a1B";
	std::string out;
	solve(str,out);
}