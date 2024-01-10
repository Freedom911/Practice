#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v{-2,100,2,3,4,4,1000,20000,-1,-343333};
	
	std::vector<int>::iterator maxIter = std::max_element(v.begin(),v.end());
	
	std::vector<int>::iterator minIter = std::min_element(v.begin(),v.end());
	
	std::cout << "\n Min Element = " << *minIter << ", Found at = " << std::distance(v.begin(),minIter) << "\n";
	
	std::cout << "\n Max Element = " << *maxIter << ", Found at = " << std::distance(v.begin(),maxIter) << "\n";
	
	
	std::pair<std::vector<int>::iterator,std::vector<int>::iterator> minMaxPair;
	minMaxPair = std::minmax_element(v.begin(),v.end());
	std::cout << "\n COmbined Min Element = " << *minMaxPair.first << "\n Found at = " << minMaxPair.first - v.begin();
	std::cout << "\n COmbined Max Element = " << *minMaxPair.second << "\n Found at = " << minMaxPair.second - v.begin() << "\n";
	
}