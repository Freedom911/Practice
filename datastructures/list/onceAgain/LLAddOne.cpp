/**
 *
 * Given A linked list. Addone to it
 * eg 1->2->3->4
 * adding 1
 *  1->2->3->5
 * 9->9 adding one
 * 1->0->0
 * We will present two nodes'
 * Soltiion 1
 * we reverse whioe linked list add one. if carry still one append to first. now reverse whoel ll
 * Solution 2 
 * Using recursion. we dig deep down.when we reach last node we add one and while backtracking keep updating
 * nodes
 * 
 */
 
 #include <iostream>
 #include <vector>
 
 struct LL
 {
	 int data;
	 LL * next;
	 LL(int val)
	 {
		 data = val;
		 next = nullptr;
	 }
 };
 
 
 LL * Reverse(LL *Head)
 {
	 //NO need to reverse 
	 if(Head == nullptr || Head->next == nullptr)
	 {
		 return Head;
	 }
	 LL * prev = nullptr;
	 
	 LL *curr = Head,*next = nullptr;
	 while(curr != nullptr)
	 {
		 next = curr->next;
		 curr->next = prev;
		 
		 prev = curr;
		 curr = next;
	 }
	 return prev;
 }
 
 //we dont need to check for all. as soon as we get carry = 0. we dont need to proceed durther
 //wejust reverse it back eg 1-2-3-4 after rev 4-3-2-1 then we add 1 to 4 we get 5 but we dont need to proceed
 //we just rev back
 LL *AddOneReversion(LL*Head)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 Head = Reverse(Head);
	 int carry = 1;
	 LL* curr = Head;
	 LL *prev = nullptr;
	 while(curr != nullptr && carry != 0)
	 {
		 int val = carry + curr->data;
		 
		 int sum = val %10;
		 carry = val / 10;
		 curr->data = sum;
		 std::cout << curr->data << "\n";
		 prev = curr;
		 curr = curr->next;
	 }
	 if(carry == 1) // means we need to add new node to end in the reversed list
	 {
		 LL * tmp = new LL(carry);
		 prev->next = tmp;
	 }
	 
	 return Reverse(Head);

 }
 
 //Hypothesis - This functions returns carry after adding value to node
 int RecursionHelper(LL*Head)
 {
	 //Base condition
	 if(Head == nullptr)
	 {
		 //means we reached last node so we return carry 1. as add from right/last node
		 return 1;
	 }
	 
	 //Induction
	 int carry = RecursionHelper(Head->next);
	 int val = carry + Head->data;
	 Head->data = val % 10;
	 return val /10;
 }
 
  //Here we use recursion to add Number
 LL *AddOneRecursion(LL*Head)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 int lastCarry = RecursionHelper(Head);
	 
	 
	 if(lastCarry == 1) // means we need to add new node to begin
	 {
		 LL * tmp = new LL(lastCarry);
		 tmp->next = Head;
		 Head = tmp;
	 }
	 
	 return Head;

 }
 
 void Display(LL *Head)
 {
	 if(Head == nullptr)
	 {
		 return;
	 }
	 std::cout << "Linked LIst Content = ";
	 while(Head != nullptr)
	 {
		 std::cout << Head->data << "->";
		 Head = Head->next;
	 }
	 std::cout << "nullptr\n";
 }
 
 int main()
 {
	 LL * node1 = new LL(9);
	 LL * node2 = new LL(9);
	 LL * node3 = new LL(9);
	 LL * node4 = new LL(9);
	 LL * node5 = new LL(8);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 node4->next = node5;
	 Display(node1);
	 
	 node1 = AddOneReversion(node1);
	 
	 std::cout << "\n After Adding 1 = ";
	 Display(node1);
	
	 
 }