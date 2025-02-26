/**
https://takeuforward.org/graph/word-ladder-i-g-29/

Given are the two distinct words startWord and targetWord, 
and a list denoting wordList of unique words of equal lengths. 
Find the length of the shortest transformation sequence from startWord to targetWord.

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.

Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord = "dfs"
Output:
3
Explanation: 
The length of the smallest transformation sequence from "der" to 
"dfs" is 3 i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’)  -> "dfs". So, it takes 3 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

Solution
Think of these as nodes.
So Basically we pick the starting string and try the brute force by changing each character from a-z
eg der->aer,ber,cer,...zer,dar,dbr,dcr,...dzr,dea,deb,dec,...dez. We add in our queue only if the string
 exists in the list like in queue we will add der initially ,then on changing one letter we can add des
 we simply stop when we reach the target.Also to check if string exists or not we use unordered set.
 and we remove from unordered set on adding to queue as we dont want to loop again like 
 
 der->des->der. To avoid this condition we remove from the unordered set.IN the queue we initially add
 startingWord,1. then on next we increment the counter. at last we return the counter.
 
 We use BFS. we expand level wise. if we use dfs. then we have to keep a counter to min steps to reach target
 and will be more complicated

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

int wordLadderLength(std::string start,std::string target,std::vector<std::string> words)
{
	//Maintain a queue
	std::queue<std::pair<std::string,int>>q; //pair of string and steps
	std::unordered_set<std::string> us(words.begin(),words.end());
	
	if(us.find(target) == us.end())
	{
		std::cout << "\n Not possible \n";
		return -1;
	}
	
	q.push({start,1});
	us.erase(start);
	
	while(q.empty() == false)
	{
		std::string node = q.front().first;
		int steps = q.front().second;
		q.pop();
		
		if(node == target)
		{
			return steps;
		}
		
		//adj nodes are a-z
		for(int i = 0; i < node.size(); i++)
		{
			char original = node[i];
			
			for(char ch = 'a'; ch <= 'z'; ch++)
			{
				node[i] = ch;
				
				//check exits in queue
				if(us.find(node) != us.end())
				{
					us.erase(node);
					q.push({node,steps + 1});
				}
			}
			
			//revert
			node[i] = original;
		}
	}
	
	std::cout << "\n Not possible \n";
	return -1;
}

int main()
{
 
    std::vector<std::string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    std::string startWord = "der", targetWord = "dfs";
 
    
 
    int ans = wordLadderLength(startWord, targetWord, wordList);
 
    std::cout << ans;
    std::cout << std::endl;
    return 0;
}

