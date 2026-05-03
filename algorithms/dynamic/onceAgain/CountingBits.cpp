/**
 * 
 * pproach 1 relies on a simple observation: 
 * Shifting a binary number to the right by one position is the same as dividing it by 2
 *  and discarding the remainder.In programming terms, i >> 1 is equivalent to i // 2.
 * The Core LogicEvery number i is either Even or Odd.
 *  We can determine the number of set bits (1s) in i by looking at the number we already 
 * calculated for i // 2 
 * .1. If the number is Even (e.g., i = 6)The binary representation of an even number always ends in 0
 * .6 in binary is 110.If we shift it right (6 >> 1), we get 3, which is 11.
 * Notice that 110 has the exact same number of 1s as 11.
 * Rule: ans[i] = ans[i // 2] 
 * 
 * 2. If the number is Odd (e.g., i = 7)The binary representation of an odd number always
 *  ends in 1.7 in binary is 111.If we shift it right (7 >> 1), we get 3, which is 11.
 * Notice that 111 has one more 1 than 11.Rule: ans[i] = ans[i // 2] + 1
 * 
 * So basically for n = 4
 * i = 0 arr[0] = 0
 * arr[1] = arr[1>>1] + 1 = arr[0] + 1
 * arr[2] = arr[2>>1]   = arr[1] 
 * arr[3] = arr[3 >> 1] + 1 = arr[1] + 1
 * arr[4] = arr[4 >> 1] + 0 = arr[2] + 0
 * this is bottom up
 * 
 * Leetcode counting bits
 * https://leetcode.com/problems/counting-bits/
 * 
 * Other simple solution o(nlogn)
 * is for i = 0 to n we call the countSetBits function we defined in bits folder look
 */

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n+1,0);

        for(int i = 1; i <= n; i++)
        {
            //even
            if( i % 2 == 0)
            {
                ans[i] = ans[i >> 1];
            }
            else
            {
                ans[i] = ans[i>>1] + 1;
            }
        }

        return ans;
    }
};