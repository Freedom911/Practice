/**
 *
 * Delete Nth Node From last
 */
 
 #include <iostream>
 
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
 
 LL *DeleteNthNaive(LL *Head,int N)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 int M = 0;
	 LL *curr = Head;
	 while(curr != nullptr)
	 {
		 curr = curr->next;
		 M++;
	 }
	 std::cout << "\n Deleting N = " << N << "th Node from Linked List of Size = " << M << "\n";
	 
	 if(N > M)
	 {
		 std::cout << "\n Not POssible \n";
		 return Head;
	 }
	 else if( M == N)
	 {
		 LL * tmp = Head->next;
		 delete Head;
		 return tmp; 
	 }
	 
	 int res = M - N;
	 
	 int cnt = 0;
	 LL *prev = nullptr;
	 curr = Head;
	 while(cnt < res)
	 {
		 prev = curr;
		 curr = curr->next;
		 cnt++;
	 }
	 std::cout << "\n";
	 prev->next = curr->next;
	 delete curr;
	 return Head;
 }
 
 LL *DeleteNthOptimized(LL *Head,int N)
 {
	 std::cout << "\n Deleting N = " << N << "th Node from Linked List \n";
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 //Using Concept of Fast and slow
	 LL *fast = Head;
	 LL *slow = Head;
	 
	 ///Giving Head start of N
	 int i = 0;
	 for(i = 0; i < N && fast != nullptr; i++)
	 {
		 fast = fast->next;
	 }
	 
	 //Edge Cases To Handle
	 //if the item to be deleted is at front
	 //or if Nth is greater than the length of LL
	 if(fast == nullptr && i == N)
	 {
		 LL * tmp = Head;
		 Head = Head->next;
		 delete tmp;
		 return Head;
	 }
	 
	 //Edge Cases if i > total Linked LIst
	 else if(fast == nullptr && i < N) // Means Nth is equal to linked list length so we delete Head
	 {
		 std::cout << "\n Deletion Not Possible \n";
		 return Head;
	 }

	 
	 //Since we gave Fast pinter a head start of N. we just need to cover M - N distance
	 //so when we cover M - N distance by slow pointer we will be at the position for which we have
	 //to delete 
	 LL * prev = nullptr;
	 while(fast != nullptr)
	 {
		 prev = slow;
		 slow = slow->next;
		 fast = fast->next;
	 }
	 
	 prev->next = slow->next;
	 delete slow;
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
	 LL * node1 = new LL(1);
	 LL * node2 = new LL(2);
	 LL * node3 = new LL(3);
	 LL * node4 = new LL(4);
	 LL * node5 = new LL(5);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 node4->next = node5;
	 Display(node1);
	 node1 = DeleteNthOptimized(node1,2);
	 Display(node1);
 }