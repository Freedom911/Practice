//Find maximum length of substring with k unique characters
//Variable window size
//Concept like count occurrence of anagrams where we maintained unordered map
//unordered map will store unique characters
#include <iostream>
#include <string>
#include <unordered_map>

//K represent sunique characters
int solve(std::string s,int k)
{
	//FOllowing general Format of variable size window
	int i = 0,j = 0,n = s.size(), maxWindowLength = -1;
	std::unordered_map<char,int>us;
	
	while(j < n)
	{
		us[s[j]]++;
		
		//general format
		
		//means we have not got k unique letters till now so keep including
		if(us.size() < k)
		{
			j++;
		}
		
		else if(us.size() == k)// we have got the desired unique characters
		{
			//j-i+1represents window length
			maxWindowLength = std::max(maxWindowLength,j - i + 1);
			j++;
		}
		
		else if(us.size() > k)//we have got more unique characters than desired so we remove
		{
			while(us.size() > k)
			{
				us[s[i]]--;
				
				if(us[s[i]] <= 0)//means we no occurrence left in our window so we remove 
				{
					us.erase(s[i]);
				}
				i++;
			}
			
			j++;
		}
	}
	
	return maxWindowLength;
}

int main()
{
	std::cout << solve("aaabbb",1);
}