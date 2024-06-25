#include <iostream>
#include <set>

int main()
{
  std::set<int,std::greater<int>> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(3);

  for(auto f : s) 
  {
    std::cout << f << " ";
  }
}
