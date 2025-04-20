/**
 *
 * https://takeuforward.org/binary-search/find-peak-element-ii
 *
 * Problem Statement: You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, 
 * where each cell contains a positive integer, and adjacent cells are distinct.
 * You need to find the location of a peak element in it. If there are multiple answers, find any of them.
 * A peak element is a cell with a value strictly greater than all its adjacent cells.
 * Assume the grid to be surrounded by a perimeter of ‘-1s’.
 
 * Examples
 * Input Format: N = 2, M = 2, g[][] = [[8,6],[10,1]]
 * Output: {1, 0}
 * Explanation: The element 10 is the peak element which is at cell {1, 0}(0-based indexing).
 * Input: N = 3, M = 3, g[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
 * Output: {2, 2}
 * Explanation: The element 9 is the peak element which is at cell {2, 2}(0-based indexing).
 *
 * Solution 1 - We can do n*m lineary search and find the max element. that will be definitley the peak element
 *
 * Solution 2 - We Continue The concept of Binary Search Peak Elemenet in 1d
 * For Answer - 
 * we check mid with 4 of its neighbor. we eleimnate up and down direction by finding the max element
 * 
 * So we first find the mid column. and now for that particular column we find the max element
 * That will be a probable candaidate of the peak. We compare with left and right.
 * If greater than both we return row and column
 *
 * For Movemnet
 * if arr[mid] < left side then the left side is more probable
 * We then move left, else we move right
 */
#include <iostream>
#include <vector>
#include <limits>

//This Function returns the index of row containing maximum element in a particular col
//Using Linear Search. We optimize further
int MaxRow(std::vector<std::vector<int>>& mat,int col)
{
   //Check conditions
   if(mat.size() == 0 || mat[0].size() == 0)
   {
       return -1;
   }
   int tr = mat.size();
   int maxIndex = -1;
   int maxValue = std::numeric_limits<int>::min();
   //for Every row for the particular column find the max
   for(int i = 0; i < tr; i++)
   {
       if(mat[i][col] > maxValue)
       {
           maxValue = mat[i][col];
           maxIndex = i;
       }
   }
   return maxIndex;
}


//This Function Returns the peak element in 2d matrix
std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) 
{
   //Check Conditions
   if(mat.size() == 0 || mat[0].size() == 0)
   {
       return  {-1,-1};
   }

   int low = 0;
   int high = mat.size()-1; // equal to no of columns
   int tc = mat[0].size();

   while(low <= high)
   {
       int midc = low + (high-low)/2;
       int midr = MaxRow(mat,midc);
       std::cout << "FOR MIDC = " << midc << " we Found max At row = " << midr << "\n";
       if(midr == -1)
       {
           break;
       }

       //Check for left and right only. up down already eliminated after fixing dthe max row
       int left = midc - 1>= 0 ? mat[midr][midc-1] : -1;
       int right = midc + 1 < tc ? mat[midr][midc+1] : -1;

       //Answer
       if(mat[midr][midc] > left && mat[midr][midc] > right)
       {
           return {midr,midc};
       }
       //Left Side More Promising
       else if(mat[midr][midc] <  left)
       {
          high = midc - 1;
       }
       else
       {
           low = midc + 1;
       }

   }
   return {-1,-1};
}

int main()
{
    std::vector<std::vector<int>> g = {{1,4}, {3,2}};
    std::vector<int> ans = findPeakGrid(g);
    std::cout << "The peak element is at: {" << ans[0] << ", "
            << ans[1] << "}" << std::endl;
}




