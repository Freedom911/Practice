#include <iostream>
#include <vector>
#include <stack>

//We will be using two stack s and s1. s is  normal stack and s1 stack stores minimum element only

class Stack
{
public:

	int Pop()
	{
		if (s.size() == 0)
		{
			return -1;
		}

		int ans = s.top();
		s.pop();
		if (ans == s1.top())
		{
			s1.pop();
		}
		return ans;
	}

	void Push(const int& elem)
	{
		s.push(elem);

		if (s1.size() == 0 || s1.top() > elem)
		{
			s1.push(elem);
		}
	
	}

	int GetMinElement()
	{
		if (s1.size() == 0)
		{
			return -1;
		}

		return s1.top();
	}
private:

	std::stack<int> s;
	//Supporting stack that stores mini mum element
	std::stack<int> s1;
};

int main()
{
	Stack s;
	s.Push(18);
	s.Push(19);
	s.Push(29);
	s.Push(15);
	s.Push(16);

	std::cout << "\n Miniumum Element after inserting all " << s.GetMinElement() << "\n";
	int elem = s.Pop();
	std::cout << "\n Miniumum Element after Popping = " << elem << " is " << s.GetMinElement() << "\n";

	elem = s.Pop();
	std::cout << "\n Miniumum Element after Popping = " << elem << " is " << s.GetMinElement() << "\n";

	elem = s.Pop();
	std::cout << "\n Miniumum Element after Popping = " << elem << " is " << s.GetMinElement() << "\n";

	elem = s.Pop();
	std::cout << "\n Miniumum Element after Popping = " << elem << " is " << s.GetMinElement() << "\n";

	elem = s.Pop();
	std::cout << "\n Miniumum Element after Popping = " << elem << " is " << s.GetMinElement() << "\n";

}