//https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
//Find Minimum Length to make an array fully sorted
//we will scan from left side first and find the element for which the right element is less
//then from right side we will find element in which the right element is bigger than left
//will remember those index now we will scan from 0 to unsorted piece of array to check
//whether we need to incluide more elemnets.similarly for right side
#include <iostream>
#include <vector>
#include <limits>

void findMinimumSortingList(std::vector<int> elements)
{
  int s = -1;
  int e = -1;
  for(int i = 0; i < elements.size() - 1; i++)
  {
    if(elements[i] > elements[i+1])
    {
      s = i;
      break;
    }

  }

  if(s == -1)
  {
    std::cout << "\n Vector is sorted already \n";
    return ;
  }
  std::cout << "\n S IS === " << s << "\n";
  for(int i =  elements.size() - 1; i > 0;i--)
  {
    if(elements[i] < elements[i - 1])
    {
      e = i;
      break;
    }
  }

  int max = -1,min = std::numeric_limits<int>::max();
  //Now we need to check if need more elenmennts to include
  //find Max and min within the range
  for(int j = s + 1; j<= e; j++)
  {
    if(elements[j] > max)
      max = elements[j];
    if(elements[j] < min)
      min = elements[j];
  }


  for(int i = 0; i < s; i++)
  {
    if(elements[i] > min)
    {
      s = i;
      break;
    }
  }
  
  for(int i = elements.size() - 1; i >= e; i--)
  {
    if(elements[i] < max)
    {
      e = i;
      break;
    }
  }


  std::cout << "\n SORTING ARAY BETWEEN (" << s << "," << e << ") \n";


}


int main()
{
 findMinimumSortingList( {10, 12, 20, 30, 25,40, 32, 31, 35, 50, 60});
}
