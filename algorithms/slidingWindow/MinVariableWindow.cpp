//Find minimum Variable window length
//which contains word  in the pattern.
//ccan inclide other letters. if maximum was asked
//we would have used LCS.
//this is like anagram occurence
#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

std::string solve(std::string pattern,std::string word)
{
	 std::unordered_map<char,int>us;
	 
	 for(int i = 0; i < word.length(); i++)
	 {
		 us[word[i]]++;
	 }
	 
	 int i = 0,j = 0,winLength = std::numeric_limits<int>::max();
	 int count = us.size(),start = -1;
	 int n = pattern.length();
	 
	 while(j < n)
	 {
		 if(us.find(pattern[j]) != us.end())
		 {
			 us[pattern[j]]--;
			 if(us[pattern[j]] == 0)
			 {
				 count--;
			 }
		 }
		 
		 //now if covered all letters of word then we want to find minimum
		 //so we increment i till the count == 0
		 //as the map would become negative if more than desired character present
		 if(count == 0)
		 {
			 while(count == 0)
			 {
				 if(us.find(pattern[i]) != us.end())
				 {
					us[pattern[i]]++;
					if(us[pattern[i]] == 1)
					{
						count++;
						
						if(winLength > j - i + 1)
						{
							winLength = j - i + 1;
							start = i;
						}
						
					}

				}
				i++;
				 
			 }
		 }
		 j++;
	 }
	 
	 if( start == -1)
		 return "";
	 
	 return pattern.substr(start,winLength);
}

int main()
{
	std::cout << solve("ADOBECODEBANC","ABC") << "\n";
	std::cout << solve("a","a") << "\n";
	std::cout << solve("a","aa") << "\n";
}

