/**
 *
 *  https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/
 
	Accounts Merge - DSU: G-50

	Problem Statement: Given a list of accounts where each element account [ i ] is 
    a list of strings, where the first element account [ i ][ 0 ]  is a name, and the 
    rest of the elements are emails representing emails of the account.
	Now, we would like to merge these accounts. Two accounts definitely 
    belong to the same person if there is some common email to both accounts. 
    Note that even if two accounts have the same name, they may belong to 
    different people as people could have the same name. A person can have 
    any number of accounts initially, but all of their accounts definitely have the same name.
	After merging the accounts, return the accounts in the 
    following format: the first element of each account is the name, 
    and the rest of the elements are emails in sorted order.
	Note: Accounts themselves can be returned in any order.
	Pre-requisite: Disjoint Set data structure
	
	Example 1:
	Input: N = 4
	accounts [ ] =
	[["John","johnsmith@mail.com","john_newyork@mail.com"],
	["John","johnsmith@mail.com","john00@mail.com"],
	["Mary","mary@mail.com"],
	["John","johnnybravo@mail.com"]]

	Output: [["John","john00@mail.com","john_newyork@mail.com", "johnsmith@mail.com"],
	["Mary","mary@mail.com"],
	["John","johnnybravo@mail.com"]]

	Explanation: The first and the second John are the same person as they 
    have a common email. But the third Mary and fourth John are not the 
    same as they do not have any common email.  The result can be in any 
    order but the emails must be in sorted order. The following is also a valid result:
	[['Mary', 'mary@mail.com'],
	['John', 'johnnybravo@mail.com'],
	['John', 'john00@mail.com' , 'john_newyork@mail.com', 'johnsmith@mail.com' ]]
	
	
	Solution - So common sense approach would be to have an unordered map with email id to index mapping
	eg John : J1,J2,J3
	so we will have J1->0,J2->0,J3->0
	Now if another entry comes with same email like
	John : J4,J2
	J4->1
	But J2 is already in map so we say both 1 and 0 needs to be merged. so we use disjoint set concept
	
	so in 1st iteration we loop through all enteries and build the unordered map. we will merge set number
	if common email.
	IN 2nd iteration we will find the ultimate parent of each set so that to create vector of this
	0->J1,J2,J3,J4
	1->M1...
	As you can see J4 is also merged to 0. 
	3rd iteration would simply add in answer
	
	If we didn't knew Disjoint set then we would have kept two unordered map
	1st unordered map stores email->id
	2nd unordered map stores childID->parent Id
	
	but this will be expensive as we would have cases like
	9->8->4->2->1->0 were we have to linear jump from 9 to 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class DisjointSet
{
	public:
	std::vector<int>IsPartOf,Size;
	DisjointSet(int n)
	{
		IsPartOf.resize(n,0);
		Size.resize(n,1);
		for(int i = 0;i < n; i++)
		{
			IsPartOf[i] = i;
		}
	}
	
	int findUPar(int u)
	{
		if(u == IsPartOf[u])
		{
			return u;
		}
		
		return IsPartOf[u] = findUPar(IsPartOf[u]);//Path compression
	}
	
	bool UnionBySize(int u,int v)
	{
		int setV = findUPar(v);
		int setU = findUPar(u);
		if(setU == setV)
		{
			return false;//no need to merge
		}
		
		if(Size[setV] > Size[setU])
		{
			//merge set u with set v
			Size[setV] += Size[setU];
			IsPartOf[setU] = setV;
		}
		else
		{
			Size[setU] += Size[setV];
			IsPartOf[setV] = IsPartOf[setU];
		}
		return true;
	}
};

std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts)
{
	if(accounts.size() == 0)
	{
		return {};
	}
	DisjointSet ds(accounts.size());
	
	//1st iteration create unordered map
	std::unordered_map<std::string,int> us;
	for(int i = 0; i < accounts.size(); i++)
	{
		for(int j = 1; j < accounts[i].size(); j++)
		{
			if(us.find(accounts[i][j]) == us.end())
			{
				us[accounts[i][j]] = i;
			}
			else
			{
				//we try to merge the setstate
				ds.UnionBySize(us[accounts[i][j]],i);
				
			}
		}
	}
	
	//2nd loop to get in intermediate list
	//map email to their respective id
	//0->j1,j2,j3
	int n = accounts.size();
	std::vector<std::string> inter[n];

	for(auto it : us)
	{
		std::string email = it.first;
		int index = it.second;
		//find Ultimate parent to get to correct position 
		int up = ds.findUPar(index);
		inter[up].push_back(email);
	}
	
	//3d loop for answer
	std::vector<std::vector<std::string>> res;
	for(int i = 0;i < n; i++)
	{
		if(inter[i].size() == 0)
		{
			continue;
		}
		std::vector<std::string> temp;
		std::sort(inter[i].begin(),inter[i].end());
		temp.push_back(accounts[i][0]);
		
		temp.insert(temp.end(),inter[i].begin(),inter[i].end());
		res.push_back(std::move(temp)); //move to avoid copying
	}
	return res;
	
}
int main() {

    std::vector<std::vector<std::string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };


    
    std::vector<std::vector<std::string>> ans = accountsMerge(accounts);
    for (auto acc : ans) {
        std::cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            std::cout << acc[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
#if 0
Output:

John:j1@com j2@com j3@com j5@com
John:j4@com
Mary:m1@com
Raj:r1@com r2@com r3@com
#endif
