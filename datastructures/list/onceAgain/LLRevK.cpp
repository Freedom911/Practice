/**
 *
 * Given a linked list. we need to reverse in k groups
 *
 *  1-2-3-4-5-6-7
 * k = 3
 * ans = 3-2-1-6-5-4-7
 * So Basically we reverse linked list for a block of size k. if size less than k we ignore
 *
 * Solution -
 * We use the previous knowledge of reversing a linked lsit
 * but we restrict the number.
 * after that we just connect the remaining pointer
 * Algo
 * 1. Find kth Node
 * 2. if null then return the newHead
 * 3. Break the kthNode and kthNode->next_permutation
 * 4. reverse the curr node till kth
 * 5  after reversal.connect the last node of the previous group with the revered head
 * 6. Connect the last node of the current group to the next_permutation
 * 7. Repeat till all nodes.
 */

#include <iostream>

struct Node
{
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = nullptr;
	}
};

//This Function returns the kth node . if not found or
// total elements are less then return nullptr
Node *GetKthNode(Node*Head,int k)
{
	
	Node* Curr = Head;
	for(int i = 0; i < k; i++)
	{
		if(Curr == nullptr)
		{
			return nullptr;
		}
		Curr = Curr->next;
	}
	return Curr;
}

Node *Rev(Node*Head)
{
	if(Head == nullptr)
	{
		return Head;
	}
	
	Node*Prev = nullptr;
	Node*Curr = Head;
	while(Curr)
	{
		Node*Next = Curr->next;
		Curr->next = Prev;
		Prev = Curr;
		Curr = Next;
	}
	return Prev;
}

Node *ReverseK(Node*Head,int K)
{
	if(Head == nullptr || K <= 0)
	{
		return Head;
	}
	
	Node*PrevTail = nullptr;
	Node*NewHead = nullptr;
	Node*Curr = Head;
	
	while(Curr)
	{
		//1.First we need to get Kth node
		//2. then break the linked
		//3.reverse the group
		//4.connect pointers
		//5 Move forward
		
		//1
		Node*Kth = GetKthNode(Curr,K-1);
		
		if(Kth == nullptr)
		{
			break;
		}
		
		//2.
		Node*Next = Kth->next;
		
		Kth->next = nullptr;
		
		//3.Reverse the group only
		Node*RevHead = Rev(Curr);
		
		//4.
		//means this is the first time so we assign head
		if(PrevTail == nullptr)
		{
			NewHead = RevHead;
		}
		else
		{
			PrevTail->next = RevHead;
		}
		
		//Connecting Next pointer
		Curr->next = Next;
		
		//5.
		PrevTail = Curr;
		Curr = Next;
	}
	
	return NewHead;
}

void Display(Node*Head)
{
	if(Head == nullptr)
	{
		return;
	}
	std::cout << "\n List Content = ";
	while(Head)
	{
		std::cout << Head->data << "-->";
		Head = Head->next;
	}
	std::cout << "nullptr\n";
}

int main()
{
	Node * node1 = new Node(1);
	Node * node2 = new Node(2);
	Node * node3 = new Node(3);
	Node * node4 = new Node(4);
	Node * node5 = new Node(5);
	Node * node6 = new Node(6);
	Node * node7 = new Node(7);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	
	int k = 3;
	Display(node1);
	std::cout << "\n Reversing in group size = " << k << "\n";
	Node* rev = ReverseK(node1,k);
	
	if(rev)
	{
		Display(rev);
	}
	else
	{
		std::cout << "\n Cant Reverse \n";
	}
}
