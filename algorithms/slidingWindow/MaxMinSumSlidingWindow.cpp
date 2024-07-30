//Find Maximum/minimum sum in a array of window size kbhit
//naive approach would be to use 2 loops one for index
//other for k window size. But the work will be repeative
//time complexity O(kn)
//IN sliding window technique we keep moving the window by 
//subtracting the ith element eg 
//1 1 1 2 3. Initially i = 0 and j = 2 . window size is 3
//now we add sum of 4th index and just subtract 0th index
//again we add sum of 5th index and subtract 1st index 
//Time complexity O(n)
#include <iostream>
#include <vector>
#include <limits>

void getMaxMinSum(std::vector<int> v,int k)
{
	int minNo = std::numeric_limits<int>::max();
	int maxNo = std::numeric_limits<int>::min();
	int i = 0;
	int j = 0;
	int sum = 0;
	
	while(j < v.size())
	{
		sum += v[j];
		
		if(j - i + 1 == k)
		{
			//Calculating part
			minNo = std::min(minNo,sum);
			maxNo = std::max(maxNo,sum);
			
			//Sliding Part
			sum -= v[i];
			i++;
			
		}
		j++;
	}
	
	std::cout << "\n Minimum Sum = " << minNo << "\n";
	std::cout << "\n Maximum Sum = " << maxNo << "\n";
}


int main()
{
	int k ;
	std::cout << "\n Window size enter = ";
	std::cin >> k;
	getMaxMinSum({1,1,2,3,-2},k);
}