/**
 * https://takeuforward.org/data-structure/stock-buy-and-sell-dp-35/
 *
 * Best time to buy and sell stock
 * We are given an array Arr[] of length n. 
 * It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

    We can buy and sell a stock only once.
    We can buy and sell the stock on any day but to sell the stock, 
    we need to first buy it on the same or any previous day.
    We need to tell the maximum profit one can get by buying and selling this stock.

    Arr = [7,1,5,6,3,4]
    N = 6

    Max Profit = 5( Buy at 1 sell at 6)

    Here We can do via brute force,via dp and via direct one pass
    Brute force would be to calculate the max profit for each day
    like for 1st day we calculate the max profit we can get by check for each day after 1st
    so this will be o(n2)

    One pass solution
    So if we look at the array we see we need to buy a product at lowest price and sell at highest price
    but the catch here is we can sell only after bought that means if we find a minimum price for a stock
    but it is after max price then it is not valid
    So the solution is we move iteratively and calculate the max profit buy comparing the min price till now
    and the price at ith index.
 */

#include <iostream>
#include <vector>
#include <limits>

int StockBuySell1(std::vector<int> &vec)
{
    int maxProfit = std::numeric_limits<int>::min();
    int minPrice = vec[0];

    for(unsigned int i = 0 ; i < vec.size(); i++)
    {
        //Update Max Price based on current stock price
        maxProfit = std::max(maxProfit,vec[i] - minPrice);
        minPrice = std::min(minPrice,vec[i]);
    }

    return maxProfit;
}

int main()
{
    std::vector<int> vec{7,1,5,3,6,4};
    std::cout << "Max Profit We Got = " << StockBuySell1(vec) << "\n";
}




