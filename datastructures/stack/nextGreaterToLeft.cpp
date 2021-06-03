#include <iostream>
#include <stack>
#include <vector>

void findNextGreaterToLeft(std::vector<int> in)
{
  std::vector<int> op;
  std::stack<int> s;

  for(int i = 0; i <in.size(); i++)
  {
    while(s.empty() == false && s.top() <= in[i])
      s.pop();

    if(s.empty())
      op.push_back(-1);
    else
      op.push_back(s.top());

    s.push(in[i]);
  }

  std::cout << "\n Next Greater to left is \n";
  for(auto &e:op)
  {
    std::cout << e << " ";
  }
}

int main()
{
  findNextGreaterToLeft({1,3,2,4});
}

