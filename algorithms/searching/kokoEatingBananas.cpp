class Solution {
public:
  
  bool checkIsPossible(const long long int &maxRate,const vector<int>&piles,const int&h)
  {
    if(maxRate == 0)
      return false;
    long long int count = 0;
    for(int i = 0; i < piles.size();i++)
    {
      count+=std::ceil((double)piles[i]/maxRate);
    }
    
    return count <= h;
  }
  
    int minEatingSpeed(vector<int>& piles, const int &h) {
       long long int l = 0;
      int s = piles.size();
      long long int r =1e9;
      int ans = std::numeric_limits<int>::max();
      long long int mid= -1;
      while(l <= r)
      {
         mid = l + (r-l)/2;
        if(checkIsPossible(mid,piles,h))
        {
          if(ans > mid)
             ans = mid;
          r = mid-1;
        } 
        else
          l = mid + 1;
      }
      return ans;
    }
};
