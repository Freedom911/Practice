/**
 *
 * Given a linked list with Random and next pointer. we need to clone iter_swap
 * like create a deep copy
 * 
 * Solution
 * I can think of two solution 
 * Solution 1 - Using Map
 * So basically if we were given a simple linked list we would have created clone in  a single traversal
 * We need to remember the random node as well
 * ALgo
 * 1. Create a map with [Original Node,Copy Node] and insert it while traverseing 1st time
 * 2. Now to connect random ptr we pick entry from map one by one
 * 3. We check random ptr for original one. from this we can find in the map that copy node should point to 
 *    value present in map[randomPtrOfOriginal Node]
 * Time Complexity O(n)
 * Space Complexity O(n)
 *
 *
 * Solution 2 
 * so basically we need to remember the position of random ptr. we do this by fixing a new linked list
 * at a known position. I mean that if i have 1-2-3-4 original list then we insert a copy node between each
 * 1-1-2-2-3-3-4-4. So starting from 0 elements at even position are original and and odd position are copy
 * in this way if 1st random is 3 then 1 copy random will be present just next to original 1ns random next
 * Thats the crux
 * Algo
 * 1. Start Traversing and create copy nodes in between
 * 2. Connection of random ptrs. we first try to connect random as breaking/removing next ptr is easy
 *    so copy 1 random will original 1 random next
 * 3. For next ptr we say curr starting from head we remove curr->next and point to curr->next->next->next
 * we do this till end and we increment curr by 2 in btoh cases
 */
 
 #include <iostream>
 
 struct LL
 {
	 int data;
	 LL*next;
	 LL*randPtr;
	 
	 LL(int val,LL* nextPtr = nullptr,LL* randPtrCopy = nullptr):data(val),next(nextPtr),randPtr(randPtrCopy){}
 };
 
 //This function is responible for Deep cloning a linked list and returns a head 
 //of the cloned list
 //There are three steps
 //1. Creation of Node
 //2. Connection of Random Ptrs
 //3. Connection of Next ptr and removal from original list
 LL* DeepCopyClone(LL*Head)
 {
	 //Base condition
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 //1. Step one creation
	 LL*Orig = Head;
	 LL*newHead = nullptr;
	 while(Orig)
	 {
		 LL* node = new LL(Orig->data);
		 
		 //Point new head
		 if(newHead == nullptr)
		 {
			 newHead = node;
		 }
		 
		 LL*next = Orig->next;
		 Orig->next = node;
		 node->next = next;
		 
		 Orig = Orig->next->next;
	 }
	 
	 
	 
	 //2. Step two Random ptr connection
	 Orig = Head;
	 
	 while(Orig && Orig->next)
	 {
		 LL*copyNode = Orig->next;
		 LL* origRandom = Orig->randPtr;
		 
		 //Random ptr will be just after original one
		 if(origRandom)
		 {
			 copyNode->randPtr = origRandom->next;
		 }
		 
		 Orig = Orig->next->next;
	 }
	 
	 //3. Step 3 Connect Next ptr
	  Orig = Head;
	  //1-1-2-2-3-3
	  //If both present
	  while(Orig && Orig->next)
	  {
		 //Dry to run undersatnad
          
		  //Get COpy Node which is next
		  LL*Copy = Orig->next;
		  
		  //Rejoin Link  of Orig List
		  LL*OrigNext = Orig->next->next;  
		  Orig->next = OrigNext;
		  
		  //Make COpy NOde point to the next or OrigNext
		  //Handing if nullptr
		  if(OrigNext)
			Copy->next = OrigNext->next;
		  
		  //Continue Forward
		  Orig = Orig->next;
	  }
	  
	  return newHead;
 }
 
 void Display(LL*Head)
 {
	 if(Head == nullptr)
	 {
		 return;
	 }
	 
	 while(Head)
	 {
		 std::cout << "->" << Head->data;//comment data to know all address different : )

		 if(Head->randPtr)
			std::cout << " random = " << Head->randPtr->data << " ";
		else
			std::cout << " random = nullptr ";
		 Head = Head->next;
	 }
 }
 
 //1-2-3-4
 //random 1-4,2-nullptr,3-1,4-2
 
 int main()
 {
	 LL *node1 = new LL(1);
	 LL *node2 = new LL(2);
	 LL *node3 = new LL(3);
	 LL *node4 = new LL(4);
	 
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 
	 node1->randPtr = node4;
	 node3->randPtr = node1;
	 node4->randPtr = node2;
	 
	 Display(node1);
	 
	 std::cout << "\n After CLoning \n";
	 LL*copy = DeepCopyClone(node1);
	 
	 Display(copy);
 }
 
 
 