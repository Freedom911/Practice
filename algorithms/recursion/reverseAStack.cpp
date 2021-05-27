//Program To reverse a stack using recursion
#include <iostream>
#include <stack>



void insertAtTheEnd(std::stack<int> &st,int elementToInsert);

//Hypothesis - This functin will reverse a stack of size N and will also 
//Reverse a stack of size n - 1
void reverseStack(std::stack<int> &st)
{
  //Base Condition
  //If there is one element only no need to reverse
  if(st.size() == 1)
    return;


  //Induction. Take an element on stack top and insert at the end
  int elem = st.top();
  st.pop();
  reverseStack(st);
  insertAtTheEnd(st,elem);

}

//Hypothesis - Takes an element and add to last of stack. This function will work for size N of stack
//and will also for stack of size N-1
void insertAtTheEnd(std::stack<int> &st,int elementToInsert)
{
  //Base Condition - If we have reached bottom then insert the eleent and return
  if(st.size() == 0)
  {
    st.push(elementToInsert);
    return;
  }

  //Induction - Take the top element pop it insert the element toInsert and then push the element
  int top = st.top();
  st.pop();
  insertAtTheEnd(st,elementToInsert);

  st.push(top);
} 


int main()
{
  std::stack<int> s;
  s.push(0);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  std::stack<int> s1(s);

  std::cout << "\n INTIALLY = ";
  while(s1.empty() == false)
  {
    std::cout << s1.top() << " ";
    s1.pop();
  }

  reverseStack(s);
  std::cout << "\n REVERSING = ";
  while(s.empty() == false)
  {
    std::cout << s.top() << " ";
    s.pop();
  }

}
