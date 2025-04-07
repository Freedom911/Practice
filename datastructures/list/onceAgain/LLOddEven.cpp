/**
 *
 * Given a Linked list we need to sort odd and even index
 * eg 1->2->3->4->5->6
 * so we do 1->3->5->4->6
 * so basically if we start indexing from 1 we merge odd index first and then connect with even index
 * Solution 1 - Using Extra Space
 * we store the result in an array which stores 1,3,5 first and then even index. then we write back to list
 * Time and SPace  Complexity is O(n) 
 * Solution 2 - Modifying Links
 * Basically we modify the link only. we keep two pointers odd and even
 * we set odd->next = odd->next->next
 * same for even->next = even->next->next
 * so basically we are connecting odd's next to odd's next next i.e 1 is connected to 3
 * and at last we connect odd->next = evenHead; and return the head
 * for Checking Condition we can either check both the even or odd pointers
 * but we know even will always be in front so we can just check even pointer
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
 
 LinkedList * OddEven(LinkedList *Head)
 {
	 if(Head == nullptr || Head->next == nullptr)
	 {
		 return Head;
	 }
	 LinkedList * HeadCopy = Head;
	 LinkedList * Odd = Head;
	 LinkedList * Even = Head->next;
	 LinkedList * EvenHead = Even;
	 
	 //we Need to Check Even pointer only as it will be always be ahead of odd
	 //also check even->next as we use even->next->next
	 //works for both odd and even length index
	 while(Even != nullptr && Even->next != nullptr)
	 {
		 Odd->next = Odd->next->next;
		 Even->next = Even->next->next;
		 
		 Odd = Odd->next;
		 Even = Even->next;
	 }
	 Odd->next = EvenHead;
	 return HeadCopy;
	 
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
	 LinkedList *node1 = new LinkedList(1);
	 LinkedList *node2 = new LinkedList(2);
	 LinkedList *node3 = new LinkedList(3);
	 LinkedList *node4 = new LinkedList(4);
	 node1->next = node2;
	 node2->next = node3;
	 //node3->next = node4;
	 
	 std::cout << "\n Linked List Content = ";
	 Display(node1);
	 
	 LinkedList * OddEvenHead = OddEven(node1);
	 
	std::cout << "\n Odd Even Head = \n";
	Display(OddEvenHead);
 }