#include <iostream>
using namespace std;
  
class Test {
    int x;
    int& ref;
  
public:
    Test(int i)
        : x(i)
        , ref(i)
    {
    }

    Test &operator=(const Test&obj)
    {
      x = obj.x;
      ref = obj.ref;
      return *this;
    }

    void print() { cout << ref; }
    void setX(int i) { x = i; }
};
  
// Driver Code
int main()
{

    Test t1(10);
    Test t2(20);
    t2 = t1;
    t1.setX(40);
    t2.print();
    return 0;
}
