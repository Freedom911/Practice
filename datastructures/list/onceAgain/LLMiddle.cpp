/**
 *
 * Finding Middle in linked list
 * Given a Linked List we have to return the middle Element
 * in odd 1->2->3 we return middle element 3/2 = 1st element that is 2
 * more eg 1->2->3->4->5 total 5/2 = 2nd element that is 3 = Floor(n/2)
 * for even linked list
 * 1->2->3->4 we return (n/2) = 2nd element that is 3
 * 
 * Solution 
 * 1. Two Pass Solution 
 * We count number of nodes in first pass
 * then in second pass we traverse till n/2
 *
 * 2. Single Pass Solution
 * We use concept of two pointers. One moves faster and other normally
 * Also known as Fast slow pointer approach
 * This approach is very good and is used in cycle detection
 * this is also called as Floyd Cycle Detection algo with slow and fast pointer
 * The Approach Works because fast pointer makes hops by 2. so it will read destination
 * twice as fast than normal one. So it reaches destination in n/2 time n is total nodes
 * so Slow pointer will be at n/2 node which is the middle one only.
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
 
 //We are using Tortoise and Hare.By Default it retrusn middle +1 
 //to get middle element we have to give fast ptr head start by 1
 //fast = head->next:
 LinkedList * returnMiddleElement(LinkedList *Head)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 LinkedList *Slow = Head;
	 LinkedList *Fast = Head;
	 
	 while(Fast != nullptr && Fast->next != nullptr)
	 {
		 Slow = Slow->next;
		 Fast = Fast->next;
		 Fast = Fast->next;
	 }
	 
	 return Slow;
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
	 node3->next = node4;
	 
	 std::cout << "\n Linked List Content = ";
	 Display(node1);
	 
	 LinkedList * middle = returnMiddleElement(node1);
	 
	 if(middle)
	 std::cout << "\n Middle Element = " << middle->data << "\n";
 }
