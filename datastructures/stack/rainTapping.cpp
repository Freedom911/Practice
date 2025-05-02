/* Program To efficiently Trap Rain Water based on the array given
 * Given an array of non-negative integers representation elevation of ground. 
 * My task is to find the water that can be trapped after rain.
 * Examples:
 * Example 1:
 * Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * Solution
 * If we observe Carefully for A tower We say the water trapped is dependanton the
 * Boundaries of left or right. Basically the lmax and rmax. 
 * eg 4,1,2,3,0,2,6 for the tower 4th i.e the water trapped will depend on the left most max and
 * right most max. i.e 4,6 me se min wala we pick
 * So Total Water Trapped = Sum( arr[i] - std::min(lmax,rmax)) where arr[i] is height of current tower
 * and lmax and rmax is the maximum we get.
 *
 * So Solution 1 - 
 * We make two array left side and right side
 * which stores the max we got till that index
 * After Forming Both the array we pick the min and subtract from the height and we sum all
 *
 * Time Complexity - O(n)
 * Space Complexity - O(n)
 *
 * Solution 2 
 * If we look Carefully we need only one of the minimunm left or right Boundary
 * So using The Coder Army Solution
 * We First Find the tower with the maximum Index let say maxIndex
 * Now For 0 till that index we only consider left side boundary as it will be less than right boundary i,e maxIndex
 *
 * eg 
 * 2,4,1,2,6,2,1
 * maxIndex = 4
 * so we start from left
 * current lmax = 2
 * then we go to 4 we update lmax = 4
 * then we go to 1 we have lmax = 4 so the water stored by 1 will be lmax -ar[i] = 4-1 = 3
 * we sum till max index
 * after that we go for right side of maxIndex
 * Now the left Boundary is 6 and the answer will depend on the right Boundary Only
 * Time Complexity - O(2n)
 * Space Complexity - O(1)
 *
 * Solution 3  Two Pointers
 * Continuning with the Solution 2 we can have the solution in 1 go
 * we take 4 variables lmax(stores the max from left side),rmax(stores the max from right side),
 * l = 0,r = n-1.
 * \
 * So when we get lmax > rmax that means the left Boundary is set and the answer depends on the right Boundary Only
 * so we update the water and do r--,same if rmax > lmax then the answer will depend on the left boundary only like
 * we did find the max Index in case of Solution 2 and we found the left side.
 */ 


#include <iostream>
#include <vector>


//Solution in O(n) time and space complexity
//we will maintain the max height of left and right of a bar
//which ever is less needs to be subtracted from that bar
//Solution 1 Time Complexity - O(n),Space Complexity - O(n)
int Solution1(std::vector<int> ar)
{
  std::vector<int> leftSide(ar.size(),0),rightSide(ar.size(),0);
  int max = -1;
  for(int i = 0; i < ar.size(); i++)
  {
    if(ar[i] > max)
    {
      max = ar[i];
    }
    leftSide[i] = (max);

  }

  max = -1;
  for(int i = ar.size() - 1; i >= 0; i--)
  {
     if(ar[i] > max)
     {
       max = ar[i];
     }
 
     rightSide[i] = max;

  }

  int totalUnits = 0;

  for(int i = 1; i < ar.size() - 1; i++)
  {
    int min = leftSide[i] < rightSide[i] ? leftSide[i]:rightSide[i];

    totalUnits += min - ar[i];
  }

  return totalUnits;

}

//Solution 2 - Using Max Index
//Time Copmplexity - O(2n)
//Space Complexity - O(1)
int Solution2(std::vector<int> &in)
{
    if(in.size() == 0)
    {
        return 0;
    }

    //find the max index
    int maxIndex = -1;
    int maxValue = -1;
    for(int i = 0; i < in.size(); i++)
    {
       if(maxValue < in[i])
       {
           maxValue = in[i];
           maxIndex = i;
       }
    }
     int waterStored = 0;
     int lmax = -1;
    //Finding For Left Side
    for(int i = 0; i < maxIndex; i++)
    {
       if(lmax < in[i])
       {
           lmax = in[i]; //update the lmax
       }
       else
       {
           waterStored += lmax - in[i]; //update the water count with curent height and max one
       }
    }

    //Finding For Right Side
    int rmax = -1;
    for(int i = in.size() - 1; i > maxIndex ; i--)
    {
       if(rmax < in[i])
       {
           rmax = in[i]; //update the rmax
       }
       else
       {
           waterStored += rmax - in[i]; //update the water count with curent height and max one
       }
    }
    return waterStored;
}

//Solution 3 - two Pointers 
//Time Copmplexity - O(n)
//Space Complexity - O(1)
int Solution3(std::vector<int> &in)
{
    if(in.size() == 0)
    {
        return 0;
    }

    int lmax = 0,rmax = 0;
    int l = 0;
    int r = in.size() - 1;
    int waterStored = 0;

    while(l <= r)
    {
        //Update lmax and rmax till now
        lmax = std::max(lmax,in[l]);
        rmax = std::max(rmax,in[r]);

        if(lmax < rmax) //means the right Boundary is high so answer depends on left boundary only
        {
            waterStored += lmax - in[l];
            l++;
        }
        else
        {
            waterStored += rmax - in[r];
            r--;
        }
    }
    return waterStored;
}

int main()
{
  //std::vector<int> elev{0,1,0,2,1,0,1,3,2,1,2,1};
  std::vector<int> elev{5,3,4,6,7,4};

  std::cout << "\n Total Units Trapped = " << Solution1(elev) << " Units\n";
  std::cout << "\n Total Units Trapped = " << Solution2(elev) << " Units\n";
  std::cout << "\n Total Units Trapped = " << Solution3(elev) << " Units\n";
}
