#include <iostream>
#include <unordered_set>

int main()
{
  std::unordered_set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(3);

  for(auto f : s) 
  {
    std::cout << f << " ";
  }

  //unordered set /or map cannot have vector or pair. we need to provide hash
  //as for unordered we require hashing. for normal results are stored as red black tree which
  //doesnt require hashing
}
