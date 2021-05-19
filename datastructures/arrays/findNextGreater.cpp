//Find No which is next greatest with the same digits
//eg - 1 2 3 4 5 -> 1 2 3 5 4
//Will start from right side to find the no whose left side is less
#include <iostream>
#include <vector>
#include <algorithm>

std::ostream &operator << (std::ostream &os,const std::vector<int> &elem)
{
  for(auto &e:elem)
    os << e << " ";
  return os;
}

void findNextGreater(std::vector<int> &no)
{

  std::cout << "\n INITIAL VECGOT " << no << "\n";

  //step 1 find a no whose right side is less
  int i = no.size() - 1;
  for(; i> 0; i--)
  {
      if(no[i - 1] < no [i])
        break;
  }

  int elem = no[i - 1];
  //Step 2 find the next greater no
  int nextGreator = no[i];
  int j,k ;
  for(j = i + 1; j< no.size(); j++)
  {
    if(no[j] > elem && no[j] < nextGreator)
    {
      nextGreator = no[j];
      k = j;
    }
  }

  std::swap(no[k],no[i-1]);

  std::sort(no.begin() + i,no.end());

  std::cout << "\n AFTER VECGOT " << no << "\n";

}

int main()
{
  std::vector<int> no {2,1,8,7,6,5};

  findNextGreater(no);
}

