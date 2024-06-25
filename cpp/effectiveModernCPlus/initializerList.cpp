//initializer list can be used to assign value to ref
#include <iostream>
class ABC
{
  public:
    ABC(int i):ref(i){}
    int &ref;
};
int main()
{
  int j = 5;
  ABC c(j);
  std::cout << c.ref << "\n";
}
