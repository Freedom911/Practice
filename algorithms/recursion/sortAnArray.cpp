//Given an array sort the array using recursion

#include <iostream>
#include <vector>

void insertInArray(std::vector<int> &ar,int element);
//Hypothesis
void sort(std::vector<int> &ar)
{
  //Base Condition For Array of size 1 it is already sorted
  if(ar.size() <= 1)
    return;

  //Induction 
  //Given an element insert that element into the sorted array
  int element = ar[ar.size() - 1];
  ar.pop_back();

  //Sort the remaining array
  sort(ar);

  //Insert the element at the given array
  insertInArray(ar,element);

}

void insertInArray(std::vector<int> &ar,int element)
{
  //Base Condition
  //Just push back at last
  if(ar.size() == 0 || ar[ar.size() - 1] <= element)
  {
    ar.push_back(element);
    return;
  }

  //Induction
  //Reduce the size of array
  int val = ar[ar.size() - 1];
  ar.pop_back();
  //For the reduce sorted array insert the element at the right place
  insertInArray(ar,element);
  ar.push_back(val);
}

int main()
{
  std::vector<int> ar{0,1,2,90,3,4};
  sort(ar);
  for(auto &e:ar)
  {
    std::cout << e << " ";
  }
}
