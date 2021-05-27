//Given an array find the no which appears more than n/2 times o(n) time and O(1) space complexity
//no can range from 1- n
#include <iostream>
#include <vector>

void findFrequency(std::vector<int> ar)
{
  for(int i = 0; i < ar.size(); i++)
    ar[i]--;

  int n = ar.size();
  for(int i = 0; i < ar.size(); i++)
  {
    ar[ar[i] % n] += n;
  }
  
  for(int i = 0; i < ar.size(); i++)
  {
    //std::cout << "array =  " << ar[i] << "\n";
    if(ar[i]/n > n/2)
    std::cout << "\n FREQUENCY of " << i + 1 << " is = " << ar[i] / n << "\n";
  }

}

int main()
{
  std::vector<int> ar{2,3,3,2,2,5,2,3,1,2,2};
  findFrequency(ar);
}
