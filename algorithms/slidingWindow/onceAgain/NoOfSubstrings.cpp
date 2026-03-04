class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        std::unordered_map<char,int> us;

        int l = 0,r = 0;
        int n = s.length();
        int totalSub = 0;

        while(r < n)
        {
            us[s[r]]++;

            while(us.size() == 3)
            {
                totalSub += n - r ;

                us[s[l]]--;

                if(us[s[l]] == 0)
                {
                    us.erase(s[l]);
                }
                l++;
            }

            r++;
        }   

        return totalSub; 
    }
};
