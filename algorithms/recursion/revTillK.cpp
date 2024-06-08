#include <iostream>
#include <stack>

void InsertAtPosition(std::stack<int> &s,const int &elem,int k);

//Hypothesis
void ReverseTillK(std::stack<int> &s,int k)
{
	//Base Condition
	if(k == 1 || s.size() == 0)
	{
		return;
	}
	
	int topElem = s.top();
	s.pop();
	ReverseTillK(s,k-1);
	InsertAtPosition(s,topElem,k);
	
}

//Hypothesis
void InsertAtPosition(std::stack<int> &s,const int &elem,int k)
{
	//Base COnditions
  if(k == 0)
  {
    return;
  }
  
  if(k == 1)
  {
    s.push(elem);
	return;
  }
  
  //Induction Step
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
  s.push(4);
  s.push(5);
  int k = 3;
  int elem = 4;
  //Reverse till k
  //ReverseTillK(s,k);
  
  while(s.empty() == false)
  {
	  std::cout << s.top() << ",";
	  s.pop();
  }
}