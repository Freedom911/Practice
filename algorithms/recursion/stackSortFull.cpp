//Given an stack sort the Stack using recursion

#include <iostream>
#include <stack>

void insertInStack(std::stack<int> &ar,int element);
void insertInStackAsc(std::stack<int> &ar,int element);
//Hypothesis
void sort(std::stack<int> &ar, int asc)
{
  //Base Condition For Stack of size 1 it is already sorted
  if(ar.size() <= 1)
    return;

  //Induction 
  //Given an element insert that element into the sorted Stack
  int element = ar.top();
  ar.pop();

  //Sort the remaining Stack
  sort(ar,asc);

  //Insert the element at the given Stack
  if(asc == 0)
  {
	  insertInStack(ar,element);
  }
  else
  {
	  insertInStackAsc(ar,element);
  }

}

void insertInStackAsc(std::stack<int> &ar,int element)
{
	//Base COndition
	if(ar.size() == 0 || ar.top() > element)
	{
		ar.push(element);
		return;
	}
	
	  //Induction
  //Reduce the size of Stack
  int val = ar.top();
  ar.pop();
  //For the reduce sorted Stack insert the element at the right place
  insertInStackAsc(ar,element);
  ar.push(val);
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
  sort(s,0);
  while(s.empty() == false)
  {
    std::cout << s.top() << " ";
    s.pop();
  }
	
  std::cout << "\n IN ASC \n";
  std::stack<int> s1;
  s1.push(0);
  s1.push(1);
  s1.push(2);
  s1.push(90);
  s1.push(3);
  s1.push(4);
  sort(s1,1);
  while(s1.empty() == false)
  {
    std::cout << s1.top() << " ";
    s1.pop();
  }
}