/**
 * https://takeuforward.org/sliding-window/maximum-points-you-can-obtain-from-cards
 *
 *
 * Maximum Points You Can Obtain from Cards
 * Problem Statement: Given an array that represents the values of N 
 * different cards and an integer K. The task is to pick out K cards 
 * and at each step pick out one card either from the beginning or 
 * from the end of the row of cards in such a way that the 
 * sum of the values of cards picked is maximum.
 * We keep removing 1 element from left side and keep adding from right
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

int maxScore(std::vector<int>& cardPoints, int k)
{
   if(cardPoints.size() == 0)
   {
       return -1;
   }
   else if(cardPoints.size() == 1)
   {
       return cardPoints[0];
   }
    
   int sum = std::accumulate(cardPoints.begin(),cardPoints.begin() + k,0);
   int lsum = sum;
   int rsum = 0;
   int maxTillNow = sum;
   int j = 1;
   int n = cardPoints.size();
   for(int i = k; i>= 0; i--)
   {

    lsum -= cardPoints[i];
    rsum += cardPoints[n - j];
    j++;
    maxTillNow = std::max(maxTillNow,lsum + rsum);

   }

   return maxTillNow;



