//Given Height of Historgram Need to find Maximum Height we can make
//In this we find NSL and NSR and store the index of them in two array as 
//for a histogram it can go upto NSL and NSR only. Width would be NSR - NSL - 1
//Width of each histogram is 1. Then we loop through the input vector and multiply
//the width and find the max area
#include <iostream>
#include <stack>
#include <vector>
#include <limits>

std::vector<int> getNSL(std::vector<int> in)
{
  //Find the next smallest element and return the index vector
  std::vector<int> nslIndex;
  //This stores the index of NSL
  std::stack<std::pair<int,int>>s;
  for(int i = 0; i < in.size(); i++)
  {
    while(s.empty() == false && s.top().first > in[i])
    {
      s.pop();
    }

    if(s.empty())
      nslIndex.push_back(-1);
    else
      nslIndex.push_back(s.top().second); 

    s.push(std::make_pair(in[i],i));
  }

  return nslIndex;
}

std::vector<int> getNSR(std::vector<int> in)
{
  std::vector<int> nsrIndex(in.size(),0);
  std::stack<std::pair<int,int>>s;

  for(int i= in.size() - 1; i>= 0; i--)
  {
    while(s.empty() == false && s.top().first > in[i])
    {
      s.pop();
    }
    if(s.empty())
    {
      //we are assuming the nth element that is beyond the total has minimum value
      //so pushing nth
      nsrIndex[i] = (in.size());
    }
    else
    {
      nsrIndex[i] = (s.top().second);
    }

    s.push(std::make_pair(in[i],i));
  }

  return nsrIndex;
}

int maximumWidthOFHistogram(std::vector<int> in)
{
  std::vector<int> width;
  std::vector<int> nsr = getNSR(in);
  std::vector<int> nsl = getNSL(in);


  for(int i = 0; i < nsr.size(); i++)
  {
    width.push_back(nsr[i] - nsl[i] - 1); //1 is due to width of each bar
  }

  int max = std::numeric_limits<int>::min();
  //in contains input and it is the length of each bar so basically height
  for(int j = 0; j < in.size(); j++)
  {
    max = std::max(max,in[j] * width[j]); //set max which has max area l * b
  }


  return max;


  
}

int main()
{
  std::cout << "\n MAXIMUM AREA = " << maximumWidthOFHistogram({6,2,5,4,5,1,6});

}
