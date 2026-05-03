/**
https://leetcode.com/problems/unique-binary-search-trees/
so basically we try to make each element as root and check how many elements we can form on left
and how many on right. since thhey are independent we muyltiply to get combinatino
if we have x ways on left and y ways on right then using x*y ways to do both
if we have 2 pairs of shoes and 3 pairs of trougsers so total 6 ways to wear
*/

class Solution
{
public:
    // hypothesis this functino returns the no fo ways
    int foo(int n)
    {
        // base condition. only one way
        if (n <= 1)
        {
            return 1;
        }

        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = foo(i - 1);  // on left this many elements
            int right = foo(n - i); // on right side this many elements

            total += (left * right);
        }
        return total;
    }

    int fooTopDown(int n, std::vector<int> &dp)
    {
        // base condition. only one way
        if (n <= 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = fooTopDown(i - 1, dp);  // on left this many elements
            int right = fooTopDown(n - i, dp); // on right side this many elements

            total += (left * right);
        }
        return dp[n] = total;
    }

    int fooBottomUp(int n)
    {
        // base condition. only one way
        if (n <= 1)
        {
            return 1;
        }

        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int totalIndex = 1; totalIndex <= n; totalIndex++)
        {
            int total = 0;
            for (int i = 1; i <= totalIndex; i++)
            {

                int left = dp[i - 1];
                int right = dp[totalIndex - i]; // on right side this many elements

                total += (left * right);
            }
            dp[totalIndex] = total;
        }
        return dp[n];
    }

    int numTrees(int n)
    {
        // return foo(n);
        // std::vector<int> dp(n+1,-1);
        // return fooTopDown(n,dp);
        return fooBottomUp(n);
    }
};