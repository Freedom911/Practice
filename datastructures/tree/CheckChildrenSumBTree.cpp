/**
 *  Checks if the Binary Tree Follow Children Sum
 *  Children sum property states that the parent  = children sum thats iter_swap
 *  So here we two methods first iterative using level order and second recursive
 */
 #include <iostream>
 #include <queue>
 
 struct Tree
 {
	int data;
	Tree *left;
	Tree *right;
	Tree(int val):data(val),left(nullptr),right(nullptr){}
 };
 
 bool CheckChildrenSumIterative(Tree *Root)
 {
	 if(Root == nullptr)
	 {
		 return true;
	 }
	 
	 std::queue<Tree*> q;
	 q.push(Root);
	 
	 while(q.empty() == false)
	 {
		 int size = q.size();
		 
		 for(int i = 0; i < size; i++)
		 {
			 //we simply check the sum of parent with children
			 int totalPSum = q.front()->data;
			 
			 Tree *Node =  q.front();
			 q.pop();
			 int totalCSum = 0;
			 if(Node->left)
			 {
				 totalCSum = Node->left->data;
				 q.push(Node->left);
			 }
			 
			 if(Node->right)
			 {
				 totalCSum += Node->right->data;
				 q.push(Node->right);
			 }
			 
			 //if it is not a leaf node then we match the sum
			 if((Node->right || Node->left) && (totalCSum != totalPSum)) 
				 return false;
		 }
	 }
	 
	 return true;
	 
 }
 
 //Hypothesis - This Function Checks Children SUm Property
 bool CheckChildrenSumRecursive(Tree *Root)
 {
	 //Base Conditions
	 //if node is null or if it is leaf node then in both case we return true
	 if(Root == nullptr || (Root->left == nullptr && Root->right == nullptr))
	 {
		 return true;
	 }
	 
	 //Induction Step
	 int totalPSum = Root->data;
	 int totalCSum = Root->left ? Root->left->data : 0; 
	 totalCSum += Root->right ? Root->right->data : 0;
	 
	 return (totalCSum == totalPSum && CheckChildrenSumRecursive(Root->left)&&
	 CheckChildrenSumRecursive(Root->right));
	 
	 
	 
	 
 }
 
 
 int main()
 {
	 // Create the binary tree
    Tree* root = new Tree(17);
    root->left = new Tree(8);
    root->right = new Tree(9);
    root->left->left = new Tree(6);
    root->left->right = new Tree(2);
    root->right->left = new Tree(1);
    root->right->right = new Tree(8);
	
	//Change any node val it will give children sum to be false

	
	
	std::cout << "\n is the tree following Children Sum Iter = " << CheckChildrenSumIterative(root) << "\n";
	std::cout << "\n is the tree following Children Sum Rec = " << CheckChildrenSumRecursive(root) << "\n";
	
 }