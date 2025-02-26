/**
https://takeuforward.org/graph/g-30-word-ladder-ii/
G-30 : Word Ladder-II



Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
Note: Please watch the previous video of this series before moving on to this particular problem as this is just an extension of the problem Word Ladder-I that is being discussed previously. The approach used for this problem would be similar to the approach used in that question.

Examples:

Example 1:
Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
[ [ “der”, “dfr”, “dfs” ], [ “der”, “des”, “dfs”] ]
Explanation: 
The length of the smallest transformation sequence here is 3.
Following are the only two shortest ways to get to the targetWord from the startWord :
"der" -> ( replace ‘r’ by ‘s’ ) -> "des" -> ( replace ‘e’ by ‘f’ ) -> "dfs".
"der" -> ( replace ‘e’ by ‘f’ ) -> "dfr" -> ( replace ‘r’ by ‘s’ ) -> "dfs".

Example 2:
Input:
startWord = "gedk", targetWord= "geek"
wordList = {"geek", "gefk"}
Output:
[ [ “gedk”, “geek” ] ]
Explanation: 
The length of the smallest transformation sequence here is 2.
Following is the only shortest way to get to the targetWord from the startWord :
"gedk" -> ( replace ‘d’ by ‘e’ ) -> "geek".


Solution - Hmmm
We obviosuly gone use previous knowledge of Word Ladder 1

So the core concept is same we keep changing each character one by one. We use BFS like previous problem

Now next thing
there can be more than one answers as expected. out of all the ansers we have to pick the min only.
Also key thing to note is to know that the minimum value will be found at the same level only

eg

Words= [pat,bot,pot,poz,coz]

start - bat
target - coz

ans
- bat,pat,pot,poz,coz
- bat,bot,pot,poz,coz 

We dont remove word as soon as we get. why?
because if we had done then we had got only one answer that is bat,pat,pot,poz,coz.
pot ate h remove ho jata unordered set se we wouldnt have got the result.

We remove when we explore the full level consiting of pot why?

because lets say we have some sequence bat,pat,pot,poz,coz and another sequence
aat,cat,bat,pat,pot,poz,coz. then we have to pick the minimum only. if pot comes later that is 
after a particular level it was discovered first then we dont need to consider it as its 
length will be greater

in other words if pot is fully explored in a level then for future things if pot comes
the length will be greater than 1st discovered.

The minimum exists on a single level. In other words the length of shortest paths for answer
will alwasy be same

In queue we store the sequence
like initially q-> {bat}
then q->{bat,pat},{bat,bot}

we take the front of queue and pick the last word and we apply the logic of changing each character
and checking in unordered set. after each level we remove the last word from unodered set because
we wont need them in future as they are already present in minimum answer. if they come later then
this means they are not minimum so we remove.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>



std::vector<std::vector<std::string>> findSequences(std::string start,std::string target,std::vector<std::string> words)
{
	std::queue<std::vector<std::string>> q;
	std::unordered_set<std::string> us(words.begin(),words.end());
	std::vector<std::vector<std::string>> res;
	bool ansFound = false;
	
	if(us.find(target) == us.end())
	{
		std::cout << "\n Not Possible \n";
		return res;
	}
	q.push({start});
	us.erase(start);// no need to include the start again
	
	while(q.empty() == false)
	{
		//explore a level fully
		int numberOfChildren = q.size();
		std::vector<std::string> usedOnLevel;
		for(int i = 0; i < numberOfChildren; i++)
		{
			
			std::vector<std::string> seq = q.front();
			std::string lastWord = seq.back();
			
			q.pop();
			
			if(lastWord == target) //found the answer dont quit.continue for next answer
			{
				
				res.push_back(seq);
				ansFound = true;
				continue;
			}
			
			//if it comes here means we have move to seq which is not in the answer
			//then we need to return and not move forward
			if(ansFound == true) 
			{
				return res;
			}
			
			//now apply word ladder 1
			for(int j = 0; j < lastWord.size(); j++)
			{
				char original = lastWord[j];
				
				
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					
					lastWord[j] = ch;
					if(us.find(lastWord) != us.end())
					{

						
						//include in queue
						seq.push_back(lastWord);
						q.push(seq);
						usedOnLevel.push_back(lastWord);
						seq.pop_back(); //remove from the seq. to add new words in other words revert
					}
					
				}
				lastWord[j] = original;
			}
			
			
		}
		
		//now remove from the unordered set which we got in this level
		for(std::string s: usedOnLevel)
		{
			us.erase(s);
		}
		
	}
	return res;
	
}

bool comp(std::vector<std::string> a, std::vector<std::string> b)
{
    std::string x = "", y = "";
    for (std::string i : a)
        x += i;
    for (std::string i : b)
        y += i;

    return x < y;
}

int main()
{

    //std::vector<std::string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    //std::string startWord = "der", targetWord = "dfs";
	

	
	    std::vector<std::string> wordList = {"pat", "bot", "pot", "poz", "coz"};
    std::string startWord = "bat", targetWord = "coz";





//- bat,pat,pot,poz,coz
//- bat,bot,pot,poz,coz 
    
    std::vector<std::vector<std::string>> ans = findSequences(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        std::cout << -1 << std::endl;
    else
    {
       // std::sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                std::cout << ans[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}




