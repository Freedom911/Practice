#include <iostream>
#include <string>

int foo(std::string str)
{
	std::cout << str << "\n";
	return 3; //prvalue
}

int main()
{

	//glvalue is lvalue + xvalue

	//lvalue
	int a = 3;
	std::string abc = "foo";
	std::string dfg = abc; //abc is lvalue and so is dfg
	foo(abc);//lvalue
	

	//rvalue is prvalue + xvalue
	//prvalue
	foo(std::string("abc"));


	//xvalue
	foo(std::move(abc));

	std::string {"asd"} = dfg; //assigning value to prvalue and the value will be discarded

	std::cout << "\n" << dfg << "\n";



}
