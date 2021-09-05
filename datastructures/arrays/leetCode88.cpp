#include <iostream>
#include <vector>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
      int p = m - 1,q = n - 1,j = nums1.size() - 1;
      
      while(p >= 0 && q >= 0)
      {
        if(nums1[p] > nums2[q])
        {
          nums1[j] = nums1[p];
          p--;
        }
        else if(nums2[q] >= nums1[p])
        {
          nums1[j] = nums2[q];
          q--;
          
        }
      
        j--;
      }
      while(q >= 0)
      {
        nums1[j] = nums2[q];
        q--;
        j--;
      }
      while(p >= 0)
      {
        nums1[j] = nums1[p];
        p--;j--;
      }
      
      
    }
};
