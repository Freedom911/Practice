#include <iostream>
#include <vector>
#include <stack>

void findNearestSmallerToRight(std::vector<int> in)
{
  std::vector<int> op(in.size(),-1);
  std::stack<int> s;

  for(int i = in.size() - 1; i >= 0; i--)
  {
    //keep poping until we find smaller elelemnt on the stacj
    while(s.empty() == false && s.top() >= in[i])
      s.pop();

    if(s.empty())
    {
      op[i] = -1;
    }
    else
      op[i] = s.top();

    s.push(in[i]);

  }

  for(auto &e:op)
  {
    std::cout << e << " ";
  }
}

int main()
{
  findNearestSmallerToRight({4,5,2,10,8});
}
