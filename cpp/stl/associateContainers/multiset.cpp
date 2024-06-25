#include <iostream>
#include <set>

int main()
{
  std::multiset<int,std::greater<int>> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(3);

  for(auto f : s) 
  {
    std::cout << f << " ";
  }

  //practical use case
  std::multiset<std::string> s1;
  s1.insert("cpu");
  s1.insert("cpu");
  s1.insert("RAM");
  s1.insert("RAM");
  s1.insert("RAM");

  std::cout << "\n TOTAL CPU in cart = " << s1.count("cpu") << " and total no of rams " << s1.count("RAM") << "\n";
}
