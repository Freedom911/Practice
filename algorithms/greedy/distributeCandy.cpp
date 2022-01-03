//Distribute candy to each child with a rating given such that
//each chlid gets one candy
//more candies is given to child with higher rating than its neigbor
#include <iostream>
#include <vector>

int getMinimumCandies(std::vector<int> childrenRating)
{
  std::vector<int> result;
  result.push_back(1);
  for(int i = 1; i < childrenRating.size(); i++)
  {
    int candy = 1;

    //means left is smaller
    if(childrenRating[i - 1] < childrenRating[i])
    {
      candy++;
    }

    result.push_back(candy);
  }

  //compare right side
  //we have to travel from right side also
  //since starting is from there
  //we are using the same result vector. the last element is at correct position
  //we update result vector if max is found
  for(int j = childrenRating.size() - 2; j >= 0; j--)
  {
    int candy = 1;
     if(childrenRating[j + 1] < childrenRating[j])
     {
       candy++;
     }

     if(candy > result[j])
     {
       result[j] = candy;
     }
  }

  int sum = 0;
  for(auto &elem:result)
  {
    sum += elem;
  }

  return sum;

}

int main()
{
  std::vector<int> rating{1,5,2,1};

  std::cout << "\n Total Candies Needed = " << getMinimumCandies(rating) << "\n";
}
