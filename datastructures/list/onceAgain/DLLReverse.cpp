/**
 * 
 * Reverse Doubly Linked lIst\
 * Logic is same as that of single liinked list reversal
 * we swap curr next and curr prev and move to next thats it
 * 
 */

 #include <iostream>
 
 struct LinkedList
 {
	int data;
	LinkedList *next;
	LinkedList *prev;
	LinkedList(int val)
	{
		data = val;
		next = nullptr;
		prev = nullptr;
	}
 };
 
 //Returns Head of reversed Linked list

  
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
 //Returns Head of reversed Linked list
 LinkedList * ReverseIter(LinkedList *Head)
 {
	 if (Head == nullptr || Head->next == nullptr)
	 {
		 return Head;
	 }
	 
	 
	 LinkedList *prev = Head->prev;
	 while(Head != nullptr)
	 {
		 
		 prev = Head->prev;
		 LinkedList * next = Head->next;
		 
		 Head->next = prev;
		 Head->prev = next;
		 
		 prev = Head;
		 Head = next;
		 
		 
	 }
	 
	 
	 return prev;
	 
 }

//Hypothesis This function reverse the linked list and return the head of reversed linked list
LinkedList * ReverseRec(LinkedList *Head,LinkedList *prev)
 {
	 if (Head == nullptr)
	 {
		 return prev;
	 }
	 
	 
	LinkedList * next = Head->next;
		 
	std::swap(Head->next,Head->prev);
	return ReverseRec(next,Head);
 }
	 


 
 int main()
 {
	 LinkedList *node1 = new LinkedList(1);
	 LinkedList *node2 = new LinkedList(2);
	 LinkedList *node3 = new LinkedList(3);
	 LinkedList *node4 = new LinkedList(4);
	 
	 node1->next = node2;
	 
	 node2->next = node3;
	 node2->prev = node1;
	 
	 node3->next = node4;
	 node3->prev = node2;
	 
	 node4->prev =node3;
	 std::cout << "\n List Content =";
	 Display(node1);
	 
	 std::cout << "\n List Content After Iterative Reverse =";
	 
	 node1 = ReverseIter(node1);
	 Display(node1);
	 
	 std::cout << "\n List Content After Rec Reverse =";
	 
	 node1 = ReverseRec(node1,nullptr);
	 Display(node1);
	 
 }