#include <iostream>
#include <queue>
#include <vector>

void InsertAtFront(std::queue<int> &q,const int &elem)
{
	std::vector<int> v;
	while(q.empty() == false)
	{
		v.push_back(q.front());
		q.pop();
	}
	
	q.push(elem);
	for(auto &e : v)
	{
		q.push(e);
	}
}

//Hypothesis
void InsertAtRightPlace(std::queue<int> &q,const int &elem)
{
	//Base conditions
	if(q.size() == 0)
	{
		q.push(elem);
		return;
	}
	
	if(q.front() > elem)
	{
		InsertAtFront(q,elem);
		return;
	}
	
	//Induction
	int topElement = q.front();
	q.pop();
	InsertAtRightPlace(q,elem);
	InsertAtFront(q,topElement);
}

int main()
{
	std::queue<int>q;
	q.push(1);
	q.push(5);
	q.push(9);
	q.push(11);
	
	InsertAtRightPlace(q,0);
	
	while(q.empty() == false)
	{
		std::cout << q.front() << ",";
		q.pop();
	}
}