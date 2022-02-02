#include <iostream>
#include <set>

int main()
{
  std::set<int>s{1,2,3,4,5};
  for(auto e:s)
  {
    if(e == 3)
      s.erase(0); //erase takes the position and not the element
  }

  for(auto e:s)
  std::cout <<e;


}
