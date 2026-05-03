/**
 * Hints - This is similar to the Climbing Stairs problem, but with constraints on which steps are valid.
 A digit of '0' can never be decoded on its own, and a two-digit number must be between 10 and 26.
 */
class Solution
{
public:
    int foo(string s, int i)
    {
        if (i == 0)
        {
            return s[i] == '0' ? 0 : 1;
        }
        else if (i < 0)
        {
            return 1;
        }
        int count = 0;
        if (s[i] != '0')
        {
            count += foo(s, i - 1);
        }
        if (i - 1 >= 0 && s[i - 1] != '0')
        {
            std::string num = string{s[i - 1], s[i]};
            if (stoi(num) > 26)
            {
                return count;
            }
            count += foo(s, i - 2);
        }
        return count;
    }

    int fooTopDown(string s, int i, vector<int> &dp)
    {
        if (i == 0)
        {
            return s[i] == '0' ? 0 : 1;
        }
        else if (i < 0)
        {
            return 1;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int count = 0;
        if (s[i] != '0')
        {
            count += fooTopDown(s, i - 1, dp);
        }
        if (i - 1 >= 0 && s[i - 1] != '0')
        {
            std::string num = string{s[i - 1], s[i]};
            if (stoi(num) > 26)
            {
                return dp[i] = count;
            }
            count += fooTopDown(s, i - 2, dp);
        }
        return dp[i] = count;
    }

    int fooBottomUp(string s)
    {
        if (s.length() == 0 || s[0] == '0')
        {
            return 0;
        }

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= s.length();i++)
        {
            if (s[i-1] != '0')
            {
                dp[i] = dp[i - 1];
            }
            {
                std::string num = string{s[i - 2], s[i-1]};
                if (stoi(num) <= 26 && stoi(num) >= 10)
                {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.length()];
    }

    int mostOptimized(string s)
    {
        if (s.length() == 0 || s[0] == '0')
        {
            return 0;
        }
        int a = 1;
        int b = 1;
        

        for (int i = 2; i <= s.length();i++)
        {
            int c = 0;

            if (s[i-1] != '0')
            {
                c += b;
            }

            {
                std::string num = string{s[i - 2], s[i-1]};
                if (stoi(num) <= 26 && stoi(num) >= 10)
                {
                    c += a;
                }
            }
            a = b; 
            b = c;
        }
        return b;    
    }
    int numDecodings(string s)
    {
        // return foo(s,s.length() - 1);
        //std::vector<int> dp(s.length(), -1);
        //return fooTopDown(s, s.length() - 1, dp);
        //return fooBottomUp(s);
        return mostOptimized(s);
    }
};