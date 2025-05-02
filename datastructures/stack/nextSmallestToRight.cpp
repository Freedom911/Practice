//Find NNearest Smaller to Right
//we can do two loops - O(n2)
//Using 1 loop
//we use Stack
//There are two ways to start
//from end or from begining
//from end it is simple as the order is maintained in the stack
//3,2,1 - starting from right  2  1 -1
//So in the stack we keep the lesser element.
//so we pop till the stack top is greater than current element
//as soon as the condition fails we stop and print that element
//
//For starting from 0 
//we slighly modify the logic
//basically we keep adding the elements in stack and as soon as we get a smaller element
//we keep popping from the stack till the current element is smaller and we say that the
//So in the stack we keep the lesser element.
//Nearest smaller to right is the current element
//To get answer in order we use index as well

#include <iostream>
#include <vector>
#include <stack>

//From last
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

//We Start from 0
void findNearestSmallerToRightFromStart(std::vector<int> in)
{
  std::vector<int> op(in.size(),-1);
  std::stack<std::pair<int,int>> s;//stack maintains index as well. first element index second is val

  for(int i = 0; i < in.size(); i++)
  {
      while(s.empty() == false && in[i] <= s.top().second)
      {
         op[s.top().first] = in[i];
         s.pop();
      }

      s.push({i,in[i]});

  }

  for(auto &e:op)
  {
    std::cout << e << " ";
  }
}

int main()
{
  findNearestSmallerToRight({4,5,2,10,8});
  std::cout << "\n";
  findNearestSmallerToRightFromStart({4,5,2,10,8});
  std::cout << "\n";
}
