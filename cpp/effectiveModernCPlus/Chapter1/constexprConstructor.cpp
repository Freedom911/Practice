#include <iostream>

class Fruit
{

};

//This will give error It should not have virtual base class
class Apple// : virtual public Fruit
{
  public:

  //For Constxpr intiailziation only allowed through initiallizer list
  //If constexpr declared then every member must be initialized
  constexpr Apple(int i):count(i)
  {
  }

  void display() const
  {
    std::cout << "Total APples = " << count << "\n";
  }
  private:
  int count;
  //int a; On Uncommenting this will give error
};

int main()
{
  Apple a(3);

}
