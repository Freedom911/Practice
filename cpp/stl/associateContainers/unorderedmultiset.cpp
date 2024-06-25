#include <iostream>
#include <unordered_set>

int main()
{
  std::unordered_multiset<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(3);

  for(auto f : s) 
  {
    std::cout << f << " ";
  }
}
