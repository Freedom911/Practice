//Virtual inheritance is used in case of diamond inheritance
//i.e
//
//       C   C
//       |   |
//       A   B
//        \ /
//         D
//
// Without Virtual inheritance above will be the diagram
// D will have two copies of C so changing from D will result in ambiguity
//
// Using Virtual Inheritance we change the structure to 
//         C
//        / \
//       A   B
//        \ /
//         D
// So D will have only one copy           

#include <iostream>

class C
{
  public:
  int a;
};

#if 0
class A : public C
{

};

class B : public C
{

};
#else
class A : virtual public C
{

};

class B : virtual public C
{

};
#endif

class D : public A,B
{

};

int main()
{
  D d;
  d.a = 100;
  std::cout << d.a << "\n";
}
