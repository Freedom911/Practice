#include <iostream>

void recursionTest(int p,int r)
{
  std::cout << p << " " << r << "\n";
  if(p <  r)
   {
    int q = (p + r) / 2;
    recursionTest(p,q);
    recursionTest(q+1,r);
    std::cout << "\n FINLL from " << p << " to " << q << "to " << r << "\n";
   }
}

int main()
{
  recursionTest(0,1);
}
