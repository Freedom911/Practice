/**
 * Tought Problem for me. have to look through solution. please go through agfain
 */
#include <iostream>
#include <vector>

    //2d recsursion
    //beans the state depends on two varaible
    //and this can be problemetic while doing dp
    int foo2d(int currentA,int totalLeft)
    {
        //Base Condition
        if(totalLeft <= 0)
        {
            return currentA;
        }

        //for enter char
        int enter = foo2d(currentA + 1, totalLeft - 1);

        int res = enter;

        for (int i = 1; i <= totalLeft -2; i++)
        {
            int val = currentA * (i + 1);
            int left = totalLeft - 2 - i;

            res = std::max(res,foo2d(val,left));
        }
        return res;
    }

    int foo2dTopDown(int currentA,int totalLeft,std::vector<std::vector<int>>  &dp)
    {
        //Base Condition
        if(totalLeft <= 0)
        {
            return dp[totalLeft][currentA] = currentA;
        }

        if(dp[totalLeft][currentA] != -1)
        {
            //std::cout << "U\n";
            return dp[totalLeft][currentA];
        }

        //for enter char
        int enter = foo2dTopDown(currentA + 1, totalLeft - 1,dp);

        int res = enter;

        for (int i = 1; i <= totalLeft -2; i++)
        {
            int val = currentA * (i + 1);
            int left = totalLeft - 2 - i;

            res = std::max(res,foo2dTopDown(val,left,dp));
        }
        return dp[totalLeft][currentA] = res;
    }

int foo2dBottomUp(int currentA,int totalLeft)
{
}

//-------------------------ONE D SOLUTION
//ONE VARIABLE CHANGING SOLUTION
//SO here the function returns the maximum as well
int solve(int totalLeft)
{
    if (totalLeft <= 6)
    {
        return totalLeft;
    }

    int res = 1 + solve(totalLeft - 1);

    //now for every previous point we check the max
    for (int i = totalLeft - 3; i>= 1; i--)
    {
                                    //forumula n - (j+2) + 1
                                    //+1 as we have to include current leftters on screen
                                    //do the maths
                                    //if we have 2 paste left then original AAA + AAA + AAA
        int copyPaste = solve(i) * (totalLeft - (i + 2 ) + 1 );
        res = std::max(res, copyPaste);
    }

    return res;
}

int solve1D(int totalLeft,std::vector<int> dp1)
{
    if (totalLeft <= 6)
    {
        return totalLeft;
    }

    if(dp1[totalLeft] != -1)
    {
        return dp1[totalLeft];
    }

    int res = 1 + solve1D(totalLeft - 1,dp1);

    //now for every previous point we check the max
    for (int i = totalLeft - 3; i>= 1; i--)
    {
                                    //forumula n - (j+2) + 1
                                    //+1 as we have to include current leftters on screen
                                    //do the maths
                                    //if we have 2 paste left then original AAA + AAA + AAA
        int copyPaste = solve1D(i,dp1) * (totalLeft - (i + 2 ) + 1 );
        res = std::max(res, copyPaste);
    }

    return dp1[totalLeft] = res;
}

int solve1DBottomUp(int totalLeft)
{
    if (totalLeft <= 6)
    {
        return totalLeft;
    }
    std::vector<int> dp1(totalLeft+1,0);
    for(int i = 0; i <= 6; i++)
    {
        dp1[i] = i;
    }
    
    for(int i = 7; i<= totalLeft; i++)
    {
        dp1[i] = 1+dp1[i-1];
        for (int j = 1; j<= i-3; j++)
        {
            
            dp1[i] = std::max(dp1[i],(i - (j+2) + 1) * dp1[j]);
        }
    }

    return dp1[totalLeft];
}

int main()
{
    int i = 0;
    std::cin >> i;
    std::cout << "\n Getting = " << foo2d(0,i)<< "\n";

    //Bottom Up Approach
    std::vector<std::vector<int>> dp(i + 1,std::vector<int> (1000,-1));
    std::cout << "\n Getting = " << foo2dTopDown(0,i,dp)<< "\n";


    std::cout << "\n 1D = " << solve(i) << "\n";

      std::vector<int> dp1(i + 1,-1);
    std::cout << "\n 1D TOPDOWN = " << solve1D(i,dp1) << "\n";


    std::cout << "\n 1D BOTTOM = " << solve1DBottomUp(i) << "\n";

}