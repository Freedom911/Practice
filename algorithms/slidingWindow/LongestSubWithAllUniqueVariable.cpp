//Just like k unique characters
//here k is not giving
//k will be equal to j - i + 1
//if map.size() == j - i + 1 means all character are unique
#include <iostream>
#include <unordered_map>
#include <string>

int solve(std::string s)
{
	int i = 0, j = 0;
	int winLen = -1;
	std::unordered_map<char,int>us;
	int n = s.length();
	
	while(j < n)
	{
		us[s[j]]++;
		//int k = j - i + 1;
		
		//this condition will never hit us.size() > k
		
		//if map size is equal to substring length means all unqiue
		if(us.size() == j - i + 1)
		{
			winLen = std::max(winLen,j - i + 1);
		}
		//means map is containing repeating character
		else if(us.size() < j - i + 1)
		{
			while(us.size() < j - i + 1)
			{
				us[s[i]]--;
				
				if(us[s[i]] <= 0)
				{
					us.erase(s[i]);
				}
				i++;
			}
		}
		j++;
	}
	return winLen;
}

int main()
{
	std::cout << solve("ABCDEFGABEF") << "\n";
	std::cout << solve("GEEKSFORGEEKS") << "\n";
	std::cout << solve("aa") << "\n";
}