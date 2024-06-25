#include <iostream>

class A;

class B
{
  public:
    B()
    {
      b = 5;
    }
  private:
    int b;
  friend class A;
};

class A
{
  public:
    void show()
    {
      B ba;
      std::cout << "\n This is A friend class of B = " << ba.b << "\n";
    }
};

int main()
{
  A a;
  a.show();
}
