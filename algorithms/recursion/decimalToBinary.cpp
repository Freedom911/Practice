//Recursion Program to print Binary Numbers
//we use IBH method
#include <iostream>


//Hypothesis. This function will print Binaary for decimal number
void PrintBinary(int number)
{
	//Base step
	//means we get 1 and 0 which comes at last of division in decimal to binary
	if(number <= 1) 
	{
		std::cout << number;
		return;
	}
	
	//Induction
	int rem = number % 2;
	//This will print binary of number/2 
	PrintBinary(number/2);
	//now we print the remainder of number
	//meaning initially we had 7 then PrintBinary(3)
	//and at last we print 
	std::cout << rem;
	
}

int main()
{
	std::cout << "Binary of 7 ";
	PrintBinary(7);
	std::cout << "\nBinary of 8 ";
	PrintBinary(8);
	std::cout << "\n";
}