#include <iostream>
class B1 {
public:
  virtual ~B1() {}
  void f0() {}
  virtual void f1() {}
  int int_in_b1;
};

class B2 {
public:
  virtual ~B2() {}
  virtual void f2() {}
  int int_in_b2;
};

class B3 {
public:
  virtual ~B3() {}
  virtual void f3() {}
  int int_in_b3;
};
class D : public B2,public B1 {
public:
  //void d() {}
  void f2() override {}
  double int_in_d;
};

int main()
{
  std::cout << sizeof(B1) << " " << sizeof(B2) << " " << sizeof(D) <<  "\n";
}
