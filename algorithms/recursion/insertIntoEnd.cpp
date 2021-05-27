//Insert an element into stack end

#include <iostream>
#include <stack>

//Hypothesis
void InsertAtEnd(std::stack<int> &s,int elementToInsert)
{
  if(s.size() == 0)
  {
    s.push(elementToInsert);
    return;
  }

  //Induction 
  int element = s.top();
  s.pop();
  InsertAtEnd(s,elementToInsert);
  s.push(element);
}

int main()
{
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  InsertAtEnd(s,0);

  while(s.empty() == false)
  {
    std::cout << s.top() << " ";
    s.pop();
  }
}

