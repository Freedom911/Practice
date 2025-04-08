/**
 *
 * Given a Linked list of 0s 1s and 2s. We need to sort them
 * Solution 1 
 * Count Number of Frequencies and overwrite the data
 * Time Complexity O(n) and Space Complexity O(1) but the solution is 2 pass
 *
 * Solution 2 
 * Updating Links
 * So taking inspiration from sorting 012 in array we 
 * Try to move 0 to left most.1 in middle and 2 at last
 * the Algo is simple
 * When we encounter 0 we pop the element and push in front of the list
 * if we encounter 1 we pop the element and attach to tail of 0s tail
 * for 2 we just ignore
 * We maintain Prev,ZeroTail,Curr and Head pointer
 * So current moves one by one
 * if 0 encounters it insert 0 to front. if zero tail was null then we update the zero tail to curr
 * now we dont update zero tail ever as it will be keep pointing to the tail
 * if 1 is encountered we pop and attach 1 to zero tail. if zero tail is null then we move 1 to front
 * For 0 we dont do any link update we  just update prev and curr.
 */
 
 #include <iostream>
 
 struct LinkedList
 {
	 int data;
	 LinkedList *next;
	 
	 LinkedList(int val)
	 {
		 data = val;
		 next = nullptr;
	 }
 };
 
 LinkedList* InsertAtBeg(LinkedList*Head,LinkedList*Curr)
 {
	 if(Head != nullptr)
	 {
		 Curr->next = Head;
	 }
	 
	 return Curr;
 }
 
 LinkedList* InsertAfterPos(LinkedList*Head,LinkedList*ZeroTail,LinkedList*Curr)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 if(ZeroTail == nullptr)
	 {
		 return InsertAtBeg(Head,Curr);
	 }
	 LinkedList*Next = ZeroTail->next;
	 ZeroTail->next = Curr;
	 Curr->next = Next;
	 return Head;
 }
 
 LinkedList * Sort(LinkedList *Head)
 {
	 if(Head == nullptr || Head->next == nullptr)
	 {
		 return Head;
	 }
	 
	 LinkedList* curr = Head;
	 LinkedList* ZeroTail = nullptr;
	 
	 if(curr->data == 0)
	 {
		 ZeroTail = curr;
	 }
	 LinkedList *prev = curr;
	 curr = curr->next;
	 
	 while(curr != nullptr)
	 {
		 LinkedList*next = curr->next;
		 if(curr->data == 0)
		 {
			 //1st Pop the element
			 prev->next = next;
			 Head = InsertAtBeg(Head,curr);
			 if(ZeroTail == nullptr)
			 {
				 ZeroTail = Head;
			 }
			 curr = next;
		 }
		 else if(curr->data == 1)
		 {
			 //Pop the element
			 prev->next = next;
			 //Insert curr to tail of 0 liked list
			 Head = InsertAfterPos(Head,ZeroTail,curr);
			 
			 //Update Curr POinter to the next element
			 //previous will be at same pos
			 curr = next;
		 }
		 else
		 {
			 //ignore 2 case
			 //just update prev and curr pointer
			 prev = curr;
			 curr  = next;
		 }
			 
	 }
	 
	 return Head;
 }
 
 void Display(LinkedList* Head)
 {
	 if(Head == nullptr)
	 {
		 std::cout << " Nullptr \n";
		 return;
	 }
	 
	 std::cout << Head->data << "->";
	 Display(Head->next);
 }
 
 int main()
 {
	 LinkedList *node1 = new LinkedList(2);
	 LinkedList *node2 = new LinkedList(1);
	 LinkedList *node3 = new LinkedList(2);
	 LinkedList *node4 = new LinkedList(0);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 
	 std::cout << "\n Linked List Content = ";
	 Display(node1);
	 
	 LinkedList * Sorted = Sort(node1);
	 
	std::cout << "\n After Sorting = \n";
	Display(Sorted);
 }
