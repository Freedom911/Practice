/**
 *
 * https://takeuforward.org/data-structure/buy-and-sell-stock-iii-dp-37
 * 
 * Stock Problem 4 is with cool down so basically when we sell the next day to buy will be day + 2 instead of day + 1
 * Stock Problem5 is with a fee so when we sell we add the fee
 *
 * We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days.
 * The following guidelines need to be followed:
 * We can buy and sell the stock any number of times.
 * In order to sell the stock, we need to first buy it on the same or any previous day.
 * We can’t buy a stock again after buying it once. In other words,
 * we first buy a stock and then sell it. After selling we can buy and sell again.
 * But we can’t sell before buying and can’t buy before selling any previously bought stock.
 * We can do at most 2 transactions.
 *
 * Solution Iwillpresent is of dp and we also try one pass
 * 
 * 
 */

#include <iostream>
#include <vector>

// Dp Solution
// Hypothesis - This function returns the max profit till day given that we can buy or not
// We add cap to restrict total tansactions
int StockBuySell3DPTopDown(std::vector<int> &prices, int day, bool canBuy, int cap, std::vector<std::vector<std::vector<int>>> &dp)
{
    // Base Cases
    if (day >= prices.size() || prices.size() == 0 || cap == 0)
    {
        return 0;
    }
    if (dp[day][canBuy][cap] != -1)
    {
        return dp[day][canBuy][cap];
    }

    // Induction Step
    // each Day we have two choices either do nothing or buy/sell
    // if canbuy = True we have two options
    // do nothing
    // or buy
    // if canbuy = False we again have two options
    // do nothing
    // sell
    // we pick the max profit from that
    int op1 = 0, op2 = 0;
    if (canBuy == true)
    {
        // Cap only changes when we complete the transaction i.e we sell
        op1 = 0 + StockBuySell3DPTopDown(prices, day + 1, canBuy, cap, dp); // means in next day we can still buy
        // you ask why negative. because when we buy our pocket pe load padta h
        // and we have now less money so that y negative
        // for next day we cant buy now so false passed
        op2 = -prices[day] + StockBuySell3DPTopDown(prices, day + 1, false, cap, dp);
    }
    else // we cant buy
    {
        op1 = 0 + StockBuySell3DPTopDown(prices, day + 1, false, cap, dp); // means in next day we can still sell
        // you ask why positive. because when we sell ouir pocket gets full
        // Completed the transactionthats why cap -1
        op2 = +prices[day] + StockBuySell3DPTopDown(prices, day + 1, true, cap - 1, dp); // means next day we can buy
    }

    return dp[day][canBuy][cap] = std::max(op1, op2);
}

// Dp Solution Bottom Up Tabular
int StockBuySell3DPBottomUp(std::vector<int> &prices)
{
    // Base Cases
    if (prices.size() == 0)
    {
        return 0;
    }

    int cap = 2;
    int n = prices.size();
    // We add cap as well
    std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(2, std::vector<int>(cap + 1, 0)));
    // we start from last

    for (int i = n - 1; i >= 0; i--) // day
    {
        for (int j = 1; j >= 0; j--) // buy
        {
            for (int c = 1; c <= cap; c++)
            {
                int op1 = 0, op2 = 0;

                if (j == 1) // can buy
                {
                    op1 = 0 + dp[i + 1][1][c];
                    op2 = -prices[i] + dp[i + 1][0][c];
                }
                else // we cant buy but can sell
                {
                    op1 = 0 + dp[i + 1][0][c];

                    op2 = +prices[i] + dp[i + 1][1][c - 1];
                }
                dp[i][j][c] = std::max(op1, op2);
            }
        }
    }

    // means at day 1st we can buy this is where will find the answer
    // 0 means at day 1 , next 1 means initially we have buy and cap = 2
    return dp[0][1][2];
}

// This is one pass with Time O(n) and space O(1) best way
// The Thing is we want to only limit to 2 transactions so basically we
// want only first two maximum. we could use 2 variables if for k comes we can keep max heap
int StockBuySell3(std::vector<int> &stockPrice)
{
    // this maintains the maximum element we got till now
    // from the current start
    int maxE = 0;
    // this is the starting point of the new transaction
    int start = stockPrice[0];
    // this denotes the total profit
    int totalProfit = 0;
    // This denotes the maximum profit we got in the current transaction
    int maxProfit = 0;

    // Keep Track of 2 max profits
    int firstMax = 0;
    int secondMax = 0;

    for (int i = 0; i < stockPrice.size(); i++)
    {
        // Check if current day price of the stock is crashing
        if (stockPrice[i] <= maxE)
        {
            if (maxProfit > firstMax)
            {

                secondMax = firstMax;
                firstMax = maxProfit;
            }
            // Dont just add we keep track
            // totalProfit += maxProfit;//we add the profit we achieved so far
            maxProfit = 0;         // reset the max profit price after selling
            start = stockPrice[i]; // Now we start with the current Price
            maxE = stockPrice[i];  // set the max Element we got to stock price
        }
        else // means the stock day price
        {
            maxProfit = std::max(maxProfit, stockPrice[i] - start);
        }
        maxE = std::max(maxE, stockPrice[i]); // update the maxE to denote the maximum we got
    }

    if (maxProfit >= firstMax)
    {

        secondMax = firstMax;
        firstMax = maxProfit;
    }

    return firstMax + secondMax;
}

int main()
{
    std::vector<int> vec{7,6,4,3,1};
    ;
    int cap = 2;
    std::vector<std::vector<std::vector<int>>> dp(vec.size(), std::vector<std::vector<int>>(2, std::vector<int>(cap + 1, -1)));
    std::cout << "\n One Pass     = " << StockBuySell3(vec) << "\n";
    std::cout << "\n DP Top Down  = " << StockBuySell3DPTopDown(vec, 0, true, cap, dp) << "\n";
    std::cout << "\n DP Bottom Up = " << StockBuySell3DPBottomUp(vec) << "\n";
}
