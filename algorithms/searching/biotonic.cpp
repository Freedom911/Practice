#include <iostream>
#include <vector>


int findPeakElement(std::vector<int> nums) {
        int p = 0;
      int q = nums.size() - 1;
      int mid = -1;
      while(p <= q)
      {
        mid = p + (q-p)/2;
        int prev = mid - 1;
        int next = mid + 1;
        if(prev < 0 && next >= nums.size())
          return 0;
        
        if((prev < 0 && nums[mid] > nums[next]) || (next >= nums.size() && nums[mid] > nums[prev]))
        {
          return mid;
        }
        
        //right side more promising
        else if(nums[mid] < nums[next])
        {
          p = mid + 1;
        }
        else if(nums[mid] < nums[prev])
          q = mid - 1;
        else if( nums[mid] > nums[prev] && nums[mid] > nums[next])
        {
          return mid;
        }
        
      }
      return 0;
      
    }

int main()
{
  std::vector<int> v = {1,3,8,12,4,2};
  std::cout << v[findPeakElement(v)] << "\n";
}
