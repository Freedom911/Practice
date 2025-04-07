/**
  Given Two linked list return the intersection point.
  1-2-3-4-5
  0-5-1-2-3-4-5
  intersection point 1-2-3-4-5. Remember when two list intersects not only their value is same but 
  their addres as well
  
  I wioll be giving three soliutino
  Solutino 1 - Simple Comparision
  Solution 2 - Hash
  Solution 3 - Optimized head start implementation
  
 */
 #include <iostream>
 #include <unordered_set>
 
 
 struct LL
 {
	 int data;
	 LL *next;
	 
	 LL(int val):data(val),next(nullptr){}
 };
 
 //in this approach we take every element of l2 and compare with l1. as soon as 
 //we get even a single node matching fully. including address
 //total timeo complexito T(M*N) wehere m is length of l2 and n length of l1
 //Space Complexity O(1)
 LL *SimpleComparisionSol1(LL *l1,LL *l2)
 {
	 if(l1 == nullptr || l2 == nullptr)
	 {
		 return nullptr;
	 }
	 
	 while(l2 != nullptr)
	 {
		 LL* l1Copy = l1;
		 while(l1Copy != nullptr)
		 {
			 if(l1Copy == l2)
			 {
				 return l1Copy;
			 }
			 l1Copy = l1Copy->next;
		 }
		 l2 = l2->next;
	 }
	 
	 return nullptr;
 }
 
 //Solutino 2 - We simply hash all the elements of l1 by isnerting inunordered set
 //then we simply find the eement of l2 in unordered set in O(1)
 //total timeo complexito T(M) wehere m is length of l2
 //Space Complexity O(N)
 LL *Hashing(LL *l1,LL *l2)
 {
	 if(l1 == nullptr || l2 == nullptr)
	 {
		 return nullptr;
	 }
	 std::unordered_set<LL*>us;
	 while(l1 != nullptr)
	 {
		 us.insert(l1);
		 l1 = l1->next;
	 }
	 
	 while(l2 != nullptr)
	 {
		if(us.find(l2) != us.end())
		{
			return l2;
		}
		 l2 = l2->next;
	 }
	 
	 return nullptr;
 }
 
 //Solution 3 
 //Basically we use the concept of same length
 //So imagine a world of same length linked list
 //so for these linked list we could simply run single loop
 //while incrementing both list. if same node found we return
 //So to achieve this. we try to increment the diff of length in the longer linked list
 //and we start comparisino from there in a single loop
 //total timeo complexito T(M+N) wehere m is length of l2,n is length of l1
 //Space Complexity O(1)
 
 int LengthDiff(LL *l1,LL*l2)
 {
	 
	 int n = 0;
	 int m = 0;
	 
	 while(l1 != nullptr || l2 != nullptr)
	 {
		 if(l1)
		 {
			 n++;
			 l1 = l1->next;
		 }
		 if(l2)
		 {
			 m++;
			 l2 = l2->next;
		 }
	 }
	 
	 return n - m;
 }
 
 LL *SameLength(LL *l1,LL *l2)
 {
	 if(l1 == nullptr || l2 == nullptr)
	 {
		 return nullptr;
	 }
	  
	  int diff = LengthDiff(l1,l2);
	  
	  if(diff > 0) //means l1 is longer so we head start l1 with diff
	  {
		  int cnt = 0;
		  while(cnt < diff && l1)
		  {
			  l1 = l1->next;
			  cnt++;
		  }
	  }
	  else if(diff < 0) // means l2 is longer .l2 requires head start
	  {
		  int cnt = 0;
		  int absDiff = -diff;
		  while(cnt < absDiff)
		  {
			  l2 = l2->next;
			  cnt++;
		  }
	  }
	  
	  //Now do comparisino in single loop
	  while(l1 != nullptr && l2 != nullptr)
	  {
		  if(l1 == l2)
		  {
			  return l2;
		  }
		  l1 = l1->next;
		  l2 = l2->next;
	  }
	  return nullptr;
 }
 
 void Display(LL *Head)
 {
	if(Head == nullptr)
	{
		std::cout << "nullptr\n";
		return;
	}
	std::cout << Head->data << "->";
	Display(Head->next);
	
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
	 node4->next = node5;
	 
	 
	 //List 2
	 LL* node11 = new LL(0);
	 LL* node22 = new LL(20);
	 LL* node33 = new LL(30);
	 LL* node44 = new LL(4);
	 node11->next = node22;
	 node22->next = node33;
	 node33->next = node4;
	 node33->next = node44;
	 
	 
	 std::cout << "\n InterSectino of l1 = " ;
	 Display(node1);
	 std::cout << "\n with l2 = " ;
	 Display(node11);
	 std::cout << "\n Is = ";
	 //LL *intersectionPoint = SimpleComparisionSol1(node1,node11);
	 //LL *intersectionPoint = Hashing(node1,node11);
	 LL *intersectionPoint = SameLength(node1,node11);
	 
	 if(intersectionPoint == nullptr)
	 {
		 std::cout << "\n NULL \n";
	 }
	 Display(intersectionPoint);


 }
 
 
 
 