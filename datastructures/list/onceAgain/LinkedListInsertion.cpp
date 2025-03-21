/**
 *
 * We will be doing linked list insertion in the begining, at the end and at a location
 * 
 * Case 1 - Inseration in the begning. We create a node and update the head
 * Case 2 - Inseration at the end. We traverse till end and attach the newly created node
 * Case 3 - Insertion at a position. eg 1->3->4->5 insert 2 at position 2 then we keep previous pointer
 * attach previous pointer->next to newly created node and newly created node ka next points to prev ka next
 *
 */
 #include <iostream>
 
 class LinkedList
 {
	 public:
	 int data;
	 LinkedList * next;
	 LinkedList(int elem,LinkedList * nextPtr = nullptr)
	 {
		 data = elem;
		 next = nextPtr;
	 }
 };
 
class LinkedListOp
{
	public:
	//case 1 insert at the begining
	//return updated head
	LinkedList * InsertAtBegining(LinkedList *Head,int elem)
	{
		LinkedList *NewItem = new LinkedList(elem);
		if(Head != nullptr)
		{
			NewItem->next = Head;
		}
		return NewItem;
	}
	
	//Case 2 insertion at the end
	//Returns pointer to head. head is updated only when linked list is empty
	LinkedList * InsertAtEnd(LinkedList *Head,int elem)
	{
		LinkedList *NewItem = new LinkedList(elem);
		
		if(Head == nullptr)
		{
			return NewItem;
		}
		else
		{
			LinkedList *HeadCopy = Head;
			//This reaches last node
			while(HeadCopy->next != nullptr)
			{
				HeadCopy = HeadCopy->next;
			}
			HeadCopy->next = NewItem;
			
		}
		return Head;
	}
	
	//Case 3 insertion at a particular location
	//Returns pointer to head. head is updated only when linked list is empty
	LinkedList * InsertAtPos(LinkedList *Head,int elem,int pos)
	{
		std::cout << "\n Inserting = " << elem << " at Pos = " << pos << "\n";
		//DOnt insert if starting and position is not -
		if(Head == nullptr && pos != 0)
		{
			return nullptr;
		}
		
		
		if(pos == 0)
		{
			return InsertAtBegining(Head,elem);
		}
		int count = 0;
		
			LinkedList *HeadCopy = Head;
			LinkedList * prev = nullptr;
			//This reaches last node
			while(HeadCopy != nullptr)
			{
				prev = HeadCopy;
				HeadCopy = HeadCopy->next;
				count++;
				if(count == pos)
				{
					LinkedList *NewItem =  new LinkedList(elem,prev->next);
					prev->next = NewItem;
					return Head;
					
				}
			}
			
			std::cout << "\n Can't Insert at the specified POsition \n";
			

		return Head;
	}

	void Display(LinkedList *Head)
	{
		std::cout << "\n Linked List Content = ";
		while(Head != nullptr)
		{
			std::cout << Head->data << "->";
			Head = Head->next;
		}
		std::cout << "nullptr \n";
	}
};

class LinkedListRecOp
{
	public:
	//case 1 insert at the begining
	//return updated head
	LinkedList * InsertAtBegining(LinkedList *Head,int elem)
	{
		LinkedList *NewItem = new LinkedList(elem);
		if(Head != nullptr)
		{
			NewItem->next = Head;
		}
		return NewItem;
	}
	
	//Case 2 insertion at the end
	//Returns pointer to head. head is updated only when linked list is empty


	//Hypothesis This Function Traverses and returns last
	LinkedList * TraverseTillEnd(LinkedList*Head)
	{
		//Base Conditions
		if(Head == nullptr)
		{
			return nullptr;
		}
		if(Head->next == nullptr)
		{
			return Head;
		}
		
		//Induction
		return TraverseTillEnd(Head->next);
	}
	
	LinkedList * InsertAtEnd(LinkedList *Head,int elem)
	{
		
		//Base Conditions
		if(Head == nullptr)
		{
			LinkedList *NewItem = new LinkedList(elem);
			return NewItem;
		}
		
		//Induction Step
		//Travel Till Last
		LinkedList *lastNode = TraverseTillEnd(Head);
		
		//Insert at end
		LinkedList *NewItem = new LinkedList(elem);
		if(lastNode != nullptr)
		{
			lastNode->next = NewItem;
		}

		return Head;
	}
	
	//Hypothesis This Function Traverses till specified position
	LinkedList * TraverseTillPos(LinkedList*Head,int &count,const int &pos)
	{
		//Base Conditions
		if(Head == nullptr)
		{
			return nullptr;
		}
		
		count++;

		if(count == pos)
		{
			return Head;
		}
			
		
		//Induction
		return TraverseTillPos(Head->next,count,pos);
	}
	
	//Case 3 insertion at a particular location
	//Returns pointer to head. head is updated only when linked list is empty
	LinkedList * InsertAtPos(LinkedList *Head,int elem,int pos)
	{
		std::cout << "\n Inserting = " << elem << " at Pos = " << pos << "\n";
		//DOnt insert if starting and position is not -
		if(Head == nullptr && pos != 0)
		{
			return nullptr;
		}
		
		
		if(pos == 0)
		{
			return InsertAtBegining(Head,elem);
		}
		
		//Induction Step
		//Travel Till Specified Position
		int count = 0;
		LinkedList *PrevNode = TraverseTillPos(Head,count,pos);
		
		//Insert at the Position
		LinkedList *NewItem = new LinkedList(elem);
		if(PrevNode != nullptr)
		{
			NewItem->next = PrevNode->next;
			PrevNode->next = NewItem;
		}
		else
		{				
			std::cout << "\n Can't Insert at the specified POsition \n";
		}


		return Head;
	}
	
	void DisplayRec(LinkedList *Head)
	{
		if(Head == nullptr)
		{
			return;
		}
		std::cout << Head->data << "->";
		DisplayRec(Head->next);
	}

	//Hypothesis. This Function Prints Element of linked list
	void Display(LinkedList *Head)
	{
		std::cout << "\n Linked List Content = ";
		DisplayRec(Head);
		std::cout << " nullptr \n";
	}
};




int main()
{
#if 0//Iterative
	LinkedListOp listOp;
	LinkedList *Head = nullptr;
	
	//Case 1 insertion at the begining
	std::cout << "\n ==================== CASE 1 Insert At Begining =========== \n";
	Head = listOp.InsertAtBegining(Head,5);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,4);
	listOp.Display(Head);
		
	Head = listOp.InsertAtBegining(Head,3);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,2);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,1);
	listOp.Display(Head);
	
	//Case 2 Insertion in the end it doesnt even matter ....
	std::cout << "\n ==================== CASE 2 Insert At End ================ \n";
	LinkedList *Head1 = nullptr;
	
	Head1 = listOp.InsertAtEnd(Head1,5);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,4);
	listOp.Display(Head1);
		
	Head1 = listOp.InsertAtEnd(Head1,3);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,2);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,1);
	listOp.Display(Head1);
	
	//Case 3 Insertion at a position
	std::cout << "\n ==================== CASE 3 Insert At Pos ================ \n";
	LinkedList *Head2 = nullptr;
	
	//Initially Empty
	Head2 = listOp.InsertAtPos(Head2,5,3);
	listOp.Display(Head2);
	
	//5
	Head2 = listOp.InsertAtPos(Head2,5,0);
	listOp.Display(Head2);
	
	//5->4
	Head2 = listOp.InsertAtPos(Head2,4,1);
	listOp.Display(Head2);
	
	//5->3->4
	Head2 = listOp.InsertAtPos(Head2,3,1);
	listOp.Display(Head2);
	
	//5->2->3->4
	Head2 = listOp.InsertAtPos(Head2,2,1);
	listOp.Display(Head2);
	
	//5->2->3->4
	//this wont insert
	Head2 = listOp.InsertAtPos(Head2,20,10);
	listOp.Display(Head2);
	
#else
	std::cout << "\n Recursive Solution \n";
	LinkedListRecOp listOp;
	LinkedList *Head = nullptr;
	
	//Case 1 insertion at the begining
	std::cout << "\n ==================== CASE 1 Insert At Begining =========== \n";
	Head = listOp.InsertAtBegining(Head,5);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,4);
	listOp.Display(Head);
		
	Head = listOp.InsertAtBegining(Head,3);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,2);
	listOp.Display(Head);
	
	Head = listOp.InsertAtBegining(Head,1);
	listOp.Display(Head);
	
	//Case 2 Insertion in the end it doesnt even matter ....
	std::cout << "\n ==================== CASE 2 Insert At End ================ \n";
	LinkedList *Head1 = nullptr;
	
	Head1 = listOp.InsertAtEnd(Head1,5);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,4);
	listOp.Display(Head1);
		
	Head1 = listOp.InsertAtEnd(Head1,3);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,2);
	listOp.Display(Head1);
	
	Head1 = listOp.InsertAtEnd(Head1,1);
	listOp.Display(Head1);
	
	//Case 3 Insertion at a position
	std::cout << "\n ==================== CASE 3 Insert At Pos ================ \n";
	LinkedList *Head2 = nullptr;
	
	//Initially Empty
	Head2 = listOp.InsertAtPos(Head2,5,3);
	listOp.Display(Head2);
	
	//5
	Head2 = listOp.InsertAtPos(Head2,5,0);
	listOp.Display(Head2);
	
	//5->4
	Head2 = listOp.InsertAtPos(Head2,4,1);
	listOp.Display(Head2);
	
	//5->3->4
	Head2 = listOp.InsertAtPos(Head2,3,1);
	listOp.Display(Head2);
	
	//5->2->3->4
	Head2 = listOp.InsertAtPos(Head2,2,1);
	listOp.Display(Head2);
	
	//5->2->3->4
	//this wont insert
	Head2 = listOp.InsertAtPos(Head2,20,10);
	listOp.Display(Head2);
#endif	
	
}


