class Solution {
public:
    int foo(const vector<int> &cost, size_t steps)
    {
        if (steps <= 1)
        {
            return cost[steps];
        }

        int currentCost = 0;
   
        return min(cost[steps] + foo(cost,steps - 1),cost[steps] + foo(cost,steps-2));
    }
    int fooTopDown(const vector<int> &cost, size_t steps,vector<int> &dp)
    {
        if (steps <= 1)
        {
            return cost[steps];
        }

        if(dp[steps] != -1)
        {
            return dp[steps];
        }

        int currentCost = 0;
   
        return dp[steps] =  min(cost[steps] + fooTopDown(cost,steps - 1,dp),
        cost[steps] + fooTopDown(cost,steps-2,dp));
    }

    int fooBottomUp(const vector<int> &cost)
    {
       vector<int> dp(cost.size(),0);
       dp[0] = cost[0];
       dp[1] = cost[1];
       
       for(int i = 2; i < cost.size(); i++)
       {
         dp[i] = min(cost[i] + dp[i-1],cost[i] + dp[i-2]);
       }
       return dp[cost.size() - 1];
    }
    int superOptimized(const vector<int> &cost)
    {
        int a = cost[0];
        int b = cost[1];

        for(int i = 2; i < cost.size(); i++)
        {
            c = min(cost[i] + b,cost[i] + a);
            a = b;
            b = c;
        }
        return c;
    }
    
    int minCostClimbingStairs(vector<int>& cost)
     {
        cost.push_back(0);
        return fooTopDown(cost);
        vector<int> dp(cost.size() + 1,-1)
        return fooTopDown(cost,cost.size() - 1,dp);   
    }
};