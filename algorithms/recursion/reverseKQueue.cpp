//Reversing Queue Using Recursion
#include <iostream>
#include <queue>

void reverse(std::queue<int> &q,int k)
{
  if(q.size() == 1)
    return;

  if(k < 1)
    return;

  int element = q.front();
  q.pop();
  k--;
  reverse(q,k);
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

  int k = 3;
  reverse(q,k);

  for(int i = 0 ; i < q.size() -k; i++)
  {
    int element = q.front();
    q.pop();
    q.push(element);
  }

  std::cout << "\n AFTER \n";

  while(q.empty() == false)
  {
    std::cout << q.front() << "\n";
    q.pop();
  }
}
