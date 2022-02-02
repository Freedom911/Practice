//splitting string using stringstream
#include <iostream>
#include <sstream>

void splitString(const std::string &str,const char &delimiter)
{
  std::string temp;
  std::stringstream s(str);
  while(getline(s,temp,delimiter))
  {
    std::cout << temp << "\n";
  }

}
int main()
{
  std::string str = "hello,machu naam,srajan";
  char del = ',';
  splitString(str,del);
}

