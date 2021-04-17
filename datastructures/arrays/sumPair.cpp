//Find Pair With Given Sum - https://www.geeksforgeeks.org/count-pairs-with-given-sum/

#include <iostream>
#include <unordered_set>
#include <vector>

void findPair(std::vector<int> elem,int d)
{
  std::unordered_set<int> mapper;
  for(int e:elem)
  {
    int val = d - e;

    if(mapper.find(val) != mapper.end())
    {
      std::cout << "\n Found Pair = (" << e << "," << val << ")";
    }
    mapper.insert(e);
  }
}

int main()
{
  std::vector<int> elem{1,5,7,-1};
  findPair(elem,6);
}
