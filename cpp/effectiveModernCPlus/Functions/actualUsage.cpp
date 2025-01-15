#include <iostream>
#include <vector>

//Not required to keep global we could use lamda function
int ascComparer(int a,int b)
{
  return a < b ? a:b;
}
int descComparer(int a,int b)
{
  return a > b ? a:b;
}

int mult(int a,int b)
{
  return a*b;
}

void printResult(std::vector<int> elem,int(*func)(int,int))
{
  for(int i = 0; i < elem.size(); i+=2)
  {
    std::cout << "RESULT = " << func(elem[i],elem[i+1]) << " ";
  }
}

int main()
{
  std::vector<int> a {1,2,3,4};

  printResult(a,ascComparer);
  std::cout << "\n\n";
  printResult(a,descComparer);
  std::cout << "\n\n";
  printResult(a,mult);
}
