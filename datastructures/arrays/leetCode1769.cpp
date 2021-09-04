#include <iostream>
#include <vector>
#include <string>

using  std::vector;
using  std::string;

class Solution {
public:
    vector<int> minOperations(string boxes) {
      
      vector<int>result;
      for (int i = 0; i < boxes.length(); i++)
      {
        int count = 0;
        for(int j= i-1,k = i+1;j >=0 || k < boxes.length(); j--,k++)
        {
          if(j >= 0 && boxes[j] == '1')
          {
            count += std::abs(i-j);
          }
          if(k < boxes.length() && boxes[k] == '1')
          {
            count += std::abs(i-k);
          }
        }
        result.push_back(count);
      }
      
      return result;
        
    }
};

int main()
{
  Solution s;
  std::vector<int> r = s.minOperations("001011");

  for(int i = 0; i < r.size(); i++)
  {
    std::cout << r[i] << " ";
  }
}
