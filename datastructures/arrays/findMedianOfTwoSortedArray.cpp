//Finding Median Of two odd length same sized array 
//without using o(n) space complexity
#include <iostream>
#include <vector>

float getMedian(std::vector<int> a,std::vector<int> b)
{
  int p = 0,q = 0,total = 0;
  float median = 0.f;

  int medianPosition  = (a.size() + b.size())/2;

  while(p < a.size() && q < b.size())
  {
    total++;
    int element;

    if(a[p] < b[q])
    {
      element = a[p];
      p++;
    }
    else
    {
      element = b[q];
      q++;
    }


    if(total == medianPosition)
    {
      median += element;
    }
    else if (total == medianPosition + 1)
    {
      median += element;
      break;
    }

  }

  if(total != medianPosition + 1)
  {
    if(q < b.size())
      median += b[q];

    else if(p < a.size())
      median += a[p];
  }

  return median/2;


}

int main()
{
  std::vector<int> a{1,6,8,10,12};
  std::vector<int> b{2,3,4,9,11};


  std::cout << "\n Median Of two array = " << getMedian(a,b) << "\n";
  
  std::vector<int> a1{1};
  std::vector<int> b1{3};
  
  std::cout << "\n Median Of two array = " << getMedian(a1,b1) << "\n";
  
  std::vector<int> a2{100,200,300};
  std::vector<int> b2{1,2,3};
  
  std::cout << "\n Median Of two array = " << getMedian(a2,b2) << "\n";

}
