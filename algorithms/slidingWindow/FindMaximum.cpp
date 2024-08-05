//Problem just like sliding window find
//first negative number of window size k
#include <iostream>
#include <vector>
#include <list>

void solve(std::vector<int> v,int k)
{
	int i = 0,j = 0,n = v.size();
	std::list<int>li;
	
	while(j < n)
	{
		
		//Calculation part 
		//We keep pushing in list back.
		//we pop if the list back is smaller than current element
		//as they wont be part of the ans if big bro v[j] is present
		//but if smaller element v[j] comes then we just push back to list
		//as it might be a canditate when we slide and exclude big bros from the window
		while(li.empty() == false && li.back() < v[j])
		{
			li.pop_back();
		}
		li.push_back(v[j]);
		
		//Hitting window size
		if(j-i+1 == k)
		{
			//calculate ans part
			std::cout << li.front() << ",";
			
			//Reverting and sliding
			if(li.front() == v[i])//i is the element to exclude while sliding
			{
				li.pop_front();
			}
			
			i++;
			
		}
		j++;
	}
	
}
int main()
{
	solve({8, 5, 10, 7, 9, 4, 15, 12, 90, 13},4);
}