#include<iostream>
#include <stack>
#include <vector>

void findNearestSmallestToLeft(std::vector<int> in)
{ 
  std::vector<int> op;
  std::stack<int> s;

  for(int i = 0; i < in.size(); i++)
  {
    //pop till top element is smaller
    while(s.empty() == false && s.top() >= in[i])
      s.pop();

    if(s.empty())
      op.push_back(-1);

    else
      op.push_back(s.top());

    s.push(in[i]);
  }

  for(auto &e:op)
  {
    std::cout << e << " ";
  }
}

int main()
{
  findNearestSmallestToLeft({4,5,2,10,8});
}
