class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::unordered_map<int,int> us;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int k = 2;
        int maxW = 0;

        while(r < n)
        {
            us[fruits[r]]++;

            if(us.size() > k)
            {
                us[fruits[l]]--;

                if(us[fruits[l]] == 0)
                {
                    us.erase(fruits[l]);
                }
                l++;
            }
            maxW = std::max(maxW,r-l+1);
            r++;
        }
        return maxW;
    }
};
