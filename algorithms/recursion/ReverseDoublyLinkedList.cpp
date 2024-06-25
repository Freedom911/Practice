#include <iostream>

struct Node
{
  int data = 0;
  Node*next{nullptr};
  Node*prev{nullptr};
  
  Node(int ldata)
  {
	  data = ldata;
	  next = nullptr;
	  prev = nullptr;
  }
};

Node* ReverseIterative(Node *Head)
{
	if(Head == nullptr)
	{
		return nullptr;
	}
	
	while(Head)
	{
		Node*Next = Head->next;
		Node*Prev = Head->prev;
		
		Head->next = Prev;
		Head->prev = Next;
		
		if(Next == nullptr)
		{
			return Head;
		}
		Head = Next;
	}
	
	return nullptr;
}


//Hypothesis
Node* RecurseReverse(Node *Head)
{
	//Base condition
	if(Head == nullptr)
	{
		return nullptr;
	}
	
	//Induction step
	Node* NextNode = Head->next;
	Head->next = Head->prev;
	Head->prev = NextNode;
	
	if(NextNode == nullptr)
		return Head;
		
	
	return RecurseReverse(NextNode);
}
void Display(Node * Head)
{
	std::cout << "nullptr->";
	while(Head != nullptr)
	{
		std::cout << Head->data << "->";
		Head = Head->next;
	}
	
	std::cout << "nullptr\n";
}

int main()
{
	Node *Head = new Node(10);
	Node *Node1 = new Node(20);
	Node *Node2 = new Node(30);
	Node *Node3 = new Node(40);
	Head->next = Node1;
	Node1->next = Node2;
	Node1->prev = Head;
	
	Node2->next = Node3;
	Node2->prev = Node1;
	
	Node3->prev = Node2;
	
	std::cout << "\n Content of Linked List\n";
	Display(Head);
	
	std::cout << "\n After Reverse \n";
	Display(RecurseReverse(Head));
}