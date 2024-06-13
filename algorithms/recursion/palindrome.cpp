//Recursion Program to check if a string is palindrome
//we use IBH method
//we reduce input from both end
#include <iostream>


//Hypothesis. This function will check if a string is palindrome or not
bool IsPalindrome(std::string s,int i,int j)
{
	//Base conditions
	if(i == j)
	{
		return true;
	}
	
	char a = s[i];
	char b = s[j];
	
	if(a != b)
	{
		return false;
	}
	
	//Induction step
	return IsPalindrome(s,i+1,j-1);
}


int main()
{
	std::string s = "nitin";
	std::cout << "\n Is string nitin palindrom = " << IsPalindrome(s,0,s.length() - 1) << "\n";
	s = "aba";
	std::cout << "\n Is string abad palindrom = " << IsPalindrome(s,0,s.length() - 1) << "\n";
}