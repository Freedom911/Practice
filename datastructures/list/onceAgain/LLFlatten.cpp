/**
  We are Given a linked list which has a next pointer and child pointer
  So the list is sorted in next manner and child manner
  
  eg 1-5-7
     | | |
	 8 6 9
  We need to generate a single Dimensional Linked list which is sorted
  
  So either 1-5-6-7-8-9
  or in vertical order
  
  We gonna use vertical order as it is easier to return in base condition

  Solution 1 -
  Store Everything in an set and create a new linked list with this
  Time Complexity O(NlogN) where N is the total no of elements
  Space = O(N)

  Solution 2-
  Using Concept of Merging K sorted list.
  We try to merge Head and Head->next till we reach the end
  Its Complexity is O((n1+n2 + n1+n2+n3 ...k)) 
  assuming all n1 to be n 
  we get n + 2n + 3n + ...kn
  n(1+2+3...k)
  O(n(k^2))
  Space Complexity = O(1)
  
  Solution 3
  Using Priority Queue Conept
  We again BOrrow concept from Merging K sorted list
  Time Complexity O(nklogk)
  Space Complexity O(k)
*/

#include <iostream>
#include <queue>

struct LL
{
	int data;
	LL*next;
	LL*child;
	
	LL(int val,LL*nextPtr = nullptr,LL*childPtr = nullptr):data(val),next(nextPtr),child(childPtr){}
};



//Solution 2 - Using for Loop one by one merging

//This Function is responible for merging 2 list in child manner
LL*Merge2Lists(LL*L1,LL*L2)
{
	if(L1 == nullptr && L2 == nullptr)
	{
		return nullptr;
	}
	if(L1 == nullptr)
	{
		return L2;
	}
	if(L2 == nullptr)
	{
		return L1;
	}
	LL *Dummy = new LL(-1);
	LL* Tail = Dummy;
	
	while(L1 && L2)
	{
		//L2 == nullptr means l2 is finished so just append L1
		if( L1->data < L2->data)
		{
			Tail->child = L1;
			L1 = L1->child;
		}
		else //if L1 == nullptr or L1 data is bigger then just append l2
		{
			Tail->child = L2;
			L2 = L2->child;
		}
		Tail = Tail->child;
	}
	
	if(L1)
	{
		Tail->child = L1;
	}
	
	if(L2)
	{
		Tail->child = L2;
	}
	
	
	
	LL*newHead = Dummy->child;
	delete Dummy;
	return newHead;
	
	
}

//This Function Returns a single linked in 1d with sorted elements
//There is a slight change in the algo
//basically we need to disconnect the next node to avoid cycle
//eg 1  - 7 -  11
//   10   12   16
//so if we didnt remove the next ptr then on sorting we will have 7->11 and 10->11
//In Short we remove the link first between 1-7 then we merge the first two list
//then we set the next of the merged list to 7->next in original
LL*Solution2(LL*Head)
{
	//Base condition
	if(Head == nullptr || Head->next == nullptr)
	{
		return Head;
	}
	
	while(Head && Head->next)
	{
		LL*HeadNext = Head->next;
		LL* Head2Next = HeadNext->next;
		
		//Remove the link between head and head->next
		Head->next = nullptr;
		
		//merge first 2 and update the Head
		Head = Merge2Lists(Head,HeadNext);
		
		Head->next = Head2Next;
		
	}
	
	return Head;
	
}

//This Function Returns a single linked in 1d with sorted elements
//This Function uses Priority Queue concept where it stores only next pointers
//and keep pushing one by one child 
LL*Solution3(LL*Head)
{
	//Base condition
	if(Head == nullptr || Head->next == nullptr)
	{
		return Head;
	}
	
	std::priority_queue<std::pair<int,LL*>,std::vector<std::pair<int,LL*>>,std::greater<std::pair<int,LL*>>>pq;
	
	while(Head)
	{
		pq.push({Head->data,Head});
		Head = Head->next;
	}
	
	LL*Dummy = new LL(-1);
	LL*Tail = Dummy;
	
	while(pq.empty() == false)
	{
		LL*Node = pq.top().second;
		pq.pop();
		Tail->child = Node;
		if(Node->child)
		{
			pq.push({Node->child->data,Node->child});
		}
		Tail = Tail->child;
		
	}
	
	LL*newHead = Dummy->child;
	delete Dummy;
	return newHead;
	
	
}


void Display(LL*Head)
{
	if(Head == nullptr)
	{
		return;
	}
	std::cout << "\n List Conent\n";
	while(Head)
	{
		std::cout << " " << Head->data;
		std::cout << "\n | \n";
		Head = Head->child;
	}
	std::cout << "nullptr\n";
	
}
#if 0
  eg 1-5-7
     | | |
	 8 6 9
	   8 10
#endif
int main()
{
	LL*node1 = new LL(1);
	LL*node2 = new LL(5);
	LL*node3 = new LL(7);
	node1->next = node2;
	node2->next = node3;
		LL*node4 = new LL(8);
	LL*node5 = new LL(6);
	LL*node6 = new LL(9);
	node1->child = node4;
	node2->child = node5;
	node3->child = node6;
		LL*node7 = new LL(8);
	LL*node8 = new LL(10);
	node5->child = node7;
	node6->child = node8;
	
	//std::cout << "\n Using Solution For Loop Merging \n";
	//LL*Merged = Solution2(node1);
	
		std::cout << "\n Using Solution Priority queue \n";
	LL*Merged = Solution3(node1);
	
	Display(node1);
	
}