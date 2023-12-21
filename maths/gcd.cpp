//GCD using Eucledian algorithm
//using division
//it states that if we subtract smaller from larger then gcd remains same
//we keep repeating same then at last we get gcd
//we use division here
//gcd(A,B) = gcd(B,R) where R = remainder A = B * Q + R and Q is quotient
//gcd(A,0) = A,gcd(B,0) = B
//then it becomes B = R * Q + R' and so on
//we repeat till R = 0 then gcd is B

#include <iostream>

int gcd(int a,int b)
{ 
    //Means R == 0 then 
	if( a == 0)
	{
		return b;
	}

	            //remainder,new b = a
	return gcd( b % a, a);
}

int main()
{
	std::cout << "GCD of 270 and 192 " << gcd(192,270) << "\n";
	std::cout << "GCD of 270 and 192 " << gcd(270,192);
}