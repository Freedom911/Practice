#include <iostream>
#include <vector>
using namespace std;

//2nd Optimal solution
class Solution {
public:
    int longestOnes(vector<int>& ar, int k) 
    {
       int l = 0,r = 0;
       int n = ar.size();
       int maxWindow = 0;
       while(r < n)
       {
         if(ar[r] == 0)
         {
            k--;
         }

         while(k < 0)
         {
            if(ar[l] == 0)
            {
                k++;
            }
            l++;
         }
         maxWindow = std::max(maxWindow,r-l+1);
         r++;
         
       }   
       return maxWindow; 
    }
};

//best. so in 2nd optimal solution we were moving the l pointer till we 
//eliminated at least one
//So the Best solution says we dont update maxCount
//we just move by one. in the next loop we will get
class Solution2 {
public:
    int longestOnes(vector<int>& ar, int k)
    {
       int l = 0,r = 0;
       int n = ar.size();
       int maxWindow = 0;
       while(r < n)
       {
         if(ar[r] == 0)
         {
            k--;
         }

         if(k < 0)
         {
             if(ar[l] == 0)
             {
                 k++;
             }

             l++;
         }

         maxWindow = std::max(maxWindow,r-l+1);
         r++;

       }
       return maxWindow;
    }
};

int main()
{

}
