/**
 *
 * Given A linked list. tell if it palindrme
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
 //Total Time Complexity O(N + N/2)
 //Space Complexity O(N)
 bool IsPalindromNaive(LL *Head)
 {
	 //Base Conditions
	 if(Head == nullptr || Head->next == nullptr)
	 {
		 return true;
	 }
	 
     std::vector<int> arr;
	 LL *curr = Head;
	 while(curr != nullptr)
	 {
		 arr.push_back(curr->data);
		 curr = curr->next;
	 }
	
	int i = 0;
	int j = arr.size() - 1;
	
	while(i != j && i < arr.size() && j > 0)
	{
		if(arr[i] != arr[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
 }
 
 
 //in the optimized version we dont use extra space
 //we take inspiration from array. in array we compare first and last and so on till middle
 //so here also we try to do the same. since it is singley linekd list
 //we need a mechanism to traverse in backwards direction. we use reverse from middle till end
 //we use previous knowlege of findign middle using fastr and slow ptr and reverse
 
 LL * findMiddle(LL *Head)
 {
	 if(Head == nullptr)
	 {
		 return nullptr;
	 }
	 
	 LL * slow = Head;
	 LL * fast = Head;
	 
	 //1-2-3-2-1
	 //for odd
	 //initially slow and fast = 1
	 //1st iter = slow = 2,fast = 3
	 //2nd iter = slow = 3,fast = 5
	 //break  return slow
	 //for even 1-2-3-1
	 //1st iter -> slow = 1,fast = 1
	 //2nd ->slow = 2,fast = 3
	 //3rd iter slow = 3,fast = nullptr
	 //break but we want to return 2
	 //so check till fast->next->next
	 while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
	 {
		 fast = fast->next;
		 fast = fast->next;
		 slow = slow->next;	 
	 }
	 return slow;
 }
 
 
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
 
 bool IsPalindromOptimized(LL *Head)
 {
	 //Base Conditions
	 if(Head == nullptr || Head->next == nullptr)
	 {
		 return true;
	 }
	 
	 LL *middle = findMiddle(Head);
	 
	 if(middle ==  nullptr)
	 {
		 return false;
	 }
	 
	 //reverse Middle + 1 link
	 LL *RevHead = Reverse(middle->next);
	 LL *currHead = Head;
	 
	 while(RevHead !=nullptr)
	 {
		 if(currHead->data != RevHead->data)
		 {
			 return false;
		 }
		 currHead = currHead->next;
		 RevHead = RevHead->next;
	 }
	 return true;
	 
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
	 LL * node3 = new LL(2);
	 LL * node4 = new LL(1);
	 LL * node5 = new LL(1);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 node4->next = node5;
	 Display(node1);
	 std::cout << "\n Naive Is the given String Palindrome = ? " << IsPalindromNaive(node1);
	 std::cout << "\n Optimized Is the given String Palindrome = ? " << IsPalindromOptimized(node1);
	 
 }