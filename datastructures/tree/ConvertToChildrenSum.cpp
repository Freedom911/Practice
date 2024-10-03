/**
 *  Convert a binary tree to children SUm with dec any node
 *  Children Sum property tells that a parent node val = left + right val
 *  It is not simple in the sense ki it is direct since we have to ensure
 *  we dont have to deduct value. It mayh happen if we do greedy approach of just 
 *  changing node value then it might not get the ans
 *  eg  50
 *    7    2
 *  3   5 1  30
 * if we changed 7 to 8 and 2 to 31 then we had to reduce 50 which is not allowed
 * similarly 
 *       30
 *    7      2
 *   2 5   1   50
 *  we changed 2 from 1st level to 23 then we satisy 30 but for next level
 *  we have to decrease 50 which is not possible so the solution is explained below
 *  SOLUTION
 *  Here  we take the value from root and copy to childrens
 *  if only root val is greater than children. if not then we just copy sum(left,right)
 *  to root. Now we again traverse back to root from
 *  children and we add it to get root. We are not asked to get the min value that
 *  will get us to children sum. So we take the max value . Max value is max(root->data,left+right)
 *  we do cheating or rather smart work lol.
 *   
 *   eg         10
 *             4  3
 *           First Step since 10 > 4 + 3
 *           copy 10 to both
 *              10
 *            10  10
 *           now again traverse back to parent and add value 10 + 10
 *                20
 *              10  10  so this tree is the ans
 *      
 *          Other eg
 *                7
 *               6 3
 *    First step 7 < 6 + 3
 *    so we just update root to 6+3
 *               9
 *              6 3  which is the ans
 *
 *  we use recursive method 
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
 
 
 //Inorder Traversal
 //Inorder is left root right
 void PrintInorder(Tree*Root)
 {
	 if(Root == nullptr)
	 {
		 return;
	 }
	 
	 PrintInorder(Root->left);
	 std::cout << Root->data << ",";
	 PrintInorder(Root->right);
 }
 
 //Hypothesis - This Function converts the tree to children sum
 //by modifying the value 
 void ConvertToChildrenSum(Tree*Root)
 {
	 //Base condition
	 if(Root == nullptr)
	 {
		 return;
	 }
	 
	 //Induction Step
	 int childrenSum = Root->left ? Root->left->data : 0;
	 childrenSum += Root->right ? Root->right->data : 0;
	 
	 //now check if greater than parent
	 if(childrenSum > Root->data)
	 {
		 //Update Root val
		 Root->data = childrenSum;
	 }
	 else
	 {
		 //means Root val is greater than both children
		 if(Root->left)
		 {
			 Root->left->data = childrenSum;
		 }
		 
		 if(Root->right)
		 {
			 Root->right->data = childrenSum;
		 }
		 
	 }
	 
	 //now recursively do this
	 ConvertToChildrenSum(Root->left);
	 ConvertToChildrenSum(Root->right);
	 
	 //now again modify root
	 //this is after recursion because we need to go deep and explore children
	 //because it may happen the children value may be greater than parent
	 childrenSum = 0;
	 childrenSum = Root->left ? Root->left->data : 0;
	 childrenSum += Root->right ? Root->right->data : 0;
	 
	 //means it is not a leaf node
	 if(Root->left || Root->right)
	 {
		 Root->data = childrenSum;
	 }
 }
 
 int main()
 {
	   // Create the binary tree
    Tree* root = new Tree(3);
    root->left = new Tree(5);
    root->right = new Tree(1);
    root->left->left = new Tree(6);
    root->left->right = new Tree(2);
    root->right->left = new Tree(0);
    root->right->right = new Tree(8);
    root->left->right->left = new Tree(7);
    root->left->right->right = new Tree(4);
	
	std::cout << "\n Original Tree is =  ";
	PrintInorder(root);
	
	ConvertToChildrenSum(root);
	
	std::cout << "\n After converting Tree to children sum  =  ";
	PrintInorder(root);
	
 }