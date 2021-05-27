//FInd a way to efficiently calculate no of set bits
//https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

#include <iostream>

//This will be called for the number of bits
int findSetBits(int no)
{
  int count = 0;
  int j = 0;
  while(no)
  {
    count += no & 1;
    no >>=1; //do right shift
    j++;
  }
    std::cout << "\n CALLED " << j << "\n";
  return count;
}

//Brian Kernighan’s Algorithm
//here the logic is we will do and with 1 minus the number
//this removes the right most one after counting
//THis will only be called for total bits set
//Subtracting 1 from a decimal number flips all the bits after the 
//rightmost set bit(which is 1) including the rightmost set bit. 

int findSetBitsOptimized(int no)
{
  int count = 0;
  while(no)
  {
    no =  no & (no -1);
    std::cout << "\n CALLED1\n";
    count++;
  }
  return count;
}

int main()
{
  std::cout << "\n SET BITS FOR 6 = " << findSetBits(2048) << "\n";
  std::cout << "\n SET BITS FOR 6 = " << findSetBitsOptimized(2048) << "\n";
}
