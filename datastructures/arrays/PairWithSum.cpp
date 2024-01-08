#include <iostream>
#include <vector>
#include <algorithm>
//https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
int findPairsWithLessThanSum(std::vector<int> &v,const int &sum)
{
	int count = 0;
	std::sort(v.begin(),v.end());
	int i = 0,j = v.size() - 1;
	while(i <v.size())
	{
		j = v.size() - 1;
		while(j > i)
		{
		  if(v[i] + v[j] >= sum)
		  {
			  j--;
		  }
		  else
		  {
			  count += j-i;
			  break;
		  }
		}			
		i++;
	}
	return count;
}

int findPairsWithSum(std::vector<int> &v,const int &sum)
{
	int count = 0;
	std::sort(v.begin(),v.end());
	int i = 0,j = v.size() - 1;
	while(i != j)
	{
		if(v[i] + v[j] > sum)
		{
			j--;
		}
		else if(v[i] + v[j] < sum)
		{
			i++;
		}
		else
		{
			std::cout << "\n Pairs = " << v[i] << "," << v[j] << "\n";
			count++;
			i++;
			j--;
		}
	}
	return count;
}

int main()
{
  std::vector<int>v{-3,-1,0,2,-2};
  
  std::cout << findPairsWithLessThanSum(v,0) << "\n";
}