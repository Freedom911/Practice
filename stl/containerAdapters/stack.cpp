//STACK - LIFO
//UNDERLYING CONTAINER - VECTOR,LIST,DEQUE
//Only Requires Sequential container

#include <iostream>
#include <stack>

int main()
{
  std::stack<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);
  pq.push(5);

  while(!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
 } 
