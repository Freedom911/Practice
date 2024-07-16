//Program To check if a string is a scrambled of another
//To check A string is a scrambled of other string we can make a binary treee and swap the nonleave nodes
//Example
//String str - great
//             /   \
//            gr   eat
//           / \   / \
//          g  r  e  at
//                  / \
//                 a   t

//we can swap non leave nodes children i.e gr,eat,at and great
//String str - rgeat
//             /   \
//            rg   eat
//           / \   / \
//          r  g  e  at
//                  / \
//                 a   t
// rgeat is a scrambled string of great

//To Check for each i = 1 to N - 1 we will match both portion of the two strings
// gr|eat and rg|eat we will match not == but recursivly solve for both the regions
// ALso Great and Great are scrambled. means if str1 == str2 it is scrambled
// we want to reach at base level to check for this == #include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	
	//Hypothesis
	bool isScrambledDP(string s1,string s2,std::unordered_map<std::string,bool> &us)
	{
		int n = s1.length();
		//Base conditions
		if(s1 == s2)
		{
			return true;
		}
		if(n != s2.length())
		{
			std::cout << "\n IS IT\n";
			return false;
		}
		std::string s1_1 = s1;
		std::string s2_1 = s2;
		std::sort(s1_1.begin(),s1_1.end());
		std::sort(s2_1.begin(),s2_1.end());
		//Means different characters
		if(s1_1 != s2_1)
		{
			std::cout << "\n IS IT \n";
			return false;
		}
		
		std::string key = s1 + "_" + s2;
		if(us.find(key) != us.end())
		{
			return us[key];
		}
		

		//choices
		bool bisScrambled = false;
		for(int k = 1; k <= n-1; k++)
		{
			//s1 = a1 + a2
			//s2 = b1 + b2
			std::string a1,a2,b1,b2;
			a1 = s1.substr(0,k);
			a2 = s1.substr(k);
			b1 = s2.substr(0,k);
			b2 = s2.substr(k);
			
			//For case 2
			std::string a11,a21,b11,b21;
			a11 = s1.substr(0,k);
			a21 = s1.substr(k);
			b11 = s2.substr(0,n-k);
			b21 = s2.substr(n-k);
			
			//case 1
			if(isScrambledDP(a1,b1,us) && isScrambledDP(a2,b2,us))
			{
				bisScrambled = true;
				break;
			}
			
			//case 2s	

			else if(isScrambledDP(a11,b21,us) && isScrambledDP(a21,b11,us))
			{
				bisScrambled = true;
				break;
			}
			
		}
			
		return us[key] = bisScrambled;
			
	}
	
    bool isScramble(string s1, string s2) {
        std::unordered_map<std::string,bool> us;
		
		return isScrambledDP(s1,s2,us);
    }
};

int main()
{
	Solution s1;
	std::cout << s1.isScramble("great","rgeat");
}
