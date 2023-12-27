#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

    int numJewelsInStones(string jewels, string stones) {
	
		int count = 0;
        unordered_set<int> us;
		//O(n)
		for(int i = 0; i < jewels.length(); i++)
		{
			us.insert(jewels[i]); //O(1)
		}
		
		for(int i = 0 ; i < stones.length(); i++)
		{
		  if(us.find(stones[i]) != us.end())
		  {
			count++;
		  }
		}
		
		return count;
		
    }
	
int main()
{
  std::cout << numJewelsInStones("aA","bcaAaAa") << "\n";
}
