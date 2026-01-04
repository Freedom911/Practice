/**
 *
 * https://leetcode.com/problems/wildcard-matching/
 *
 * Given an input string (s) and a pattern (p), 
 * implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

    The matching should cover the entire input string (not partial).



    Example 1:

    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa"

    So I will explain

    we are given 2 strings. when there is no wild cards then it is simple string matching
    
    case 1 : if ? then we can match ? in str[i] with str2[j] with any char
    like str 1 a?b
         str 2 acb
         then ? will match c

    case 2 : if we have * then the case is different as it may match with o or more
    like str1 a*b and str2 is abcbweqwdbsacb
    then * can match with 0 char or more so it will return true in this case

    so if str[i] == * then either
    f(i-1,j) means ignore * and match with no character or
    f(i,j-1) or we match star with one of the char of str2 and we keep reducing it
    if any one is true then we return true


    Base case is 
    if(i < 0 && j < 0) then it means both string matched return true
    if(i < 0 && j >= 0) //means str1 exhausted not even having wild char then return false
    but if j < 0 and i>=0 means str 1 still have some char left .then we check if they are stars all then return true
    because this can only be the case
*/    
#include <iostream>
#include <string>

//Hypothesis - this function matches str 1 and 2 which can have wild cards
//till i and j
bool solve(std::string str1,std::string str2, int i, int j)
{
    //Base cases
    //Both cases exhausted
    if(i < 0 && j < 0)
    {
        return true;
    }
    else if(i < 0 && j >= 0)
    {
        return false;//j still left we cant match
    }
    else if(j < 0 && i >= 0)
    {
        for(int index = 0; index <= i; index++)
        {
            if(str[index] != '*')
            {
                return false;
            }
        }
        return true;
    }


    //induction step
    //Char same or ? as it can match with anything
    if(str1[i] == str2[j] || str1[i] == '?')
    {
        return true;
    }
    else if(str1[i] == '*')
    {
        //either ignore * or match with 0 or more
        return solve(str1,str2,i-1,j) || solve(str1,str2,i,j-1);
    }
    return false;
}

bool solveTopDown(std::string str1,std::string str2, int i, int j,std::vector<std::vector<int>> &dp)
{
    //Base cases
    //Both cases exhausted
    if(i <= 0 && j <= 0)
    {
        return true;
    }
    else if(i <= 0 && j > 0)
    {
        return false;//j still left we cant match
    }
    else if(j <= 0 && i > 0)
    {
        for(int index = 1; index < i; index++)
        {
            if(str[index - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j] == 1; //1 means true 0 means false -1 means not initialized
    }


    //induction step
    //Char same or ? as it can match with anything
    if(str1[i-1] == str2[j-1] || str1[i-1] == '?')
    {
        dp[i][j] = 1;
        return true;
    }
    else if(str1[i-1] == '*')
    {
        //either ignore * or match with 0 or more
        bool val = solve(str1,str2,i-1,j) || solve(str1,str2,i,j-1);
        dp[i][j] = val == true ? 1:0;
        return val;
    }
    dp[i][j] = 0;
    return false;
}

bool wildCardMatch(std::string str1,std::string str2)
{
    int n = str1.size();
    int m = str2.size();

    //return solve(str1,str2,n-1,m-1);
    //for dp since we are checking for i - 1 so increment everything
    td::vector<std::vector<int>> dp(n + 1,std::vector<int>(m+1,-1));
    return solveTopDown(str1,str2,n-1,m-1,dp);


}
