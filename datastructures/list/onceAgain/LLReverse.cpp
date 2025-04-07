/**
 * Reverse Singly Linked List with and without recursion
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
 
 //Returns Head of reversed Linked list
 LinkedList * ReverseIter(LinkedList *Head)
 {
	 if (Head == nullptr || Head->next == nullptr)
	 {
		 return Head;
	 }
	 
	 LinkedList *prev = nullptr;
	 LinkedList * next = nullptr;
	 
	 while(Head != nullptr)
	 {
		 next = Head->next;
		 
		 Head->next = prev;
		 prev = Head;
		 Head = next;
		 
	 }
	 
	 return prev;
	 
 }
 
 LinkedList * ReverseRec(LinkedList *Head,LinkedList * prev)
 {
	 //Base condition. that is we hit the last node. so prev is having the head of reversed ll
	 if(Head == nullptr)
	 {
		 return prev;
	 }
	 
	 LinkedList *next = Head->next;
	 Head->next = prev;
	 return ReverseRec(next,Head);
	 
 }
 
 void Display(LinkedList *Head)
 {
	 if(Head == nullptr)
	 {
		 std::cout << "nullptr\n";
		 return;
	 }
	 std::cout << Head->data << ",";
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
	 node3->next = node4;
	 std::cout << "\n List Content =";
	 Display(node1);
	 
	 std::cout << "\n List Content After Iterative Reverse =";
	 
	 node1 = ReverseIter(node1);
	 Display(node1);
	 
	 std::cout << "\n List Content After Recursive Reverse =";
	 
	 node1 = ReverseRec(node1,nullptr);
	 Display(node1);
	 
 }
	 
	 