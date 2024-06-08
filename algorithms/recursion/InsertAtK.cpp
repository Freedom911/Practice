#include <iostream>
#include <stack>

void InsertAtPosition(std::stack<int> &s,const int &elem,int k)
{
  if(k == 0)
  {
    return;
  }
  
  if(k == 1)
  {
    s.push(elem);
	return;
  }
  
  int topElem = s.top();
  s.pop();
  InsertAtPosition(s,elem,k-1);
  s.push(topElem);
  
}

int main()
{
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(5);
  int k = 2;
  int elem = 4;
  //Insert elem at k
  InsertAtPosition(s,elem,k);
  
  while(s.empty() == false)
  {
	  std::cout << s.top() << ",";
	  s.pop();
  }
}