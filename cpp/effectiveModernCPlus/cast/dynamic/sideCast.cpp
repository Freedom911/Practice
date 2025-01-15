#include <iostream>

class A
{
	public:
	virtual void foo(){}
};

class B
{
};

class C: public A,public B
{
};

int main()
{
	A * a = new C;
	B *b = dynamic_cast<B*>(a);//static cast will give error
	
	if(b == nullptr)
	{
		std::cout << "\n Side Cast Failed \n";
	}
    else
    {
        std::cout << "\n Side Cast Passed \n"; //this will happen
    }

		
}
