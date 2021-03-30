//Simple Thread Example
#include <iostream>
#include <thread>

void printString(int threadID,std::string message)
{
  std::cout << "\n Thread = " << threadID << " IS Printing == " << message << "\n";
}

int main()
{
  std::thread th(printString,1,"hello");
  std::thread th1(printString,2,"bye bye");

  th1.join();
  th.join();
  std::cin.get();
}
