/**
 * https://takeuforward.org/linked-list/sort-a-linked-list
 *
 * Given A linked list we need to sort
 *
 * We shall use Merge Sort 
 *
 * Solution
 * Basically merge sort keeps diving the array into 2 parts
 * then when only one element is there it merges there
 * So We alread have the conceptof merging two list
 * We gonna extend that
 * We take the head pointer and divide the linked list fron middle
 * so 1st linked list is head to middle and other is middle->next to end
 * Then we merge
 */ 

#include <iostream>
#include <queue>

struct LL
{
	int data;
	LL*next;

	
	LL(int val)
    {
        data = val;
        next = nullptr;
    }
};


void Display(LL*Head)
{
	if(Head == nullptr)
	{
		return;
	}
	std::cout << "\n List Conent->";
	while(Head)
	{
		std::cout <<  Head->data << "->";

		Head = Head->next;
	}
	std::cout << "nullptr\n";
	
}


//This Function is responible for merging 2 list 
LL*Merge2Lists(LL*L1,LL*L2)
{
    //Base Conditions
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

    //Create A Dummy node
	LL *Dummy = new LL(-1);
	LL* Tail = Dummy;
	
	while(L1 && L2)
	{
		if( L1->data < L2->data)
		{
			Tail->next = L1;
			L1 = L1->next;
		}
		else 
		{
			Tail->next = L2;
			L2 = L2->next;
		}
		Tail = Tail->next;
	}
	
    //If Anything Left in L1
	if(L1)
	{
		Tail->next = L1;
	}
	//or L2
	else if(L2)
	{
		Tail->next = L2;
	}
	
	
	
	LL*newHead = Dummy->next;
	delete Dummy;
	return newHead;
	
	
}

//This Function Getts the middle Element
//Using Tortoise and Hare
//Here we want to return exact middle . In Tortoise and Hare we get middle + 1
//so we give headstart 1
LL* GetMiddle(LL*Head)
{
    //Base Condition. if no node or one node
	if(Head == nullptr || Head->next == nullptr)
	{
		return Head;
	}
	
	LL*fast = Head->next;
	LL*slow = Head;
	
    //move fast twicea
	while(fast != nullptr && fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//This Functions Does Merge sort and returns Sorted Linked list
LL* MergeSort(LL*Head)
{
    std::cout << "\n TIMEs " << std::endl;
    //Base Conditions
	if(Head == nullptr || Head->next==nullptr)
	{
		return Head;
	}
	
    //Get The Middle Element
	LL*Middle = GetMiddle(Head);
    if(Middle == nullptr)
    {
        return nullptr;
    }

	LL*r = Middle->next;//Right Side
	//Remove Link to treat as two individual link
	Middle->next = nullptr;
	LL*l = Head;//Left Side


    //Sort Left
	LL *l1 = MergeSort(l);
    //Sort Right
	LL *l2 = MergeSort(r);

    //Finally Merge
	return Merge2Lists(l1,l2);
}


#if 0
  eg 1-2-9-4-6

#endif
int main()
{
	LL*node1 = new LL(9);
	LL*node2 = new LL(2);
	LL*node3 = new LL(1);
	LL*node4 = new LL(4);
	LL*node5 = new LL(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
    node4->next = node5;

	Display(node1);
    std::cout << "\n MIDDLE = " << GetMiddle(node1)->data << "\n";
    return 0;

	
	
	std::cout << "\n BEfore \n";
	Display(node1);
	node1 = MergeSort(node1);
	std::cout << "\n After \n";
	Display(node1);
	
}
