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
 
 LinkedList* RemoveNthBruteForce(LinkedList*Head,int N)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 //1st Count Total Number of elements
	 int M = 0;
	 LinkedList*Curr = Head;
	 while(Curr != nullptr)
	 {
		 M++;
		 Curr = Curr->next;
	 }
	 
	 if(M - N == 0)
	 {
		 //First Element
		 LinkedList*HeadCopy = Head;
		 Head = Head->next;
		 delete HeadCopy;
		 return Head;
	 }
	 else if(M - N < 0) //Not Possible means item to delete is not in range
	 {
		 return Head;
	 }
	 else
	 {
		 int count = 0;
		 Curr = Head;
		 LinkedList*prev = nullptr;
		 while(count < M-N && Curr != nullptr)
		 {
			 prev = Curr;
			 Curr = Curr->next;
			 count++;
		 }
		 if(Curr != nullptr)
		 {
			prev->next = Curr->next;
			delete Curr;
		 }
	 }
	 return Head;
 }
 
  LinkedList* RemoveNthOptimized(LinkedList*Head,int N)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	
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
	 LinkedList *node1 = new LinkedList(0);
	 LinkedList *node2 = new LinkedList(1);
	 LinkedList *node3 = new LinkedList(2);
	 LinkedList *node4 = new LinkedList(3);
	 LinkedList *node5 = new LinkedList(4);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 node4->next = node5;
	 
	 std::cout << "\n Linked List Content = ";
	 Display(node1);
	 
	 LinkedList * Sorted = RemoveNthBruteForce(node1,0);
	 
	std::cout << "\n After Deleting 3rd from LL =  \n";
	Display(Sorted);
 }
 
 
