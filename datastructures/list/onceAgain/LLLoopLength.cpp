/**
  Given a linked list with loop find loop length
 */
 #include <iostream>
 #include <unordered_set>
 
 
 struct LL
 {
	 int data;
	 LL *next;
	 
	 LL(int val):data(val),next(nullptr){}
 };
 
 
 int LoopLength(LL *Head)
 {
	 if(Head == nullptr)
	 {
		 return -1;
	 }
	 
	 LL *slow = Head;
	 LL *fast = Head;
	 
	 int cnt = 0;
	 while(fast && fast->next)
	 {
		 
		 fast = fast->next->next;
		 slow = slow->next;

         if(fast == slow)
         {
             slow = slow->next;
             cnt++;
             while(slow != fast)
             {
                 slow = slow->next;
                 cnt++;
             }
             return cnt;

         }
		 
	 }
     return 0;
	 
 }


 
 int main()
 {
	 //List 1
	 LL* node1 = new LL(1);
	 LL* node2 = new LL(2);
	 LL* node3 = new LL(3);
	 LL* node4 = new LL(4);
	 LL* node5 = new LL(5);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 node4->next = node3;
	 //node4->next = node5;
	 //node5->next = node3;
	 
	 std::cout << "\n Loop Length = " << LoopLength(node1);
	 
	 


 }
 
 
 
 
