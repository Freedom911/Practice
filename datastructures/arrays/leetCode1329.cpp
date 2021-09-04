#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:

    vector<vector<int>> diagonalSort1(vector<vector<int>>& mat) {
      
      int m = mat.size();
      if(m == 1)
        return mat;
      int n = mat[0].size();


       
      for(int k = m - 1; k >= 0; k--)
      {
        int i = k;
        int j = 0;
        
        vector<int>s;//(std::abs(k - i + 1));
        int l =  0;
                     
                     
        
        while(i < m)
        {
          if(j >= n)
            break;

          s.push_back(mat[i][j]);
          i++;
          j++;
          l++;
        }
        
        i = k;
        j = 0;
        std::sort(s.begin(),s.end());
        for(int g = 0; g < s.size(); g++)
        
        {
          if( i >= m || j >= n)
            break;
          
          mat[i][j] = s[g];

          
          
          i++;
          j++;
        }
      }
      
      
    for (int k = 1; k < n; k++)
    {
        int j = k;
        int i = 0;
        std::vector<int> s;//(std::abs(k-j + 1));
        int l = 0;

        while (j < n)
        {
          
          if(i >= m)
            break;


            
            s.push_back(mat[i][j]);
            i++;
            j++;
            l++;

        }
        
        j = k;
        i = 0;
      std::sort(s.begin(),s.end());
        for(int g = 0; g < s.size(); g++)
        
        {
          if( i >= m || j >= n)
            break;
          mat[i][j] = s[g];
          
        
          i++;
          j++;
        }
    }

   
      return mat;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int m = mat.size();
      if(m == 1)
        return mat;
      int n = mat[0].size();



      for(int k = m - 1; k >= 0; k--)
      {
        int i = k;
        int j = 0;
        std::set<int> s;

        while(i < m)
        {

          if(j >= n)
            break;

          s.insert(mat[i][j]);
          i++;
          j++;
        }
        auto iter = s.begin();
        i = k;
        j = 0;
        while(iter != s.end()&& i < m && j < n)
        {
          mat[i][j] = *iter;


          iter++;
          i++;
          j++;
        }
      }


      for (int k = 1; k < n; k++)
      {
        int j = k;
        int i = 0;
        std::set<int> s;

        while (j < n)
        {
          if(i >= m)
            break;

          s.insert(mat[i][j]);
          i++;
          j++;

        }
        auto iter = s.begin();
        j = k;
        i = 0;
        while(iter != s.end() && i < m && j < n)
        {
          std::cout << i << " Here " << j << std::endl;
          mat[i][j] = *iter;

          iter++;
          i++;
          j++;
        }
      }


      return mat;
    }
};

int main()
{
  Solution s;
  vector<vector<int>>arr{{3,3,1,1},{2,2,1,2},{1,1,1,2}};
  s.diagonalSort1(arr);

}
