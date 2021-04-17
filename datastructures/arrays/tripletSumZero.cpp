//Find Triplets Pair whose sum is 0
//https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
//The approach we will take to reduce the time to o(n2) is
//first sort the elements in O(nlogn) 
//Then after that we will take an element and have two counters l and r 
//l will be next to i+1 and r will be last
//if all three sums is less than 0 then increment l 
//else greater than 0 then decrement r
//we have two loops so complexity would be o(n2)

#include <iostream>
#include <vector>
#include <algorithm>

//Generalized to any elmeent
void findTripletsPair(std::vector<int> elements,int d)
{
  //sorts in acending order
  std::sort(elements.begin(),elements.end());
  
  int size = elements.size() - 1;
  for(int i = 0; i< size;i++)
  {
    int x = elements[i];
    int l = i + 1;
    int r = size;

    while(l < r)
    {
      int sum = x + elements[l] + elements[r];
      if(sum == d)
      {
        std::cout << "\n TRIPLET FOUND = (" << x << "," << elements[l] << "," << elements[r] << ")";
        l++;
        r--;
      }

      else if(sum < d)
        l++;
      else
        r--;
    }
  }

}


int main()
{
  findTripletsPair({0, -1, 2, -3, 1},3);
}
