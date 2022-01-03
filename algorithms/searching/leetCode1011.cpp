//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
  bool checkIsPossible(const int&maxWeight,const vector<int>&w,const int&days)
  {
    int total = 1;
    int sum = 0;
    for(int i = 0; i < w.size();i++)
    {
      sum+=w[i];
      if(sum > maxWeight)
      {
        sum = w[i];
        total++;
      }
    }
    return total <= days;
  }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
      int r = std::accumulate(weights.begin(),weights.end(),l);
      int ans = numeric_limits<int>::max();
      while( l<= r)
      {
        int mid = l + (r-l)/2;
        if(checkIsPossible(mid,weights,days))
        {
          r = mid - 1;
          if(ans > mid)
            ans = mid;
        }
        else
          l = mid + 1;
      }
      //we are retungin max in case the limit is less than max as we cannot have a capacity less than max
    return std::max(ans,*max_element(weights.begin(), weights.end()));
    }
};
