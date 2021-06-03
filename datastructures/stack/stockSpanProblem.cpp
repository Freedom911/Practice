#include <iostream>
#include <vector>
#include <stack>

//Problem is similar to finding next greater element on left
void stockProblem(std::vector<int> in)
{
  std::stack<std::pair<int,int>> s;
  std::vector<int> o;
  for(int i = 0 ; i < in.size(); i++)
  {
     while(s.empty() == false && s.top().first < in[i])
     {
       s.pop();
     }

     if(s.empty())
       o.push_back(1);
     else
       o.push_back(i - s.top().second);

     s.push(std::make_pair(in[i],i));
  }

  for(auto e:o)
  {
     std::cout << e << " ";
  }
}

int main()
{
  stockProblem({100,80,60,70,60,75,85});
}
