//Program For thread Tree
//A threaded tree is a tree in which any of the null pointer of the leaf 
//node points to successor or predecessor. This helps in traversing the tree
//in inorder manner without stack and recursion
//Here we use a flag to denote whether it is the leaf node is pointing to predecessor 
#include <iostream>
#include <stack>
struct BinaryTree
{
  int data;
  BinaryTree*leftChild;
  BinaryTree*rightChild;
  bool isThreaded;

  BinaryTree(int data)
  {
    this->data = data;
    leftChild = NULL;
    rightChild = NULL;
	isThreaded = false;
  }
};

//Gets Left Most Child
BinaryTree * LeftMostNode(BinaryTree *Root)
{
  if(Root == nullptr)
  {
	  return Root;
  }
  
  while(Root->leftChild != nullptr)
	  Root = Root->leftChild;
  
  return Root;
}

void InOrderTraversal(BinaryTree* Root)
{
	if(Root == nullptr)
	{
		return;
	}
	
	BinaryTree*Curr = LeftMostNode(Root);
	
	while(Curr != nullptr)
	{
		//we are doing inorder traversal left root right
		//so initially we are ekdum leftmost so
		//we print the data 
		std::cout << Curr->data << ",";
		
		if(Curr->isThreaded)//means the right points to the parent
		{
			//go to parent.as we go to parent in the loop we print data
			//as we have already printed left now we print root 
			Curr = Curr->rightChild;
		}
		else
		{
			//now we need to explore right subtree.
			//as the left subtree we have already explored with the help of LeftMostNode
			//so now again we have a tree and we do same thing we go left most 
			//for the right child
			Curr = LeftMostNode(Curr->rightChild);
			
		}
	}
}

//Create tree as following
//      10
//    /   \
//   11   12
//  /     / \
//	13	  15 16
//Inorder 13 11 10 15 12 16
//11 right point to 10 as 10 is successor of  11
//13 right points to 11 as 11 is successor of 13 in order and 15 right points to 12 as 15 successor is 12 in inorder
//Node if there has been a right child of 11 then 11 wont be threaded as 14 will pointing to 10 which is the successor of that node 


int main()
{
  BinaryTree *rootNode = new BinaryTree(10);
  BinaryTree *node1 = new BinaryTree(11);
  BinaryTree *node2 = new BinaryTree(12);
  BinaryTree *node3 = new BinaryTree(13);
  BinaryTree *node4 = new BinaryTree(15);
  BinaryTree *node5 = new BinaryTree(16);
  
  rootNode->leftChild = node1;
  rootNode->rightChild = node2;

  node1->leftChild = node3;
  node1->isThreaded = true;
  node1->rightChild = rootNode;//threaded
  
  node3->rightChild = node1;//threaded
  node3->isThreaded = true;
  
  node2->leftChild = node4;
  node2->rightChild = node5;
  
  node4->rightChild = node2;
  node4->isThreaded = true; // threaded
  std::cout << "\n Inorder Threaded TRAVERSAL \n";
  InOrderTraversal(rootNode);//Expected Ouput 13 11 10 15 12 16
  

}