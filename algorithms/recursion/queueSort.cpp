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

//Hypothesis
void SortQueue(std::queue<int> &q)
{
	//Base conditions
	if(q.size() <= 1)
	{
		return;//sorting not required with 1 or less elements
	}
	
	//Induction
	int elem = q.front();
    q.pop();
	SortQueue(q);//sorts queue of size n-1 then we take the front element and push to right place
	InsertAtRightPlace(q,elem);
}

int main()
{
	std::queue<int>q;
	q.push(15);
	q.push(5);
	q.push(91);
	q.push(10);
	
	SortQueue(q);
	
	while(q.empty() == false)
	{
		std::cout << q.front() << ",";
		q.pop();
	}
}