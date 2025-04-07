/**
 * Given A linked list
 * 1->2->3->4->5->6
 * Rotate it rightwards by K
 * Eg K = 2
 * So move everyone right
 * 5-6,1,2,3,4
 *
 * Algo
 * So Basically
 * 1. Find Total Elements
 * 2. Get Tail of the total elements
 * 3. Get n-k th element. 
 * 4. Save n-k+1 element. This will be the new head
 * 5. Set n-k next to null
 * 6. Connect Tail with Head
 */

#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int val):data(val),next(nullptr){}
};

//Returns Total Element while returning the last node
Node *GetTotalElements(Node*Head,int &count)
{
    count = 0;
    if(Head == nullptr)
    {
        return Head;
    }

    Node *prev = nullptr;
    while(Head)
    {
        prev = Head;
        Head = Head->next;
        count++;
    }

    return prev;
}

Node *GetKthElement(Node*Head,int k)
{
    if(k <= 0 || Head == nullptr)
    {
        return Head;
    }
    for(int i = 0; i < k; i++)
    {
        if(Head == nullptr)
        {
            return nullptr;
        }
        Head = Head->next;
    }
    return Head;
}

Node *RotateByK(Node*Head,int k)
{
    // 1. Find Total Elements
    // 2. Get Tail of the total elements
    // 3. Get n-k th element. 
    // 4. Save n-k+1 element. This will be the new head
    // 5. Set n-k next to null
    // 6. Connect Tail with Head
    //7. set new head
    if(Head == nullptr || k == 0)
    {
        return Head;
    }
    int totalCount = 0;
    //1 and 2
    Node *Curr = Head;
    Node *Tail = GetTotalElements(Curr,totalCount);

    k = k % totalCount;

    
    //3 Getting n - k
    //1-2-3-4-5 with k = 2
    Node *kth = GetKthElement(Curr,totalCount - k - 1);
    //4
    Node *kthNext = kth->next;
    //5 
    kth->next = nullptr;

    //6
    Tail->next = Head;

    //7set new head
    return kthNext;

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
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	int k = 2;
	Display(node1);
	std::cout << "\n Rotating = " << k << " times\n";
	Node* rev = RotateByK(node1,k);
	
	if(rev)
	{
		Display(rev);
	}
	else
	{
		std::cout << "\n Cant Reverse \n";
	}
}
