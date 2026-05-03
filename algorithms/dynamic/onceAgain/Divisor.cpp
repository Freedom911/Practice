#include <iostream>
#include<vector>
class Solution
{
public:
    //Hypothesis
    //The function tells whether any player wins given n moves
    //Here it is any player.initially we start with alice
    //so if other player loses he wins and vice versa
    //Optimal solution is if n  % 2 == 0 return true
    //because for all even alice will win
    bool divisorGame(int n)
    {
        std::vector<int>dp(n+1,-1);
        return divisorGameMemo(n,dp);
        #if 0
        if(n <= 1)
        {
            return false;
        }

        for(int i = 1; i < n; i++)
        {
            if(n%i == 0)
            {
                if (!divisorGame(n-i))//means if other player loses.victory for me
                {
                    return true;
                }
            }
        }

        return false;//means other player won so i  lose
        #endif
    }

      bool divisorGameMemo(int n,std::vector<int> &dp)
    {
        if(n <= 1)
        {
            return false;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        for(int i = 1; i < n; i++)
        {
            if(n%i == 0)
            {
                if (!divisorGameMemo(n-i,dp))//means if other player loses.victory for me
                {
                    return dp[n] = true;
                }
            }
        }

        return dp[n] = false;//means other player won so i  lose
    }

};

int main(int argc, char **argv)
{
    Solution s;
    std::cout << std::boolalpha << "\n RES = " << s.divisorGame(std::atoi(argv[1]));
}