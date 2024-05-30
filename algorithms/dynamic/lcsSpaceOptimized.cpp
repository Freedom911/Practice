#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //Lets use space optimized LCS
		//because  we require only previous row result from table
		int n = text1.size();
		int m = text2.size();
		
		int t[2][m+1];
		std::memset(t,0,sizeof(t));
		
		for(int i = 1; i < n + 1; i++)
		{
			for(int j = 1; j < m + 1; j++)
			{
				if(text1[i-1] == text2[j-1])
				{
					t[1][j] = 1 + t[0][j-1];
				}
				else
				{
					t[1][j] = std::max(t[0][j],t[1][j-1]);
				}
				
			}
			
			//for(int j = 0; j < m + 1; j++)
			{
				//t[0][j] = t[1][j];
			}
			memmove(&t[0],&t[1],(m+1)* sizeof(int));
		}
		return t[1][m];
    }
};
//printing space optimized lcs is not possible
int main()
{
	Solution s;
	std::string a = "abcde";
	//std::string 
	std::cout << s.longestCommonSubsequence("bsbininm","jmjkbkjkv");
}
