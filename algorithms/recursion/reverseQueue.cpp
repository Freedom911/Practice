//Reversing Queue Using Recursion
#include <iostream>
#include <queue>

void reverse(std::queue<int> &q)
{
  if(q.size() == 1)
    return;

  int element = q.front();
  q.pop();
  reverse(q);
  q.push(element);
}

int main()
{
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  std::cout << "\n BEFORE \n";
  while(q.empty() == false)
  {
    std::cout << q.front() << "\n";
    q.pop();
  }
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  reverse(q);
  std::cout << "\n AFTER \n";

  while(q.empty() == false)
  {
    std::cout << q.front() << "\n";
    q.pop();
  }
}
