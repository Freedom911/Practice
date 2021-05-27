//Delete Middle Element From Stack using Recursion
#include <iostream>
#include <stack>


//HYPOTHESIS this function deletes the kth element of stakc of size N
//This will also delete k - 1 element of stack of size n-1
void deleteElem(std::stack<int> &s,int k)
{
  //Base Condition
  if(k <= 1)
  {
    s.pop();
    return;
  }

  //INDUCTION
  int topElement = s.top();
  s.pop();
  deleteElem(s,k-1);
  s.push(topElement);
}


void deleteMiddle(std::stack<int> &s)
{
  if(s.size() == 0)
    return;

   int k = (s.size()/2) + 1;

   deleteElem(s,k);

}

int main()
{
  std::stack<int> s;
  s.push(0);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  deleteMiddle(s);
  while(s.empty() == false)
  {
   std::cout << s.top() << "\n";
   s.pop();
  }
}
