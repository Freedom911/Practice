#include <iostream>
int main()
{
  //They all are same
  int i = 3;
  int j (4);
  int k {5};
  int l = { 6};

  auto ii = 3;
  auto jj(4);
  auto kk{5};  //These Two will be treated as initailzer List
  auto ll = {6};

  std::cout << *ll.begin() << "\n";

}
