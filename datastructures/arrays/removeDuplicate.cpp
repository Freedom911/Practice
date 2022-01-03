//Program To remove duplicates from the given sorted array

#include <iostream>
#include <vector>

int removeDuplicate(std::vector<int> &elem)
{
  int lastElement = elem[0];
  int p = 0;

  for(int i = 0; i < elem.size(); i++)
  {
    if(elem[i] != lastElement)
    {
      lastElement = elem[i];
      p++;
      std::swap(elem[i],elem[p]);
    }
  }

  return p + 1;
}

std::ostream &operator << (std::ostream & os,const std::vector<int> &elem)
{
  for(auto &e:elem)
  {
    os << e << " ";
  }

  return os;
}

int main()
{
  std::vector<int> arr {1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3};

  std::cout << "\n Initial Array == " << arr << "\n";

  int a =  removeDuplicate(arr);

  for(int i = 0; i < a; i++)
  std::cout <<  arr[i] << " ";
}
