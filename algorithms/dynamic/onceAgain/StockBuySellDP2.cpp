/**
 * https://takeuforward.org/data-structure/buy-and-sell-stock-ii-dp-36/
 *
 * We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days.
 * The following guidelines need to be followed:
 * We can buy and sell the stock any number of times.
 * In order to sell the stock, we need to first buy it on the same or any previous day.
 * We can’t buy a stock again after buying it once. In other words, we 
 * first buy a stock and then sell it. After selling we can buy and sell 
 * again. But we can’t sell before buying and can’t buy 
 * before selling any previously bought stock.
 *
 * Means we can do B S B S but not B B S S
 *
 * So continuning with previous Approach in one pass. We will also present DP solution as it 
 * may be required in further stock problems. Algorithmaicly 1 pass is better
 *
 * Solution 1 - Using Greedy One Pass
 * So the main intuition is we keep track of the max price after we bought
 * with some changes
 * We start with 0th element. Which is the start element and we keep track of the max element till this
 * transaction. As soon as well sell we reset the max element and add the profit
 *
 * Criteria for selling is 
 * as soon as we detect the price of the stock is going down we sell it just that
 *
 */
#include <iostream>
#include <vector>


int StockBuySell2(std::vector<int> &stockPrice)
{
    //this maintains the maximum element we got till now 
    //from the current start
    int maxE = 0;
    //this is the starting point of the new transaction
    int start = stockPrice[0];
    //this denotes the total profit 
    int totalProfit = 0;
    //This denotes the maximum profit we got in the current transaction
    int maxProfit = 0;

    for(int i = 0; i < stockPrice.size(); i++)
    {
        //Check if current day price of the stock is crashing
        if(stockPrice[i] <= maxE)
        {
            totalProfit += maxProfit;//we add the profit we achieved so far
            maxProfit = 0;//reset the max profit price after selling
            start = stockPrice[i];//Now we start with the current Price
            maxE = stockPrice[i];//set the max Element we got to stock price
        }
        else //means the stock day price 
        {
            maxProfit = std::max(maxProfit,stockPrice[i] - start);
        }
           maxE = std::max(maxE,stockPrice[i]);//update the maxE to denote the maximum we got
    }

    //add remaining. in case we dont get decreasing price
    totalProfit += maxProfit;
    return totalProfit;
}

//Dp Solution 
//Hypothesis - This function returns the max profit till day given that we can buy or not
int StockBuySell2DPTopDown(std::vector<int> &prices,int day,bool canBuy,std::vector<std::vector<int>> &dp)
{
    //Base Cases
    if(day >= prices.size() || prices.size() == 0)
    {
        return 0;
    }
    if(dp[day][canBuy]  != -1)
    {
        return dp[day][canBuy];
    }

    //Induction Step
    //each Day we have two choices either do nothing or buy/sell
    //if canbuy = True we have two options
    //do nothing
    //or buy
    //if canbuy = False we again have two options
    //do nothing
    //sell
    //we pick the max profit from that
    int op1 = 0,op2 = 0;
    if(canBuy == true)
    {
        op1 = 0 + StockBuySell2DPTopDown(prices,day+1,canBuy,dp);//means in next day we can still buy
        //you ask why negative. because when we buy our pocket pe load padta h
        //and we have now less money so that y negative
        //for next day we cant buy now so false passed
        op2 = -prices[day] + StockBuySell2DPTopDown(prices,day+1,false,dp);
    }
    else//we cant buy
    {
        op1 = 0 + StockBuySell2DPTopDown(prices,day+1,false,dp);//means in next day we can still sell
        //you ask why positive. because when we sell ouir pocket gets full
        op2 = +prices[day] + StockBuySell2DPTopDown(prices,day+1,true,dp);//means next day we can buy
    }

    return dp[day][canBuy] = std::max(op1,op2);
}

//Dp Solution Bottom Up Tabular
int StockBuySell2DPBottomUp(std::vector<int> &prices)
{
    //Base Cases
    if( prices.size() == 0)
    {
        return 0;
    }
    
    int n = prices.size();
    std::vector<std::vector<int>>dp(n + 1,std::vector<int>(2,0));
    //we start from last
    //so basically if we have no stocks left we cant buy sell
    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int i = n - 1; i >= 0; i--) //day
    {
        for(int j = 1; j >= 0; j--) //buy
        {
            int op1 = 0,op2 = 0;

            if(j == 1)//can buy
            {
                op1 = 0 + dp[i+1][1];
                op2 = -prices[i] + dp[i+1][0];
            }
            else//we cant buy but can sell
            {
                op1 = 0 + dp[i+1][0];

                op2 = +prices[i] + dp[i+1][1];
            }
            dp[i][j] = std::max(op1,op2);
        }
    }

    return dp[0][1]; // means at day 1st we can buy this is where will find the answer
        
}

int main()
{
    std::vector<int> vec{7,1,5,3,6,4};
    std::vector<std::vector<int>>dp(vec.size(),std::vector<int>(2,-1));
    std::cout << "\n One Pass     = " << StockBuySell2(vec) << "\n";
    std::cout << "\n DP Top Down  = " << StockBuySell2DPTopDown(vec,0,true,dp) << "\n";
    std::cout << "\n DP Bottom Up = " << StockBuySell2DPBottomUp(vec) << "\n";
}
