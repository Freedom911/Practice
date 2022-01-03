//Given an array find the frequency in o(n) time and O(1) space complexity
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
    std::cout << "\n FREQUENCY of " << i + 1 << " is = " << ar[i] / n << "\n";
  }

}

int main()
{
  std::vector<int> ar{2,3,1,2,3};
  findFrequency(ar);
}
