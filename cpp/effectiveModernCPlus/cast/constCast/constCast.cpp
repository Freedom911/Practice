#include <iostream>
class A
{
  int roll = 5;
  
  public:
  void foo() const
  {
	  (const_cast<A*>(this))->roll = 6;
  }
  
  int getRoll(){return roll;}
};

int value(int *ptr)
{
	return (*ptr + 20);
}

int valueMod(int *ptr)
{
	*ptr = *ptr + 10;
	return *ptr;
}

int main()
{
	//1 Modying value in const function
	A a;
	std::cout << "\n Before = " << a.getRoll() << "\n";
	a.foo();
	std::cout << "\n After = " << a.getRoll() << "\n";
	
	const int abc = 10;
	//std::cout << value(&abc) << "\n"; Error
	std::cout << value(const_cast<int*>(&abc)) << "\n";
	
	std::cout << valueMod(const_cast<int*>(&abc)) << "\n";//Undefined
}
