//Dynamic Cast is a runtime cast which downcasts object safely
//One example would be lets say a vector is containing a base pointer
//for all widget now since we dont have info we want a box widget to be moved
//so we will cast base class i.e convert base class to dervided. we use dnamic cast 
//need astleast one virtual func
#include <iostream>
class A
{
 public:
   virtual void a() //if not virtual we get error poloymorphic
   {

   }
};
class B:public A
{

};
int main()
{
  A *a = new B;
  B *b = dynamic_cast<B*>(a);
}
