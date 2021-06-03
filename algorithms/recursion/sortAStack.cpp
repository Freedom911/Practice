//Given an stack sort the Stack using recursion

#include <iostream>
#include <stack>

void insertInStack(std::stack<int> &ar,int element);
//Hypothesis
void sort(std::stack<int> &ar)
{
  //Base Condition For Stack of size 1 it is already sorted
  if(ar.size() <= 1)
    return;

  //Induction 
  //Given an element insert that element into the sorted Stack
  int element = ar.top();
  ar.pop();

  //Sort the remaining Stack
  sort(ar);

  //Insert the element at the given Stack
  insertInStack(ar,element);

}

void insertInStack(std::stack<int> &ar,int element)
{
  //Base Condition
  //Just push back at last
  if(ar.size() == 0 || ar.top() <= element)
  {
    ar.push(element);
    return;
  }

  //Induction
  //Reduce the size of Stack
  int val = ar.top();
  ar.pop();
  //For the reduce sorted Stack insert the element at the right place
  insertInStack(ar,element);
  ar.push(val);
}

int main()
{
  std::stack<int> s;
  s.push(0);
  s.push(1);
  s.push(2);
  s.push(90);
  s.push(3);
  s.push(4);
  sort(s);
  while(s.empty() == false)
  {
    std::cout << s.top() << " ";
    s.pop();
  }
}
