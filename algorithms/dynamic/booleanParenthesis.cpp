//Boolean parenthesis problem
//Get total no of ways of placing brackets such that the expressino is true
//T XOR F AND T - (T XOR F) AND T - 1
//T XOR (F AND T) - 2
//2 ways
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

//Hypothesis
int GetTotal(std::string str,int i,int j,bool evaluate)
{
	//Base condition
	if(i == j) //means only one char
	{
		if(evaluate == true)
		{
			
			return str[i] == 'T' ? 1:0;
		}
		else
		{
			return str[i] == 'F' ? 1:0;
		}
	}
	
	//Choices
	int ans = 0;
	for(int k = i + 1; k <= j- 1; k+=2)
	{
		//1. and operation
		if(str[k] == '&')
		{
			if(evaluate == true) //LeftTrue * RightTrue
			{
				ans += (GetTotal(str,i,k-1,true) * GetTotal(str,k+1,j,true));
			}
			else
			{
				//to get false in and we can do
				//Lf*Rf + Lt*Rf + Lf*Rt

				ans += (GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,true)) +
				        (GetTotal(str,i,k-1,true) * GetTotal(str,k+1,j,false)) +
						(GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,false));
			}
			
		}
		
		//2. OR operation
		if(str[k] == '|')
		{
			if(evaluate == true)
			{
				//LeftTrue * RightTrue + LeftFalse * RightTrue + 
				//LeftTrue * RightFalse
				ans += (GetTotal(str,i,k-1,true) * GetTotal(str,k+1,j,true)) +
				        (GetTotal(str,i,k-1,true) * GetTotal(str,k+1,j,false)) +
						(GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,true));
				
			}
			else
			{
				//LeftFalse * Right False
				ans += (GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,false));
			}
		}
		
		//3. XOR operation
		if(str[k] == '^')
		{
			if(evaluate == true)
			{
				//LeftTrue * Right False + LeftFalse * RightTrue + 
				ans += (GetTotal(str,i,k-1,'T') * GetTotal(str,k+1,j,false)) +
				        (GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,true));
				
			}
			else
			{
				//LeftFalse * Right False + LeftTrue * RightTrue
				ans += (GetTotal(str,i,k-1,false) * GetTotal(str,k+1,j,false)) + 
					   (GetTotal(str,i,k-1,true) * GetTotal(str,k+1,j,true));
			}
		}
		
	}
	
	return ans;
}

std::unordered_map<std::string,int> us;
//Hypothesis
int GetTotalDP(std::string str,int i,int j,bool evaluate)
{
	//Base condition
	if(i == j) //means only one char
	{
		if(evaluate == true)
		{
			
			return str[i] == 'T' ? 1:0;
		}
		else
		{
			return str[i] == 'F' ? 1:0;
		}
	}
	
	std::ostringstream out;
	out << i << "_" << j << "_" << evaluate;
	std::string key = out.str();
	if(us.find(key) != us.end())
	{
		return us[key];
	}
	//Choices
	int ans = 0;
	for(int k = i + 1; k <= j- 1; k+=2)
	{
		//1. and operation
		if(str[k] == '&')
		{
			if(evaluate == true) //LeftTrue * RightTrue
			{
				ans += (GetTotalDP(str,i,k-1,true) * GetTotalDP(str,k+1,j,true));
			}
			else
			{
				//to get false in and we can do
				//Lf*Rf + Lt*Rf + Lf*Rt

				ans += (GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,true)) +
				        (GetTotalDP(str,i,k-1,true) * GetTotalDP(str,k+1,j,false)) +
						(GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,false));
			}
			
		}
		
		//2. OR operation
		if(str[k] == '|')
		{
			if(evaluate == true)
			{
				//LeftTrue * RightTrue + LeftFalse * RightTrue + 
				//LeftTrue * RightFalse
				ans += (GetTotalDP(str,i,k-1,true) * GetTotalDP(str,k+1,j,true)) +
				        (GetTotalDP(str,i,k-1,true) * GetTotalDP(str,k+1,j,false)) +
						(GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,true));
				
			}
			else
			{
				//LeftFalse * Right False
				ans += (GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,false));
			}
		}
		
		//3. XOR operation
		if(str[k] == '^')
		{
			if(evaluate == true)
			{
				//LeftTrue * Right False + LeftFalse * RightTrue + 
				ans += (GetTotalDP(str,i,k-1,'T') * GetTotalDP(str,k+1,j,false)) +
				        (GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,true));
				
			}
			else
			{
				//LeftFalse * Right False + LeftTrue * RightTrue
				ans += (GetTotalDP(str,i,k-1,false) * GetTotalDP(str,k+1,j,false)) + 
					   (GetTotalDP(str,i,k-1,true) * GetTotalDP(str,k+1,j,true));
			}
		}
		
	}
	
	return us[key] = ans;
}


int main()
{
	std::string str = "T^F&T";
	
	std::cout << GetTotal(str,0,str.length() - 1,true) << "\n";
	
	std::cout << "DP VERSINO = " << GetTotalDP(str,0,str.length() - 1,true) << "\n";
	
}